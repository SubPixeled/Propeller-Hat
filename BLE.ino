int incomingByte = 0;
int z = 0;
int s = 0;
int motorDirPin = 4;      // Motor direction connected to digital pin 4
int motorSpeedPin = 5;    // Motor speed connected to analog pin 5

void setup() {
  
  Serial.begin(115200);
  pinMode(motorDirPin, OUTPUT);       // sets the pin as output
  pinMode(motorSpeedPin, OUTPUT);     // sets the pin as output
  pinMode(A3,INPUT);

  digitalWrite(motorDirPin, LOW);     // sets the default dir to be forward
  digitalWrite(motorSpeedPin, LOW);

}

void loop() {
  
  if (Serial.available() > 0) {
    // read the incoming byte:
  incomingByte = Serial.read();

  if(incomingByte = 25)z = 64;
  if(incomingByte = 50)z = 128;
  if(incomingByte = 75)z = 192;
  if(incomingByte = 100)z = 255;
  
  
  
  Serial.print("I received: ");
  Serial.println(z);
 analogWrite(motorSpeedPin, z);
 }

else{
 int a=analogRead(A3);
   z=map(a,0,1023,0,255);

 // Adjust to prevent "buzzing" at very low speed

 if (z < 8)z = 0;
 
 Serial.println(z);
 delay(100);
 

 
 analogWrite(motorSpeedPin, z);
}
}


