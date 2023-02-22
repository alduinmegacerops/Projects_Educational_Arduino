#include "Wire.h" 

int addr[2] = {0x39, 0x68};
char sensor[2][10] = {"APDS-9930", "GY-521"};

void setup()
{
    Serial.begin(9600);
}
 
void loop(){
  for(int i = 0; i < 2; i++)
  {
    Wire.beginTransmission(addr[i]); // начинаем общение с шиной
    Wire.begin();//инициализируем прослушаивание шины
    Wire.write(0);//отправляем ноль, чтобы считать показания с датчика
    Wire.endTransmission();//заканчиваем общение с шиной
    Wire.requestFrom(addr[i], 1);//ждем единицу с датчика
    while(Wire.available() == 0);//цикл будет крутиться пока мы не получим информацию
    float buffer = Wire.read();//  полученное значение добавляем в переменную
    Serial.print("Sensor ");
    Serial.print(sensor[i]);
    Serial.print(" : ");
    Serial.println(buffer);
  }
  delay(5000);
}
