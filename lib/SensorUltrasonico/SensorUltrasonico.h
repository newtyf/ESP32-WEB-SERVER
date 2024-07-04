#ifndef SENSORULTRASONICO_H
#define SENSORULTRASONICO_H

#include <Arduino.h>
#include <ESPAsyncWebServer.h>

class SensorUltrasonico
{
private:
  const int trigPin;
  const int echoPin;
  long level;
  long timeOn;
  int valorMinimo;
  int valorMaximo;

  unsigned long lastDataTime;
  bool dataReceived;

  const int buzzerPin;

public:
  SensorUltrasonico(const int trigPin, const int echoPin, const int buzzerPin);
  void begin();
  void calculateLevel();
  float getLevel();
};

#endif // SENSORULTRASONICO_H