/** @file Device.h
 * @brief Coordinates proximity detection, five-second valve control, LED and WiFi.
 * @author IoT Development Team
 */
#ifndef CIA_STEEL_DEVICE_H
#define CIA_STEEL_DEVICE_H
#include <Arduino.h>
#include <WiFi.h>
#include "Config.h"
#include "ProximitySensor.h"
#include "ValveActuator.h"
#include "StatusReporter.h"
class Device {
 public:
  Device():sensor_(FaucetConfig::TRIGGER_PIN,FaucetConfig::ECHO_PIN),valve_(FaucetConfig::RELAY_PIN){}
  void begin(){
    Serial.begin(115200);StatusReporter::printStartup();
    sensor_.begin();valve_.begin();
    pinMode(FaucetConfig::BLUE_LED_PIN,OUTPUT);
    digitalWrite(FaucetConfig::BLUE_LED_PIN,LOW);
    WiFi.mode(WIFI_STA);WiFi.begin(FaucetConfig::WIFI_SSID,FaucetConfig::WIFI_PASSWORD,6);
    Serial.println("Connecting to WiFi: Wokwi-GUEST");
    unsigned long now=millis();
    lastSensorRead_=now-FaucetConfig::SENSOR_INTERVAL_MS;
    lastReport_=now-FaucetConfig::REPORT_INTERVAL_MS;
    lastWifiAttempt_=now;
  }
  void update(){
    unsigned long now=millis();
    valve_.update(now);
    if(now-lastSensorRead_>=FaucetConfig::SENSOR_INTERVAL_MS){
      lastSensorRead_=now;distanceCm_=sensor_.readDistanceCm();
      bool detected=distanceCm_>0 && distanceCm_<thresholdCm_;
      digitalWrite(FaucetConfig::BLUE_LED_PIN,detected?HIGH:LOW);
      // One five-second opening per new proximity event.
      if(detected && !previouslyDetected_){
        valve_.open(millis());
        Serial.println("EVENT: Hand detected - valve open for 5 seconds");
      }
      previouslyDetected_=detected;
    }
    valve_.update(millis());
    if(now-lastReport_>=FaucetConfig::REPORT_INTERVAL_MS){
      lastReport_=now;
      StatusReporter::printStatus(distanceCm_,valve_.isOpen(),previouslyDetected_,WiFi.status()==WL_CONNECTED);
    }
    if(WiFi.status()!=WL_CONNECTED && now-lastWifiAttempt_>=FaucetConfig::WIFI_RETRY_MS){
      lastWifiAttempt_=now;WiFi.reconnect();
    }
  }
  // Extension hook for a future mobile application, not exposed via HTTP yet.
  bool setThresholdCm(float value){
    if(value<2.0f||value>100.0f)return false;
    thresholdCm_=value;return true;
  }
 private:
  ProximitySensor sensor_; ValveActuator valve_;
  float distanceCm_=-1.0f, thresholdCm_=FaucetConfig::PROXIMITY_THRESHOLD_CM;
  bool previouslyDetected_=false;
  unsigned long lastSensorRead_=0,lastReport_=0,lastWifiAttempt_=0;
};
#endif
