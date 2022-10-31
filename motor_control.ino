int motorDirPin = 2;      // Motor direction connected to digital pin 2
int motorSpeedPin = 3;    // Motor speed connected to analog pin 3

void setup()
{
  Serial.begin(9600);
  pinMode(motorDirPin, OUTPUT);       // set the pin as output
  pinMode(motorSpeedPin, OUTPUT);     // set the pin as output
  pinMode(A0,INPUT);

  digitalWrite(motorDirPin, LOW);     // sets the default dir to be forward
  digitalWrite(motorSpeedPin, LOW);   // sets the default speed to be off
}

void loop()
{
  // Set the motor direction to forward
  digitalWrite(motorDirPin, LOW);     

  // Ramp the motor speed up
  analogWrite(motorSpeedPin, 0);    // Min speed forward (motor off)
  delay(50);  
  analogWrite(motorSpeedPin, 63);   
  delay(50);  
  analogWrite(motorSpeedPin, 127);   
  delay(50); 
  analogWrite(motorSpeedPin, 191);   
  delay(50); 
  analogWrite(motorSpeedPin, 255);   // Max speed forward
  delay(50); 
  
  // Read the values from the potentiometers
    
  int s=analogRead(A0);
  int z=map(s,0,1023,0,255);

 // Adjust to prevent "buzzing" at very low speed
 
 if (z < 8)z = 0;
 
 Serial.println(z);

 analogWrite(motorSpeedPin, z);

}