void setup() 
{
  Serial.begin(9600);
}

float val = 0;

void loop() 
{
  int newVal = analogRead(A3);
  int valOut;

  val += (newVal - val) * 0.1;
  valOut = map(val, 29, 1010, 0, 10);
  valOut = constrain(valOut, 0, 10);

  Serial.println(valOut);
  
  delay(30);

}
