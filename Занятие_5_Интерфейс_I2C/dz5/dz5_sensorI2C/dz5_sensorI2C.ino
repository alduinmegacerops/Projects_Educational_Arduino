#include "I2Cdev.h"                  // Подключение библиотеки I2Cdev
#include "MPU6050.h"                 // Подключение библиотеки MPU6050 
#include "Wire.h"                    // Подключение библиотеки WireCdev
#include <APDS9930.h>                // Подключаем библиотеку APDS9930

APDS9930 apds;                       // Создаем объект apds
MPU6050 CY531;                       // Создаем объект, символизирующий модуль датчика

int16_t ax, ay, az;                  // Переменные для хранения значений акселерометра
int16_t gx, gy, gz;                  // Переменные для хранения значений гироскоп
float ambient_light = 0;             // Создаем пеерменную, для хранения данных

void setup() 
{
  Serial.begin(9600);                // Инициируем передачу данных в монитор на скорости 9600 бит
  Serial.println("Initializing I2C devices...");
  
  apds.init();                       // Инициируем работу датчика
  CY531.initialize();                // Инициализация MPU
  
  apds.enableLightSensor(false);     // Разрешаем режим определения освещённости:  
  
  delay(500);                        // Пауза
}

void loop()
{
CY531.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);   // Чтение значений гироскопа и акселерометра
apds.readAmbientLightLux(ambient_light);          // Считываем показания

// вывод значений в монитор
Serial.print(F("Ambient: "));
Serial.println(ambient_light);
Serial.print("ax = ");
Serial.print(ax); 
Serial.print("\n");
Serial.print("ay = ");
Serial.print(ay); 
Serial.print("\n");
Serial.print("az = ");
Serial.print(az); 
Serial.print("\n");
Serial.print("gx = ");
Serial.print(gx); 
Serial.print("\n");
Serial.print("gy = ");
Serial.print(gy); 
Serial.print("\n");
Serial.print("gz = ");
Serial.println(gz);
delay(5000); 
}