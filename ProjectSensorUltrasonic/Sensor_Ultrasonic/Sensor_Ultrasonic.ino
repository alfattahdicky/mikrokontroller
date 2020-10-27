const int pingPin = 5;// Pin trigger
const int echoPin = 4; // Pin echo
const int ledPin = 13;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  long duration;// waktu saat memancarkan gelombang hingga diterima kembali
  long cm;// variabel untuk menyimpan hasil konversi dari Us ke cm
  pinMode(pingPin,OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(pingPin,LOW);
  digitalWrite(ledPin,LOW);
  
  pinMode(echoPin,INPUT);
  duration = pulseIn(echoPin,HIGH);
  // fungsi microsecondsToCentimeters  
  cm = microsecondsToCentimeters(duration);
  if(cm <= 200) {
    digitalWrite(ledPin,HIGH);
  }
  Serial.print(cm);
  Serial.print("cm");
  Serial.println("");
  delay(100); 
}

// mengubah microseconds ke cm 
long microsecondsToCentimeters(long microseconds){
    return microseconds*0.034/2;
}
