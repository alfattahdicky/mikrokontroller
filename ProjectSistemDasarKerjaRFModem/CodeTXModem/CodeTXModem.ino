#include <LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);
int TEMP_SENSOR = A0;

// Part Transmitter
void setup() {
  // put your setup code here, to run once:
  lcd.begin(20,4);
  Serial.begin(9600);
  lcd.setCursor(0,0);
  lcd.print("Wireless Serial ");
  lcd.setCursor(0,1);
  lcd.print("Communication via 2.4 GHz");
  lcd.setCursor(0,2);
  lcd.print("Modem at PNJ....");
}

void loop() {
  // put your main code here, to run repeatedly:
  int TEMP_SENSOR_ADC_VALUE = analogRead(TEMP_SENSOR);
  int TEMP_VAL = TEMP_SENSOR_ADC_VALUE / 2;
  lcd.setCursor(0,3);
  lcd.print("Temp. in 0C: ");
  lcd.setCursor(13,3);
  lcd.print(TEMP_VAL);
  Serial.write(TEMP_VAL);
  delay(100);
}
