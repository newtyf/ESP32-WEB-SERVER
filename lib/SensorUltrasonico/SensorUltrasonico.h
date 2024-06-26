#ifndef SENSORULTRASONICO_H
#define SENSORULTRASONICO_H


#include <Arduino.h>
class SensorUltrasonico {
    private:
    const int trigPin;
    const int echoPin;
    int level;
    int timeOn;
    unsigned long lastDataTime;
    bool dataReceived;
    const int buzzerPin = 9;

  public:
    SensorUltrasonico(const int trigPin, const int echoPin, const int buzzerPin);
    void begin();
    void calculateLevel();
    int getLevel();
    
};

#endif // SENSORULTRASONICO_H