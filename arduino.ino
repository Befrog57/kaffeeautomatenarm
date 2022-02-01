#include <Servo.h>

String empfangen;
int dly=5;
Servo myservo;  // create servo object to control a servo
int pos = 0;    // variable to store the servo position
boolean stop=true;
 
void setup() {
  myservo.attach(5);  // attaches the servo on pin 5 to the servo object
  Serial.begin(9600);
}
 
void loop() {
  if(Serial.available() > 0)
  {
    empfangen = Serial.readString();
    empfangen.trim();
    stop=false;
    if (empfangen == "schnell")
      dly= 0;
    else if (empfangen == "mittel")
      dly= 10;
    else if (empfangen == "langsam")
      dly=20;
    else if (empfangen == "STOP")
      stop=true;
    Serial.println(empfangen);  
  }
  else
  {
    dly=5;
  }
  for (pos = 0; pos < 360 && stop==false; pos += 1) { // goes from 0 degrees to 360 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(dly);
  }
}
