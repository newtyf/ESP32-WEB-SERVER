#ifndef WEBSERVERCONTROLLER_H
#define WEBSERVERCONTROLLER_H

#include <ESPAsyncWebServer.h>

class WebServerController {
public:
    void setupRoutes(AsyncWebServer& server);
};

#endif
