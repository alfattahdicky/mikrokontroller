#include <Keypad.h> // library keypad
#include <LiquidCrystal.h> // library lcd
LiquidCrystal lcd(13,12,11,10,9,8);

const byte jmlBaris = 4; // 4 baris
const byte jmlKolom = 4; // 4 kolom

char keys[jmlBaris][jmlKolom] = {
  {'7', '8', '9', '/'},
  {'4', '5', '6', 'x'},
  {'1', '2', '3', '-'},
  {'C', '0', '=', '+'},
};

// connect pin arduino to pin keypad rows
byte pinBaris[jmlBaris] = {7,6,5,4};
// connect pin arduino to pin keypad column
byte pinKolom[jmlKolom] = {3,2,1,0};

// inisialisasi keypad
Keypad myKeypad = Keypad(makeKeymap(keys), pinBaris, pinKolom, jmlBaris, jmlKolom);

// deklarasi variabel
boolean valOnePresent = false;
boolean final = false;
String num1, num2;
long ans; 
char op;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.setCursor(2,0);
  lcd.print("Kalkulator AL!");
  delay(1000);
  lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
  char key = myKeypad.getKey();
  if(key != NO_KEY && key == '1' || key == '2' || key == '3' || key == '4' || key == '5' || key == '6' || key == '7' || key == '8' || key == '9' || key == '0'){
    if(valOnePresent != true) {
      num1 += key;
      int numLength = num1.length();
      lcd.setCursor(15 - numLength, 0); // print operator
      lcd.print(num1);
    } else {
      num2 += key;
      int numLength = num2.length();
      lcd.setCursor(15 - numLength, 1);
      lcd.print(num2);
      final = true;
    }
  } else if(valOnePresent == false && key != NO_KEY && (key == '/' || key == 'x' || key == '-' || key == '+')) {
    if(valOnePresent == false) {
      valOnePresent = true;
      op = key;
      lcd.setCursor(15,0);
      lcd.print(op);
    }
  } else if( final == true && key != NO_KEY && key == '=') {
    if(op == '+') {
      ans = num1.toInt() + num2.toInt();
    } else if(op == '-') {
      ans = num1.toInt() - num2.toInt();
    } else if(op == 'x') {
      ans = num1.toInt() * num2.toInt();
    } else if(op == '/') {
      ans = num1.toInt() / num2.toInt();
    }
    lcd.clear();
    lcd.setCursor(15,0);
    lcd.autoscroll();
    lcd.print(ans);
    lcd.noAutoscroll();
  }else if(key != NO_KEY && key == 'C') {
    lcd.clear();
    valOnePresent = false;
    final = false;
    num1 = "";
    num2 = "";
    ans = 0;
    op = ' ';
  }
}
