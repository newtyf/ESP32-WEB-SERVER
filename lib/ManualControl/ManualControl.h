#ifndef MANUAL_CONTROL_H
#define MANUAL_CONTROL_H

#include <Arduino.h>

class ManualControl
{
private:
  int pinLed;
  int pinVentilador;
  int pinBomba;
  int pinActivador;
  int buzzerpin;

public:
  bool activado;
  ManualControl(int pinLed, int pinVentilador, int pinBomba, int pinActivador, int buzzerpin);
  void encenderLed();
  void apagarLed();
  void encenderVentilador();
  void apagarVentilador();
  void encenderBomba();
  void apagarBomba();
  void activar();
  void desactivar();
};

#endif