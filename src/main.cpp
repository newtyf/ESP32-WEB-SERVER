#include <Arduino.h>
#include <ArduinoJson.h>
#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <SPIFFS.h>

#include "SensorDHT22.h"
#include "SensorHumedad.h"
#include "SensorUltrasonico.h"

#include "controllers/WebServerController.h"

// Aca se definió el SSID y PASSWORD
#include <secrets.h>

/* Añade tu SSID & Clave para acceder a tu Wifi */
const char *ssid = SSID;
const char *password = PASSWORD;

// Timer variables
unsigned long lastTime = 0;
unsigned long timerDelay = 30000;

// ESP32 pins
const int Bomba = 32;
const int FOCO = 33;
const int buzzerPin = 25;
const int Hum = 34;
const int Vent = 27;
const int DHT = 2;

const int trigger = 12;
const int echo = 13;

AsyncWebServer server(80);
AsyncWebSocket ws("/ws");
WebServerController webServerController(server, ws);

SensorHumedad sensorHumedad(Hum, Bomba, buzzerPin, FOCO, Vent);
SensorDHT22 sensorDHT22(DHT, buzzerPin, FOCO, Vent);
SensorUltrasonico sensorUltrasonico(trigger, echo, buzzerPin);

void notifyClients(String eventName, String sensorReadings)
{
  JsonDocument doc;
  doc["event"] = eventName;
  doc["payload"] = sensorReadings;

  String jsonString;
  serializeJson(doc, jsonString);

  ws.textAll(jsonString);
}

void handleWebSocketMessage(void *arg, uint8_t *data, size_t len)
{
  AwsFrameInfo *info = (AwsFrameInfo *)arg;
  if (info->final && info->index == 0 && info->len == len && info->opcode == WS_TEXT)
  {
    data[len] = 0;
    String message = (char *)data;
    // Check if the message is "getReadings"
    if (strcmp((char *)data, "getReadings") == 0)
    {
      // if it is, send current sensor readings
      float temperatura_DATO = sensorDHT22.leerTemperatura_Datos();
      Serial.print(String(temperatura_DATO));
      notifyClients("newTemperature", String(temperatura_DATO));
    }
  }
}

void onEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len)
{
  switch (type)
  {
  case WS_EVT_CONNECT:
    Serial.printf("WebSocket client #%u connected from %s\n", client->id(), client->remoteIP().toString().c_str());
    break;
  case WS_EVT_DISCONNECT:
    Serial.printf("WebSocket client #%u disconnected\n", client->id());
    break;
  case WS_EVT_DATA:
    handleWebSocketMessage(arg, data, len);
    break;
  case WS_EVT_PONG:
  case WS_EVT_ERROR:
    break;
  }
}

void setup()
{
  Serial.begin(9600);

  sensorUltrasonico.begin();

  if (!SPIFFS.begin(true))
  {
    Serial.println("Ocurrió un error mientras se montaba el SPIFFS");
    return;
  }
  Serial.println("SPIFFS montado correctamente");

  webServerController.setupRoutes();
  webServerController.setupSocket(onEvent);

  WiFi.mode(WIFI_AP);
  Serial.println("");
  Serial.println("Setting AP (Access Point)…");
  WiFi.softAP(ssid, password);

  IPAddress IP = WiFi.softAPIP();
  Serial.println("AP IP address: ");
  Serial.print(IP);

  webServerController.begin();

  Serial.println("Servidor HTTP iniciado");
}

void loop()
{
  if ((millis() - lastTime) > timerDelay)
  {
    float temperatura_DATO = sensorDHT22.leerTemperatura_Datos();
    float humedad_DATO = sensorHumedad.Humedad_Datos();
    int level_DATO = sensorUltrasonico.getLevel();

    notifyClients(String(temperatura_DATO), "newTemperature");
    notifyClients(String(humedad_DATO), "newHumidity");
    notifyClients(String(level_DATO), "waterTankLevel");

    lastTime = millis();
  }

  if (true)
  {
    sensorDHT22.leerTemperatura();
    sensorDHT22.leerHumedad();
    sensorHumedad.verificarHumedad();
    sensorUltrasonico.calculateLevel();
  }

  ws.cleanupClients();
}