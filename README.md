# Helios_esp_lamp
Este es un proyecto básico que permite comunicar dispositivos a través de comunicación mqtt, en este caso una lámpara con un celular o computador. El servidor que permite gestionar las comunicaciones es CloudMQTT aun así cualquier servidor debería servir. La placa es un versión aunque funcional se debe mejorar un poco el hardware. Se recomienda NO instalar la resistencia R2 ni el LED verde debido a un problema de encendido que presenta este dispositivo al iniciar.

Para realizar la placa PCB en donde se colocó el Esp8266 se necesita los siguietes dispositivos:

- 2 resistencia 430 Ω 1/2 Watt
- 1 resistencia 180 Ω 1 Watt 
- 1 resistencia 530 Ω 1 Watt 
- 1 condesador de 100 nF 
- 1 condesador de 10 uF
- Regulador de 3.3 V LD117AV
- Esp82666
- Moc3021M
- Triac BTA16-600BRG
- lED 5 mm Verde

A continuacion se muestra algunas imagenes del esquematico, el PCB y unos links donde se escuentra el video en el que fue basado este proyecto.

## Esquematico
![Alt text](docs/esquematico.png)

## PCB
![Alt text](docs/placa.png)

## Links
 - El código base para el proyecto [Tutorial #11 ESP8266 (Parte1) - MQTT + CloudMQTT](https://www.youtube.com/watch?v=MD2pw21HAA8&t=848s)
 - Links para descargar el esquematico y la PCB  [Wifi_lamp](https://easyeda.com/Santiago77/wifi_lamp)



