#include <Keypad.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,10,9,8,7);
const byte jmlBaris = 4;
const byte jmlKolom = 3;
char keys[jmlBaris][jmlKolom] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'},
};
// Hubungkan pin baris keypad dengan pin arduino
byte pinBaris[jmlBaris] = {3,2,1,0};

// Hubungkan pin baris keypad dengan pin arduino
byte pinKolom[jmlKolom] = {4,5,6};
int count = 0;
Keypad keypad = Keypad(makeKeymap(keys), pinBaris, pinKolom, jmlBaris, jmlKolom);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
}

void loop() {
  // put your main code here, to run repeatedly:
  char key = keypad.getKey(); //cek jika tombol ditekan
  if(key != NO_KEY) {
    lcd.print(key); // cetak ke LCD
    count++; // pindahkan karakter ke baris lcd berikutnya setelah penekanan tombol
  }
}

// https://playground.arduino.cc/Code/Keypad/
// https://www.arduino.cc/reference/en/language/variables/data-types/array/
// https://www.arduino.cc/reference/en/language/variables/data-types/byte/
