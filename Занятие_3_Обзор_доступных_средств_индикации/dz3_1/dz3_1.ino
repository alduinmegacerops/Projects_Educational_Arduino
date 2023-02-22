#define RED_LED 3
#define GREEN_LED 5
#define BLUE_LED 6

void setup() 
{
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
}

void loop() 
{
  int red = 0, green = 0, blue = 0;

  red = analogRead(A0);
  green = analogRead(A1);
  blue = analogRead(A2);

  red = map(red, 0, 1023, 0, 255);
  green = map(green, 0, 1023, 0, 255);
  blue = map(blue, 0, 1023, 0, 255);
  
  red = constrain(red, 0, 255);
  green = constrain(green, 0, 255);
  blue = constrain(blue, 0, 255);

  analogWrite(RED_LED, red);
  analogWrite(GREEN_LED, green);
  analogWrite(BLUE_LED, blue);

  delay(30);
}
