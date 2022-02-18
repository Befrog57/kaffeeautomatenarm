#include <Servo.h>

String empfangen;
int dly=50;
Servo myservo;  // create servo object to control a servo
int pos = 0;    // variable to store the servo position
boolean stop=false;

void setup() {
  myservo.attach(2);  // attaches the servo on pin 5 to the servo object
  Serial.begin(9600);
  myservo.write(200);
}

void loop() {
  if(Serial.available() > 0)
  {
    empfangen = Serial.readString();
    empfangen.trim();
    stop=false;
    if (empfangen == "schnell")
      dly = 10;
    else if (empfangen == "mittel")
      dly = 30;
    else if (empfangen == "langsam")
      dly = 50;
    else if (empfangen == "STOP")
      stop = true;
    Serial.println(empfangen);
  }

  for (pos = 0; pos < 155 && stop==false; pos += 1) { // goes from 0 degrees to 360 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(dly);
  }
    for (pos = 155; pos > 0 && stop==false; pos -= 1) { // goes from 0 degrees to 360 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(dly);
  }
}
