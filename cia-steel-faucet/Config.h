/** @file Config.h
 * @brief Cia Steel Faucet configuration constants.
 * @author IoT Development Team
 */
#ifndef CIA_STEEL_CONFIG_H
#define CIA_STEEL_CONFIG_H
#include <Arduino.h>
namespace FaucetConfig {
constexpr uint8_t TRIGGER_PIN=5, ECHO_PIN=17, BLUE_LED_PIN=18, RELAY_PIN=23;
constexpr float PROXIMITY_THRESHOLD_CM=10.0f;
constexpr unsigned long VALVE_OPEN_MS=5000UL, REPORT_INTERVAL_MS=2500UL;
constexpr unsigned long SENSOR_INTERVAL_MS=100UL, WIFI_RETRY_MS=10000UL, ECHO_TIMEOUT_US=30000UL;
constexpr char WIFI_SSID[]="Wokwi-GUEST", WIFI_PASSWORD[]="";
}
#endif
