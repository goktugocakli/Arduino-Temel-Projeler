#define led 5
#define button 10
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.print("buton değer okuma");
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int buton_durumu=digitalRead(button);
  Serial.print(buton_durumu);
  if(buton_durumu==0){
    digitalWrite(led,HIGH);
  }
  else{
    digitalWrite(led,LOW);
  }

}
