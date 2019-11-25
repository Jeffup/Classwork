int ledPin = 10;
void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    for (int value = 0 ; value < 255; value++){ 
     analogWrite(ledPin, value);
     delay(5);
  }
  for (int value = 255; value >0; value--){ 
     analogWrite(ledPin, value); 
     delay(5); 
   }
}
