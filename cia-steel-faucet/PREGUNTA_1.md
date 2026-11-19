# Pregunta 1 — Application Service Layer Requirements
## Caso Moen, Inc. — Cia Steel Faucet

La capa de servicios de aplicación coordina los casos de uso del grifo inteligente y comunica el IoT Device con la aplicación Moen Smart Water.

| Servicio | Requisitos | Interfaz de usuario |
| --- | --- | --- |
| Device Discovery & Pairing | Descubrir grifos en la red WiFi, vincular dispositivo a usuario y mostrar errores. | Vista móvil con búsqueda, lista de dispositivos y asistente de emparejamiento. |
| Device Status Monitoring | Consultar distancia en cm, detección de manos, válvula OPEN/CLOSED, conexión WiFi y última actualización. | Dashboard móvil con indicadores y lectura periódica. |
| Proximity Configuration | Consultar y cambiar remotamente el umbral de detección (valor inicial 10 cm) con validación y confirmación. | Configuración móvil con slider/campo y botón Guardar. |
| Valve Status | Mostrar apertura automática durante 5 segundos ante una nueva aproximación. | Indicador móvil OPEN/CLOSED y duración de apertura. |
| Connectivity Management | Informar conexión WiFi y fallas de red; reintentar cuando proceda. | Indicador de conectividad y mensajes de error. |

## Reglas del sistema
- Distancia menor que 10 cm significa que se detecta la mano.
- El LED azul enciende durante la detección y apaga cuando la mano se aleja.
- Un evento de entrada activa el relé por 5 segundos; debe haber salida de la zona antes del siguiente ciclo.
- Cada 2.5 segundos se informan por consola distancia y estado de la válvula.
- El dispositivo incorpora conectividad WiFi para futura integración con la app.
- Caudal de referencia de la especificación: 1.2 gpm (4.5 L/min) a 60 psi; el simulador no representa hidráulica.

## Contratos lógicos propuestos
- `discoverDevices()`: devuelve dispositivos de la red o error.
- `pairDevice(deviceId)`: devuelve el resultado del vínculo.
- `getDeviceStatus(deviceId)`: distancia, manos detectadas, válvula, WiFi y fecha de actualización.
- `getProximityThreshold(deviceId)`: umbral configurado.
- `updateProximityThreshold(deviceId, valueCm)`: confirma o rechaza un valor fuera de rango.

**Alcance:** Estos contratos son el diseño de servicios de la Pregunta 1, no una API web implementada. La Pregunta 2 implementa el comportamiento embebido en ESP32 y su conexión WiFi.
