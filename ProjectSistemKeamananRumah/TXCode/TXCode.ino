#include <LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);
const int PIR_sensor_PIN = 3;
int PIR_sensor_PIN_state  = 0;
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  Serial.begin(9600);
  pinMode(PIR_sensor_PIN, INPUT);
  lcd.setCursor(0,0);
  lcd.print("SECURITY SYSTEM");
  lcd.setCursor(0,1);
  lcd.print("OF RESTRICTED AREA");
  delay(100);
}


void loop() {
  // put your main code here, to run repeatedly:
  PIR_sensor_PIN_state = digitalRead(PIR_sensor_PIN);
  if(PIR_sensor_PIN_state == HIGH) {
    lcd.clear();
    int PIR_SERIAL_BYTE = 10;
    Serial.write(PIR_SERIAL_BYTE);
    lcd.setCursor(0,1);
    lcd.print("SECURITY BREAK");
    delay(50);
  }else {
    lcd.clear();
    int PIR_SERIAL_BYTE = 20;
    Serial.write(PIR_SERIAL_BYTE);
    lcd.setCursor(0,1);
    lcd.print("SECURITY SECURED");
    delay(50);
  }
}
