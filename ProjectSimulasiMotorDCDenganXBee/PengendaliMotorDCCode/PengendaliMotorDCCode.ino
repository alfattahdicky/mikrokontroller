#include <Keypad.h>
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'7', '8','9','/'},
  {'4', '5', '6', 'x'},
  {'1','2','3','-'},
  {'*', '0', '#', '+'}
};

byte rowPins[ROWS] = {13,12,11,10};
byte colPins[COLS] = {9,8,7,6};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
int keyCheck = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  char key = keypad.getKey();
  if(key) {
    if(key == '1') {
      keyCheck = 1;
      Serial.print('1');
    } else if(key == '2') {
      keyCheck = 1;
      Serial.print('2');
    } else if(key == '3') {
      keyCheck = 1;
      Serial.print('3');
    } else if(key == '4') {
      keyCheck = 1;
      Serial.print('4');
    } else if(key == '5') {
      keyCheck = 1;
      Serial.print('5');
    } else if(key == '6') {
      keyCheck = 1;
      Serial.print('6');
    } else if(keyCheck = 0) Serial.print(key);
    else {
      keyCheck = 0;
    }
  }

  

}
