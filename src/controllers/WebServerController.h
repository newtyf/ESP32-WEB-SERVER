#ifndef WEBSERVERCONTROLLER_H
#define WEBSERVERCONTROLLER_H

#include <ESPAsyncWebServer.h>

class WebServerController
{
public:
    AsyncWebServer &server;
    AsyncWebSocket &ws;

    WebServerController(AsyncWebServer &server, AsyncWebSocket &ws);
    void begin();
    void setupRoutes();
    void setupSocket(std::function<void(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len)> onEvent);
};

#endif
