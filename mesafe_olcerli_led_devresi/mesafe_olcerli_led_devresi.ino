#include <LiquidCrystal_I2C.h>

#include <LiquidCrystal_I2C.h>
///I2C MODÜLÜNÜN ARKASINDAKİ POTANSİYOMETRE İLE KOTRAST AYARINI YAP. Adjusting The LCD Contrast
LiquidCrystal_I2C lcd(0x27, 16,2);

int const led=6;
int const trig=12;
int const echo=10;

float sure;
float mesafe;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  lcd.begin();
}

void loop() {
  // put your main code here, to run repeatedly:


  mesafe=mesafe_olc();
  lcd.setCursor(0,0);
  lcd.print("Mesafe:");
  lcd.setCursor(0,1);
  lcd.print(mesafe);
  

  if(mesafe<10){
    digitalWrite(led, HIGH);
    delay(50);
    digitalWrite(led,LOW);
    delay(50);
  }else if(mesafe<30){
    digitalWrite(led, HIGH);
    delay(50);
    digitalWrite(led,LOW);
    delay(200);
    
  }else if(mesafe<50){
    digitalWrite(led, HIGH);
    delay(50);
    digitalWrite(led,LOW);
    delay(400);
  }
}

float mesafe_olc(){
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig,LOW);
  sure = pulseIn(echo, HIGH);
  mesafe = (sure/29.1)/2;
  if(mesafe>49){
    mesafe=50;
  }
  Serial.print("ölçülen mesafe: ");
  Serial.print(mesafe);
  Serial.println("cm");
  return mesafe;
}
