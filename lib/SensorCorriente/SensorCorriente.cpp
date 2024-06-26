#include "SensorCorriente.h"

SensorCorriente::SensorCorriente(int pinSensor) {
  this->pinSensor = pinSensor;
}
//JALA EL VALOR CORRIENTE DE AQUÍ
float SensorCorriente::leerCorriente() {
  int sensibilidad = 66;
  int offsetVoltaje = 2500;
  int valorADC = analogRead(pinSensor);
  double voltajeADC = (valorADC / 1024.0) * 5000;
  double corriente = ((voltajeADC - offsetVoltaje) / sensibilidad);

  return corriente;
}
//MOSTRAR COMO EJEMPLO
void SensorCorriente::mostrarCorriente() {
  float corriente = leerCorriente();

  Serial.print("Corriente = ");
  Serial.println(corriente);
}