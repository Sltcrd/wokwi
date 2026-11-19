/** @file ValveActuator.h
 * @brief Five-second nonblocking relay valve.
 * @author IoT Development Team
 */
#ifndef CIA_STEEL_VALVE_ACTUATOR_H
#define CIA_STEEL_VALVE_ACTUATOR_H
#include <Arduino.h>
#include "Config.h"
class ValveActuator {
 public:
  explicit ValveActuator(uint8_t relayPin):relayPin_(relayPin){}
  void begin(){pinMode(relayPin_,OUTPUT);close();}
  void open(unsigned long now){openedAt_=now;open_=true;digitalWrite(relayPin_,HIGH);}
  void update(unsigned long now){if(open_ && now-openedAt_>=FaucetConfig::VALVE_OPEN_MS)close();}
  void close(){open_=false;digitalWrite(relayPin_,LOW);}
  bool isOpen()const{return open_;}
 private:
  uint8_t relayPin_; unsigned long openedAt_=0; bool open_=false;
};
#endif
