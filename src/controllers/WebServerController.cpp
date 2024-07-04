#include "WebServerController.h"
#include "SPIFFS.h"

WebServerController::WebServerController(AsyncWebServer &server, AsyncWebSocket &ws) : server(server), ws(ws) {}

void WebServerController::begin()
{
    server.begin();
}

void WebServerController::setupRoutes()
{
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
              { request->send(SPIFFS, "/index.html", "text/html"); });

    server.serveStatic("/", SPIFFS, "/");

    server.onNotFound([](AsyncWebServerRequest *request)
                      { request->send(404, "text/plain", "La pagina no existe"); });
}

void WebServerController::setupSocket(std::function<void(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len)> onEvent)
{
    ws.onEvent(onEvent);
    server.addHandler(&ws);
}
