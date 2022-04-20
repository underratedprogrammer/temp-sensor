#include <Wire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal_I2C.h>
#define ONE_WIRE_BUS 3
LiquidCrystal_I2C lcd(0x27,16,2);
  OneWire oneWire(ONE_WIRE_BUS);

  DallasTemperature sensors(&oneWire);

void setup() {
     lcd.init();
     lcd.clear();
     lcd.backlight();
     Serial.begin(9600);
     sensors.begin();
}

void loop() {
  delay(1000);
  lcd.setCursor(2,0);
  sensors.requestTemperatures();
  Serial.print("Temperature : ");
  Serial.print(sensors.getTempCByIndex(0));

  Serial.print((char)248);
  Serial.print( "C | ");

  Serial.print("Faranhite : ");
  Serial.print((sensors.getTempCByIndex(0)*9)/5 + 32);
  Serial.print(char(248));
  Serial.println("F");

  delay(500);
}














