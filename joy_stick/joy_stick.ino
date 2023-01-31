void setup() {
  Serial.begin(9600);

  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT_PULLUP);

  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop() {
  Serial.print(analogRead(A0));
  Serial.print("\t");
  Serial.print(analogRead(A1));
  Serial.print("\t");
  Serial.println(digitalRead(A2));

  int x = map(analogRead(A0), 0, 1023, -255, 255);
  if(x > -30 and x < 0){x = 0;}
  int y = map(analogRead(A1), 0, 1023, -255, 255);
  if(y > -10 and y < 0){y = 0;}
  
  Serial.print(x);
  Serial.print("\t");
  Serial.println(y);
  Serial.println();
  delay(100);

  if(y < 0){
    digitalWrite(5, LOW);
    analogWrite(6, (y*-1));
  }
  else if(y > 0){
    analogWrite(5, y);
    digitalWrite(6, LOW);
  }
  else{
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
  }
}
