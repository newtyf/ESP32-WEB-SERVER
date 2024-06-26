#ifndef SensorHumedad_h
#define SensorHumedad_h

#include <Arduino.h>

class SensorHumedad {
  private:
    int humedadPin;
    int bombaPin;
    int buzzerPin;
    int ledPin;
    int vent;

  public:
    SensorHumedad(int humedadPin, int bombaPin, int buzzerPin, int ledPin,int vent);
    void verificarHumedad();
    float Humedad_Datos();
};

#endif