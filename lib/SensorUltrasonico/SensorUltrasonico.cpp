#include "SensorUltrasonico.h"

SensorUltrasonico::SensorUltrasonico(const int trigPin, const int echoPin, const int buzzerPin) : trigPin(trigPin), echoPin(echoPin), buzzerPin(buzzerPin), level(0), timeOn(0), valorMinimo(30), valorMaximo(0), lastDataTime(0), dataReceived(false) {}
void SensorUltrasonico::begin()
{

  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
}

void SensorUltrasonico::calculateLevel()
{
  // MODIFIQUE EL DELAY
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // Enviamos un pulso de 10us
  digitalWrite(trigPin, LOW);
  timeOn = pulseIn(echoPin, HIGH);
  // CAMBIE DE esto  v
  level = timeOn / 59; //<
                       // /
  float porcentaje;    //  almacenar el porcentaje calculado

  porcentaje = 100.0 - ((level - valorMaximo) * 100.0) / (valorMinimo - valorMaximo);
  //  rango 0-100
  if (porcentaje < 0)
  {
    porcentaje = 0;
  }
  else if (porcentaje > 100)
  {
    porcentaje = 100;
  }
  // en la consola serie va salir sus niveles
  const int por000 = 0; // no se usa

  // LA BOTELLA DE TIENE UNA ALTURA PARA EL AGUA DE 30cm  asi que me base en eso
  // del 10 % 25% 50% 75% 100% lo dividi
  const int por010 = 10;
  const int por025 = 25;
  const int por050 = 50;
  const int por075 = 75;
  const int por100 = 90;

  int nivel = -1;

  // esto es para la consola, y el buzzer
  if (porcentaje < por010)
  {
    Serial.print("NIVEL ");
    Serial.print(porcentaje);
    Serial.println("%");
    Serial.println("EL RECIPIENTE ESTA SECO , LLENALOO!");
    tone(buzzerPin, 500, 1000);
    tone(buzzerPin, 600, 1000);
  }
  else if (porcentaje >= por010 && porcentaje < por025)
  {
    nivel = 5;
  }
  else if (porcentaje >= por025 && porcentaje < por050)
  {
    nivel = 4;
  }
  else if (porcentaje >= por050 && porcentaje < por075)
  {
    nivel = 3;
  }
  else if (porcentaje >= por075 && porcentaje < por075)
  {
    nivel = 2;
  }
  else if (porcentaje >= por100)
  {
    nivel = 1;
  }
  else if (level > 30)
  {
    nivel = 0;
  }
  switch (nivel)
  {
  case 1:
    Serial.println();
    Serial.print("NIVEL ");
    Serial.print(porcentaje);
    Serial.print("%");
    Serial.println("EL RECIPIENTE ESTA LLENO");
    tone(buzzerPin, 800, 1000);
    break;
  case 2:
    Serial.println();
    Serial.print("NIVEL ");
    Serial.print(porcentaje);
    Serial.println("%");
    Serial.println("EL RECIPIENTE ESTA MEDIO LLENO!");
    break;
  case 3:
    Serial.println();
    Serial.print("NIVEL ");
    Serial.print(porcentaje);
    Serial.println("%");
    Serial.println("EL RECIPIENTE ESTA A LA MITAD!");
    break;
  case 4:
    Serial.println();
    Serial.print("NIVEL ");
    Serial.print(porcentaje);
    Serial.println("%");
    Serial.println("PRECAUCION POR EL NIVEL DEL TANQUE!");
    break;
  case 5:
    Serial.println();
    Serial.print("NIVEL ");
    Serial.print(porcentaje);
    Serial.println("%");
    Serial.println("EL RECIPIENTE ESTA CASI SIN AGUA!");
    break;
  case 0:
    Serial.println("NIVEL DESCONOCIDO");
  default:
    Serial.println();
    Serial.print("NIVEL ");
    Serial.print(porcentaje);
    Serial.print("%");
  }
}

float SensorUltrasonico::getLevel()
{
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  timeOn = pulseIn(echoPin, HIGH);
  level = timeOn / 59;
  float porcentaje; // Variable para almacenar

  // Calcular el porcentaje

  porcentaje = 100.0 - ((level - valorMaximo) * 100.0) / (valorMinimo - valorMaximo);
  // rango 0-100
  if (porcentaje < 0)
  {
    porcentaje = 0;
  }
  else if (porcentaje > 100)
  {
    porcentaje = 100;
  }

  return porcentaje;
}
