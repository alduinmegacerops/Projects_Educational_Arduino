#include "DHT.h"
#include <TFT.h>
#include <SPI.h>

#define DHTPIN 2
#define CS 10
#define DC 9
#define RST 8

DHT dht(DHTPIN, DHT11);
TFT TFTscreen = TFT(CS, DC, RST);

char buffer[5];

void setup() 
{
  Serial.begin(9600);

  dht.begin();

  TFTscreen.begin();
  TFTscreen.background(0, 0, 0); // Очистим экран дисплея
  TFTscreen.setTextSize(2);      // Устанавливаем размер шрифта
}

float val = 0;

void loop() 
{
  delay(2000);

  TFTscreen.background ( 0 , 0 , 0 );

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // Проверка. Если не удается считать показания, выводится «Ошибка считывания», и программа завершает работу
  if (isnan(h) || isnan(t))
  {
    TFTscreen.stroke(255, 0, 0);
    TFTscreen.text("Error", 70, 40);
    TFTscreen.text("Sensor", 65, 60);
    return;
  }

  TFTscreen.stroke(0, 255, 0);
  TFTscreen.text("T = ", 40, 30);
  TFTscreen.text("RH = ", 40, 70);

  dtostrf(h, 5, 2, buffer);
  TFTscreen.text(buffer, 100, 70);
  memset(buffer, 0, 5);

  dtostrf(t, 5, 2, buffer);
  TFTscreen.text(buffer, 90, 30);
  memset(buffer, 0, 5);
}
