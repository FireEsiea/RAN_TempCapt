#include <Wire.h>#include <SPI.h>
#include <Adafruit_BMP280.h>
#define BMP_SCK 13
#define BMP_MISO 12
#define BMP_MOSI 11 
#define BMP_CS 10
Adafruit_BMP280 bmp;
int count = 0;
#include <EEPROM.h>

void setup() {  
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.println(F("BMP280 test"));
if(!bmp.begin()) {  
  Serial.println(F("Could not find a valid BMP280 sensor, check wiring!"));
    while(1);
  }
 for (int i = 0 ; i < EEPROM.length() ; i++) {
    EEPROM.write(i, 0);
  }

}

void loop() {
  float temp = bmp.readTemperature();
  Serial.print(F("Temperature = "));
  Serial.print(temp);
  Serial.println(" *C");
  Serial.print(F("Pressure = "));
  Serial.print(bmp.readPressure());
  Serial.println(" Pa");
  Serial.print(F("Approx altitude = "));
  Serial.print(bmp.readAltitude(1013.25)); 
  
  // this should be adjusted to your local for-case
  Serial.println(" m");
  Serial.println();

 
    analogWrite(2, 255);
  if ( temp > 29.00 ) {
    analogWrite(2, 255);
  } else if (temp < 29.00 ) {
    analogWrite(2, 0);
  
  }

  EEPROM.write(count, temp);
  count++;
  Serial.println(count);
  
  delay(100);

  if (count == 50) {
    Serial.println(F("Voici toutes les températures enregistrées :"));
    for (int i = 0; i < 51; i++){
      byte valeur = EEPROM.read(i);
      Serial.println(valeur);
    }
    count = 0;
    
  }

}
