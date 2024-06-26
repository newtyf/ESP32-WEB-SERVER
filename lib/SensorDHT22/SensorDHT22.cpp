#include "SensorDHT22.h"

SensorDHT22::SensorDHT22(int dataPin, int buzzerPin, int LED, int VENT) : dataPin(dataPin), buzzerPin(buzzerPin), LED(LED), VENT(VENT), dht(dataPin, DHT11)
{
  dht.begin();
}

float SensorDHT22::leerTemperatura()
{
  float temperatura = dht.readTemperature();
  if (isnan(temperatura))
  {
    Serial.println("Error leyendo temperatura del DHT22");
    return 0.0;
  }

  // Aquí puedes agregar la lógica para activar el buzzer si la temperatura supera cierto umbral
  if (temperatura > 30.0)
  {
    tone(buzzerPin, 2000, 1000);
    tone(buzzerPin, 3000, 1000);
    tone(buzzerPin, 1500, 1000);

    digitalWrite(LED, HIGH);
    // Generar un sonido de 2000 Hz durante 1000 ms
  }
  else if (temperatura < 17.0)
  {
    tone(buzzerPin, 900, 1000);
    tone(buzzerPin, 800, 1000);
    tone(buzzerPin, 850, 1000);

    digitalWrite(VENT, LOW);
    // Generar un sonido de 2000 Hz durante 1000 ms
  }
  else
  {
    noTone(buzzerPin);
    digitalWrite(LED, LOW);
    digitalWrite(VENT, LOW);
  }
  return temperatura;
}

float SensorDHT22::leerHumedad()
{
  float humedad = dht.readHumidity();
  if (isnan(humedad))
  {
    Serial.println("Error leyendo humedad del DHT22");
    return 0.0;
  }

  // Aquí puedes agregar la lógica para activar el buzzer si la humedad supera cierto umbral
  if (humedad > 70.0)
  {
    tone(buzzerPin, 460, 500); // Generar un sonido de 3000 Hz durante 1000 ms
  }

  return humedad;
}
void SensorDHT22::mostrar()
{
  float temperatura = leerTemperatura();
  float humedad = leerHumedad();

  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println("°C");

  Serial.print("Humedad: ");
  Serial.print(humedad);
  Serial.println("%");
}
