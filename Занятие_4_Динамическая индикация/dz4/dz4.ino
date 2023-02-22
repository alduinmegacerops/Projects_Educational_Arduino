#define SER 8
#define LATCH 9
#define CLK 10

byte digit[10] = {
  B00111111,
  B00000110,
  B01011011,
  B01001111,
  B01100110,
  B01101101,
  B01111101,
  B00000111,
  B01111111,
  B01101111
};

byte ten[10] = {
  B10111111,
  B10000110,
  B11011011,
  B11001111,
  B11100110,
  B11101101,
  B11111101,
  B10000111,
  B11111111,
  B11101111
};

void setup() 
{
  pinMode(SER, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(CLK, OUTPUT);
}

void loop() 
{
  for(int i = 0; i < 10; i++)
  {
    for(int j = 0; j < 10; j++)
    {
      digitalWrite(LATCH, LOW);
      shiftOut(SER, CLK, MSBFIRST, ten[i]);
      shiftOut(SER, CLK, MSBFIRST, digit[j]);
      digitalWrite(LATCH, HIGH);
      delay(500);
    }
  }
}
