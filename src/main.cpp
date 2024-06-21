
#include <WiFi.h>
#include <WebServer.h>
#include "SPIFFS.h"
#include <secrets.h>

/* Añade tu SSID & Clave para acceder a tu Wifi */
const char* ssid = SSID;  // Tu SSID
const char* password = PASSWORD;  //Tu Clave
String html = "";

WebServer server(80);

#define LED 2
bool LEDEstado = LOW;

void handle_OnConnect() {
  LEDEstado = LOW; // 1
  Serial.println("LED: OFF"); // 2
  server.send(200, "text/html", html); // 3
}

void handle_led1on() {
  LEDEstado = HIGH; //1
  Serial.println("GPIO4 Estado: ON"); // 2
  server.send(200, "text/plain", "1"); //3
}

void handle_led1off() {
  LEDEstado = LOW;
  Serial.println("GPIO4 Estado: OFF");
  server.send(200, "text/plain", "0");
}

void handle_NotFound() {
  server.send(404, "text/plain", "La pagina no existe");
}

void setup() {

  Serial.begin(9600);
  pinMode(LED, OUTPUT);

  if(!SPIFFS.begin(true)){
    Serial.println("An Error has occurred while mounting SPIFFS");
    return;
  }
  Serial.println("SPIFFS montado correctamente");

  File file = SPIFFS.open("/index.html");
  if(!file){
    Serial.println("Failed to open file for reading");
    return;
  }

  while(file.available()){
    html += (char)file.read();
  }
  file.close();

  WiFi.mode(WIFI_AP);
  Serial.println("");
  Serial.println("Setting AP (Access Point)…");
  WiFi.softAP(ssid, password);

  IPAddress IP = WiFi.softAPIP();
  Serial.println("AP IP address: ");
  Serial.print(IP);

  server.on("/", handle_OnConnect); // 1
  server.on("/led1on", handle_led1on); // 2
  server.on("/led1off", handle_led1off); // 2
  server.onNotFound(handle_NotFound); // 3

  server.begin();
  Serial.println("Servidor HTTP iniciado");
}

void loop() {
  server.handleClient();
  if (LEDEstado)
  {
    digitalWrite(LED, HIGH);
  }
  else
  {
    digitalWrite(LED, LOW);
  }
}