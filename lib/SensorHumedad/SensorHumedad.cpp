#include "Arduino.h"
#include "SensorHumedad.h"
SensorHumedad::SensorHumedad(int humedadPin, int bombaPin, int buzzerPin, int ledPin, int vent)
{
	this->humedadPin = humedadPin;
	this->bombaPin = bombaPin;
	this->buzzerPin = buzzerPin;
	this->ledPin = ledPin;
	this->vent = vent;
	pinMode(bombaPin, OUTPUT);
	pinMode(buzzerPin, OUTPUT);
	pinMode(ledPin, OUTPUT);
	pinMode(vent, OUTPUT);
}

void SensorHumedad::verificarHumedad()
{// MODIFICACIONEEES
//  CAMBIEN LA HUMEDAD MINIMA DE 2000 A 1600
	int lectura = analogRead(humedadPin); // Lee la lectura analógica del pin
	float humedad_min = 4095.00;					// Valor mínimo del rango del sensor
	float humedad_max = 1600.00;					// Valor máximo del rango del sensor

	//  ALTERE LA FORMULA PARA EL PORSENTAJE PORQUE NO SALIA ANTES
		float porcentajeHumedad =  100.0 - ((lectura - humedad_max) * 100.0) / (humedad_min - humedad_max);
	if (porcentajeHumedad < 0) {
    	porcentajeHumedad = 0;
  	}else if (porcentajeHumedad > 100) {
    porcentajeHumedad = 100;
	}
	if (porcentajeHumedad < 30)
	{
		digitalWrite(bombaPin, HIGH);
		tone(buzzerPin, 2456, 1000);
		tone(buzzerPin, 2920, 1000);
	}
	else
	{
		digitalWrite(bombaPin, LOW);
		noTone(buzzerPin);
	}
}
//AQUI IGUAL!!!!!!!!!!!
float SensorHumedad::Humedad_Datos()
{
	int lectura = analogRead(humedadPin); // Lee la lectura analógica del pin
	float humedad_min = 4095.00;					// Valor mínimo del rango del sensor
	float humedad_max = 1600.00;					// Valor máximo del rango del sensor

	// Calcula el porcentaje de humedad usando la fórmula de interpolación lineal
	float porcentajeHumedad =  100.0 - ((lectura - humedad_max) * 100.0) / (humedad_min - humedad_max);
	 if (porcentajeHumedad < 0) {
    porcentajeHumedad = 0;
  } else if (porcentajeHumedad > 100) {
    porcentajeHumedad = 100;
  }
	return porcentajeHumedad;
}
