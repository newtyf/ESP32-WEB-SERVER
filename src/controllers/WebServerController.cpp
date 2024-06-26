#include "WebServerController.h"
#include "SPIFFS.h"

void WebServerController::setupRoutes(AsyncWebServer& server) {
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(SPIFFS, "/index.html", "text/html");
    });

    server.serveStatic("/", SPIFFS, "/");

    server.onNotFound([](AsyncWebServerRequest *request){
        request->send(404, "text/plain", "La pagina no existe");
    });
}
