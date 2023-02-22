#include <Adafruit_MPL3115A2.h>

Adafruit_MPL3115A2 basinc; //class adı, kendi belirlediğimzi değişken 

void setup() {
  Serial.begin(9600);
  while(!Serial);
  Serial.println("Adafruit_MPL3115A2 test!");

  if (!basinc.begin()) {
    Serial.println("Could not find sensor. Check wiring.");
    while(1);
  }

  // use to set sea level pressure for current location
  // this is needed for accurate altitude measurement
  // STD SLP = 1013.26 hPa
  basinc.setSeaPressure(1013.26);
}

void loop() {
  float pressure = basinc.getPressure();
  float altitude = basinc.getAltitude();
  float temperature = basinc.getTemperature();

  Serial.println("-----------------");
  Serial.print("pressure = "); Serial.print(pressure); Serial.println(" hPa");
  Serial.print("altitude = "); Serial.print(altitude); Serial.println(" m");
  Serial.print("temperature = "); Serial.print(temperature); Serial.println(" C");

  delay(250);
}