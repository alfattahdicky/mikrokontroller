#include <Keypad.h>
#include <Password.h>
#include <LiquidCrystal.h>
Password password = Password("123456"); // kode pin
LiquidCrystal lcd(12,11,10,9,8,7);
int x = 0; // variabel looping
int a = 0; // variabel untuk kontrol tulisan LCD
int led = 13; // pin solenoid seperti coil membuka/menutup asumsi led
// definisi baris dan kolom
const byte jmlBaris = 4;
const byte jmlKolom = 3;
//inisiasi untuk keypad
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
Keypad padLock = Keypad(makeKeymap(keys), pinBaris, pinKolom, jmlBaris, jmlKolom);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Power On ...");
  lcd.setCursor(0,1);
  lcd.print("...by dicky...");
  delay(500);
  lcd.clear();
  padLock.addEventListener(keypadEvent);
}

void loop() {
  pinMode(led, OUTPUT);
  if(a == 0) {
    lcd.setCursor(0,0); 
    lcd.print("Masukan Kode...");
    lcd.noDisplay();
    delay(250);
    lcd.display();
    delay(250);
  }
  padLock.getKey(); //membaca keypad
}

void keypadEvent(KeypadEvent eKey) {
  switch(padLock.getState()){
    case PRESSED: //saat ditekan
    if(a == 0){
      lcd.clear();
      a = 1;
    }
    lcd.setCursor(0,0);
    lcd.print("Kode:        ");
    lcd.setCursor(x,1);
  switch(eKey) {
      case '*': 
        checkPassword();
        password.reset();
        break; // melakukan pengecekan password
      case '#': 
        password.reset(); 
        lcd.setCursor(0, 0); 
        lcd.clear();
        x=0; 
        a=0;
        break; //saat # ditekan, hapus password yg ditekan
      default:
        password.append(eKey); // default untuk selain * dan #
        lcd.print("*"); // print tanda *
        x++;
    }
  }
}

void checkPassword() {
  if(password.evaluate()) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(" Kode Diterima");
    lcd.setCursor(0,1);
    lcd.print("Silahkan masuk!");
    digitalWrite(led,HIGH); // aktifkan solenoid
    delay(2000);
    digitalWrite(led,LOW); // off
    x = 0;
    a = 0;
  } else{
    lcd.clear();
    lcd.setCursor(0,0); 
    lcd.print("Kode Ditolak");
    lcd.setCursor(0,1); 
    lcd.print("===============");
    // kedipkan teks lcd sebanyak 5 kali
    for(int i = 0; i < 5; i++) {
      lcd.noDisplay();
      delay(250);
      lcd.display();
      delay(250);
      x = 0;
      a = 0;    
    }
  }
}

// https://playground.arduino.cc/Code/Keypad/
// https://www.arduino.cc/reference/en/language/variables/data-types/array/
// https://www.arduino.cc/reference/en/language/variables/data-types/byte/
