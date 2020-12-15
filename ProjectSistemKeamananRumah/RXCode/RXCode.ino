#include <LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  Serial.begin(9600);
  lcd.setCursor(0,0);
  lcd.print("SECURITY SYSTEM");
  lcd.setCursor(0,1);
  lcd.print("OF RESTRICTED AREA");
  delay(100);
}


void loop() {
  // put your main code here, to run repeatedly:
  int PIR_sensor_SERIAL_BYTE = Serial.read();
  if(PIR_sensor_SERIAL_BYTE == 10) {
    lcd.clear();
    Serial.print("PIRSENSOR:");
    Serial.println(PIR_sensor_SERIAL_BYTE);
    lcd.setCursor(0,1);
    lcd.print("SECURITY BREAK");
    delay(50);
  }else if(PIR_sensor_SERIAL_BYTE == 20){
    lcd.clear();
    Serial.print("PIRSENSOR:");
    Serial.println(PIR_sensor_SERIAL_BYTE);
    lcd.setCursor(0,1);
    lcd.print("SECURITY SECURED");
    delay(50);
  }
}
