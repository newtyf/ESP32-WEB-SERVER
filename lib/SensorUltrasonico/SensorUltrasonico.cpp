#include "SensorUltrasonico.h"

SensorUltrasonico::SensorUltrasonico(const int trigPin, const int echoPin, const int buzzerPin) : trigPin(trigPin), echoPin(echoPin), buzzerPin(buzzerPin), level(0), timeOn(0), lastDataTime(0), dataReceived(false) {}
void SensorUltrasonico::begin() {
  
    pinMode(echoPin, INPUT);
    pinMode(trigPin, OUTPUT);

    
}

// ESTE ES SOLO PARA CALCULAR Y MOSTRAR NO SE PUEDE JALAR DATOS PARA LA PAGINA
void SensorUltrasonico::calculateLevel() {
  digitalWrite(trigPin, HIGH);
  delay(1);
  digitalWrite(trigPin, LOW);
  timeOn = pulseIn(echoPin, HIGH);
  level = timeOn / 58.2;

  const int nivelMax = 30;
  const int nivelCasoVacio = 20;
  const int nivelMin = 5;

  if (level < nivelMin) {
       tone(buzzerPin, 500, 1000);
       tone(buzzerPin, 600, 1000);
  }
  if (level >= nivelMin && level <= nivelMin + 5) {
    Serial.println("EL RECIPIENTE ESTA LLENO");
  }
  if (level >= nivelCasoVacio && level <= nivelCasoVacio + 5) {
    Serial.println("EL RECIPIENTE ESTA CASI VACIO!");
  }
  if (level >= nivelMax) {
    Serial.println("EL RECIPIENTE NECESITA AGUA!");
 
  }

}
// JALA EL NIVEL PUEDES HACER LA MISMA LOGICA DE ARRIBA
int SensorUltrasonico::getLevel() {
  digitalWrite(trigPin, HIGH);
  delay(1);
  digitalWrite(trigPin, LOW);
  timeOn = pulseIn(echoPin, HIGH);
  level = timeOn / 58.2;
  return level;
}

