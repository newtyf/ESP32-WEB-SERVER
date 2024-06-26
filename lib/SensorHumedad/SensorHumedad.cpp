#include "Arduino.h"
#include "SensorHumedad.h"
SensorHumedad::SensorHumedad(int humedadPin, int bombaPin, int buzzerPin, int ledPin, int vent) {
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

void SensorHumedad::verificarHumedad() {
	float humedad = analogRead(humedadPin) / 1400.0 * 100.0;
	if (humedad < 50) {
		digitalWrite(bombaPin, HIGH);
    tone(buzzerPin, 2456,1000);
    tone(buzzerPin, 2920,1000);
    delay(500);
	} else {
		digitalWrite(bombaPin, LOW);
		noTone(buzzerPin);
	
	}
}

float SensorHumedad:: Humedad_Datos(){
  	float humedad = analogRead(humedadPin) / 1400.0 * 100.0;
    return humedad;
}

