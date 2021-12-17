String emfangen;

void setup()
{
  Serial.begin(9600);  //Boudrate syn mit UART
  pinMode(A0, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    emfangen=Serial.readString();
    //Löscht Leerzeichen
    emfangen.trim();
    if (emfangen == "schnell") {
        Serial.println("Schnell");
        analogWrite (A0, 255);
    } else if (emfangen == "mittel") {
        Serial.println("Mittel");
        analogWrite (A0, 190);
    } else if (emfangen == "langsam") {
        Serial.println("Langsam");
        analogWrite (A0, 60);
    } else if (emfangen == "STOP") {
        Serial.println("STOP");
        analogWrite (A0, 0);
    }
  }
}
