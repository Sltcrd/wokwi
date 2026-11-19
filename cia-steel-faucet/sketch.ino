/** @file sketch.ino
 * @brief Wokwi entry point for Moen Cia Steel Faucet.
 * @author IoT Development Team
 */
#include "Device.h"
Device device;
void setup(){device.begin();}
void loop(){device.update();}
