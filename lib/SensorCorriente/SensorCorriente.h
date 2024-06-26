#ifndef SENSOR_CORRIENTE_H
#define SENSOR_CORRIENTE_H

#include <Arduino.h>
class SensorCorriente {
  private:
    int pinSensor;
  public:
    SensorCorriente(int pinSensor);
    float leerCorriente();
    void mostrarCorriente();
};

#endif