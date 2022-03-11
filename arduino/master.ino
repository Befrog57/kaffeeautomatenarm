#include <Wire.h>

void setup()
{
  Wire.begin(); //  i2c bus aufbauen, optional kann master adresse vergebn werden
}

bool an = true;

void loop()
{
  Wire.beginTransmission(4); // an Teilnehmer mit Adresse 4
  Wire.write(an);
  Wire.endTransmission();    // Verbindungsabbau

  delay(20000);
}
