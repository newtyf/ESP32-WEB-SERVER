#include "ManualControl.h"

ManualControl::ManualControl(int pinLed, int pinVentilador, int pinBomba, int pinActivador, int buzzerpin)
{
  this->pinLed = pinLed;
  this->pinVentilador = pinVentilador;
  this->pinBomba = pinBomba;
  this->pinActivador = pinActivador;
  this->buzzerpin = buzzerpin;
  this->activado = false;

  pinMode(pinLed, OUTPUT);
  pinMode(pinVentilador, OUTPUT);
  pinMode(pinBomba, OUTPUT);
  pinMode(pinActivador, INPUT);
}

void ManualControl::encenderLed()
{
  if (activado)
  {
    digitalWrite(pinLed, HIGH);
    tone(buzzerpin, 980, 1000);
  }
}

void ManualControl::apagarLed()
{
  if (activado)
  {
    digitalWrite(pinLed, LOW);
    tone(buzzerpin, 810, 1000);
  }
}

void ManualControl::encenderVentilador()
{
  if (activado)
  {
    digitalWrite(pinVentilador, HIGH);
    tone(buzzerpin, 980, 1000);
  }
}

void ManualControl::apagarVentilador()
{
  if (activado)
  {
    digitalWrite(pinVentilador, LOW);
    tone(buzzerpin, 810, 1000);
  }
}

void ManualControl::encenderBomba()
{
  if (activado)
  {
    digitalWrite(pinBomba, HIGH);

    tone(buzzerpin, 980, 1000);
  }
}

void ManualControl::apagarBomba()
{
  if (activado)
  {
    digitalWrite(pinBomba, LOW);
    tone(buzzerpin, 810, 1000);
  }
}

void ManualControl::activar()
{
  activado = true;
}

void ManualControl::desactivar()
{
  activado = false;
  apagarLed();
  apagarVentilador();
  apagarBomba();
  noTone(buzzerpin);
}