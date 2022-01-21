//#include <Servo.h>
//Servo servo;
String empfangen;
void setup()
{
  pinMode(A0, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  if(Serial.available() > 0)
  {
    empfangen = Serial.readString();
    empfangen.trim();
    
    if (empfangen == "schnell")
      analogWrite(A0, 255);
    else if (empfangen == "mittel")
      analogWrite(A0, 190);
    else if (empfangen == "langsam")
      analogWrite(A0, 60);
    else if (empfangen == "STOP")
      analogWrite(A0, 0);
      
    Serial.println(empfangen);  
  }
}
