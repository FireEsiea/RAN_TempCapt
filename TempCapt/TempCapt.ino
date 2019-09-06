#include <Wire.h>#include <SPI.h>
#include <Adafruit_BMP280.h>
#define BMP_SCK 13
#define BMP_MISO 12
#define BMP_MOSI 11 
#define BMP_CS 10
Adafruit_BMP280 bmp;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.println(F("BMP280 test"));
if(!bmp.begin()) {  
  Serial.println(F("Could not find a valid BMP280 sensor, check wiring!"));
    while(1);
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

  if ( temp > 29.00 ) {
    analogWrite(2, 255);
  } else if (temp < 29.00 ) {
    analogWrite(2, 0);
  
  }
  delay(2000);
}
