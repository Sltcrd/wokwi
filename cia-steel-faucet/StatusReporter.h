/** @file StatusReporter.h
 * @brief Serial device information and status reports.
 * @author IoT Development Team
 */
#ifndef CIA_STEEL_STATUS_REPORTER_H
#define CIA_STEEL_STATUS_REPORTER_H
#include <Arduino.h>
class StatusReporter {
 public:
  static void printStartup(){
    Serial.println("==================================");
    Serial.println("Moen, Inc. | Cia Steel Faucet");
    Serial.println("Developer team: YOUR NAME AND SURNAME");
    Serial.println("Product: MotionSense Wave smart faucet");
    Serial.println("==================================");
  }
  static void printStatus(float distanceCm,bool valveOpen,bool detected,bool wifiConnected){
    Serial.print("Distance: ");
    if(distanceCm<0)Serial.print("No echo");else Serial.print(distanceCm,1);
    Serial.print(" cm | Hands: ");Serial.print(detected?"DETECTED":"ABSENT");
    Serial.print(" | Valve: ");Serial.print(valveOpen?"OPEN":"CLOSED");
    Serial.print(" | WiFi: ");Serial.println(wifiConnected?"CONNECTED":"DISCONNECTED");
  }
};
#endif
