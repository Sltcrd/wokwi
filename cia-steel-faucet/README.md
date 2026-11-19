# Cia Steel Faucet — Moen, Inc.

Entrega de las Preguntas 1 y 2 del examen de IoT. **Nuevo prototipo ESP32, diferente del sensor vehicular anterior.**

## Simulación personal en Wokwi
**Pendiente de guardar este proyecto nuevo en la cuenta de Sltcrd.** El enlace anterior de https://wokwi.com/projects/481154773977140225 corresponde al proyecto vehicular, NO al grifo.

## Hardware y cableado
- ESP32 DevKit C V4.
- HC-SR04: TRIG 5, ECHO 17, alimentación 5V y GND.
- LED azul: GPIO 18, con resistencia de 220 ohmios hacia GND.
- Relé: entrada GPIO 23, alimentación 5V y GND.

## Cómo probar
1. Abre https://wokwi.com/projects/new/esp32 en tu sesión de Wokwi.
2. Incorpora `diagram.json`, `sketch.ino` y los cinco archivos `.h` de esta carpeta.
3. Abre el monitor serie a 115200 baudios. Cambia el marcador `YOUR NAME AND SURNAME` en `StatusReporter.h`.
4. Ajusta el HC-SR04 a 8 cm. El LED azul debe encenderse y el relé activarse 5 segundos.
5. Mantén 8 cm: el LED permanece encendido, pero la válvula se cierra a los 5 s.
6. Ajusta a 20 cm y vuelve a 8 cm para reactivar la válvula.
7. Comprueba el reporte serial cada 2.5 segundos y el estado WiFi.

## Límites
Los archivos no se han ejecutado en una sesión real de Wokwi. El sistema no mide caudal ni presión, solo los representa como especificación. Existe un método de configuración de umbral para futura integración, pero **no** una aplicación móvil funcional ni una API HTTP.

En hardware real, convierte el ECHO de 5 V del HC-SR04 a 3.3 V para proteger el ESP32.

Ver [Pregunta 1](PREGUNTA_1.md).
