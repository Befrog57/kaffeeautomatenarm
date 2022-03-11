#include <Servo.h>
#include <Wire.h>

String empfangen;
int dly=50;
Servo myservo;  // create servo object to control a servo
int pos = 0;    // variable to store the servo position
boolean stop=false;

void setup() {
  Wire.begin(4);
  Wire.onReceive(starteWasser);
  myservo.attach(2);  // attaches the servo on pin 5 to the servo object
  Serial.begin(9600);
  myservo.write(200);
}

void loop() {
  delay(100);
}

void starteWasser () {
  if(Wire.available() > 0)
  {
    empfangen = Wire.read();
    empfangen.trim();
    //stop=false;
    if (empfangen == "start") {
      stop=false;
      dly = 30;
    }
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