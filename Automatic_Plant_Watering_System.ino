#include "dht.h"
#define dht_apin A0
#define soilPin A1

dht DHT;
int water;
int soilMoistureValue;
int soilMoisturePercent;

void setup() {
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  pinMode(6, INPUT);
  pinMode(soilPin, INPUT);

  delay(500);
  Serial.println("DHT11 Humidity & Temperature Sensor Initialized");
  delay(1000);
}

void loop() {
  DHT.read11(dht_apin);
  Serial.print("Current humidity = ");
  Serial.print(DHT.humidity);
  Serial.print("%  ");
  Serial.print("temperature = ");
  Serial.print(DHT.temperature);
  Serial.println("C");

  water = digitalRead(6);
  if (water == HIGH) {
    digitalWrite(3, LOW);
  } else {
    digitalWrite(3, HIGH);
  }

  soilMoistureValue = analogRead(soilPin);
  soilMoisturePercent = map(soilMoistureValue, 1023, 0, 0, 100);
  Serial.print("Soil moisture = ");
  Serial.print(soilMoisturePercent);
  Serial.println("%");

  delay(5000);
}
