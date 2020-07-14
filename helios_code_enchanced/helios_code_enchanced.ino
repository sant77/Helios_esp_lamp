/*
https://pubsubclient.knolleary.net/api.html#setserver  Mirar funciones

Santiago Duque Ramos
*/
//Librerias 
/*
https://pubsubclient.knolleary.net/api.html#setserver  Mirar funciones

Santiago Duque Ramos
*/
//Librerias 

#include <ESP8266WiFi.h>          //https://github.com/esp8266/Arduino

//needed for library
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include "WiFiManager.h"          //https://github.com/tzapu/WiFiManager
#include <PubSubClient.h>

void configModeCallback (WiFiManager *myWiFiManager) {
  Serial.println("Entered config mode");
  Serial.println(WiFi.softAPIP());
  //if you used auto generated SSID, print it
  Serial.println(myWiFiManager->getConfigPortalSSID());
}

//Variables de ccontrol
String mensaje;

//Funcion call back
void callback(char* topic, byte* payload, unsigned int length) {
 
  Serial.print("Mensaje desde topic: ");
  Serial.println(topic);
 
  Serial.print("Mensaje:");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
    mensaje = (char)payload[i];
  }
 
  Serial.println();
  Serial.println("-----------------------");
 
}

//Variables globales (Nombre de servidor,puerto,usuario,contraseña)
const char* mqttServer = "";
const int mqttPort = ;
const char* mqttUser = "";
const char* mqttPassword = "";



//Cliente 
WiFiClient espClient;
PubSubClient client(espClient);

//Setup (concetar a la red ,establecder entradas y salidas)

void setup() {
  pinMode(2,OUTPUT);
  Serial.begin(115200);

   //WiFiManager
  //Local intialization. Once its business is done, there is no need to keep it around
  WiFiManager wifiManager;
  //reset settings - for testing
  //wifiManager.resetSettings();

  //set callback that gets called when connecting to previous WiFi fails, and enters Access Point mode
  wifiManager.setAPCallback(configModeCallback);

  //fetches ssid and pass and tries to connect
  //if it does not connect it starts an access point with the specified name
  //here  "AutoConnectAP"
  //and goes into a blocking loop awaiting configuration
  if(!wifiManager.autoConnect()) {
    Serial.println("failed to connect and hit timeout");
    //reset and try again, or maybe put it to deep sleep
    ESP.reset();
    delay(1000);
  } 

  //if you get here you have connected to the WiFi
  Serial.println("connected...yeey :)");

  client.setServer(mqttServer, mqttPort);
  client.setCallback(callback);

  //Concetar a server mqtt
  while (!client.connected()) {
    Serial.println("Conectando a server MQTT...");
 
    if (client.connect("ESP8266Client", mqttUser, mqttPassword )) {
 
      Serial.println("Conectado");  
 
    } else {
 
      Serial.print("Fallo con estado ");
      Serial.print(client.state());
      delay(2000);
 
    }
  }
  //Publicar
  //client.publish("esp/helios/saludo", "Hola desde placa Helios 0.5");
  //Subscribir
  client.subscribe("esp/helios/iluminacion");
 
}


void loop() {
  
  client.loop();
  if (mensaje == "N"){
    digitalWrite(2,HIGH);
  
    }
  if (mensaje == "F"){
    digitalWrite(2,LOW);
    }
  if (WiFi.status() != WL_CONNECTED){
    Serial.print("Reset");
    ESP.restart();
    }
  
  }
