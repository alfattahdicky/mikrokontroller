int ml = A0; // Motor DC dihubungkan ke pin analog A0 arduino
int h = 255;
int l = 0;
String motion;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ml,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Silahkan ketik 'w' untuk memutar, 's' untuk berhenti ");
  while(Serial.available() == 0) {
    motion = Serial.readString();
    if(motion == "w") {
      analogWrite(ml,l);
    } else if(motion == "s") {
      analogWrite(ml,h);
    }
  }
  
}
