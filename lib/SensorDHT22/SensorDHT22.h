#ifndef SENSORDHT22_H
#define SENSORDHT22_H

#include <Arduino.h>
#include <DHT.h>

class SensorDHT22 {
  private:
    int dataPin;
    DHT dht;
    int buzzerPin;
    int LED;
    int VENT;
  public:
    float leerTemperatura();
    float leerHumedad();
    void mostrar();
    SensorDHT22(int dataPin,int buzzerPin,int LED,int VENT);
};

#endif // SENSORDHT22_H