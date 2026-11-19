/** @file ProximitySensor.h
 * @brief Object-oriented HC-SR04 sensor reader.
 * @author IoT Development Team
 */
#ifndef CIA_STEEL_PROXIMITY_SENSOR_H
#define CIA_STEEL_PROXIMITY_SENSOR_H
#include <Arduino.h>
#include "Config.h"
class ProximitySensor {
 public:
  ProximitySensor(uint8_t triggerPin,uint8_t echoPin):triggerPin_(triggerPin),echoPin_(echoPin){}
  void begin(){pinMode(triggerPin_,OUTPUT);pinMode(echoPin_,INPUT);digitalWrite(triggerPin_,LOW);}
  /** @return Distance in centimeters or -1 if no echo was received. */
  float readDistanceCm() const {
    digitalWrite(triggerPin_,LOW); delayMicroseconds(2);
    digitalWrite(triggerPin_,HIGH); delayMicroseconds(10);
    digitalWrite(triggerPin_,LOW);
    unsigned long pulseDuration=pulseIn(echoPin_,HIGH,FaucetConfig::ECHO_TIMEOUT_US);
    return pulseDuration==0?-1.0f:pulseDuration*0.0343f/2.0f;
  }
 private:
  uint8_t triggerPin_,echoPin_;
};
#endif
