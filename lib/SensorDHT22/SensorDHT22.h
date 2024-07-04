#ifndef SENSORDHT22_H
#define SENSORDHT22_H

#include <Arduino.h>
#include <DHT.h>
#include <ESPAsyncWebServer.h>

class SensorDHT22 {
  private:
    int dataPin;
    DHT dht;
    int buzzerPin;
    int LED;
    int VENT;
  public:
    SensorDHT22(int dataPin,int buzzerPin,int LED,int VENT);
    void leerTemperatura();
    void leerHumedad();
    float leerTemperatura_Datos();
    float leerHumedad_Datos();
};
#endif // SENSORDHT22_H