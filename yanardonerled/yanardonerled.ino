int leds[8]={2,3,4,5,6,7,8,9};

void setup() {
  // put your setup code here, to run once:
  for(int i=0; i< int(sizeof(leds)/sizeof(leds[0])); i++){
    pinMode(leds[i],OUTPUT);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=2; i<=9; i++){
    digitalWrite(i,1);
    delay(100);
    digitalWrite(i,0);
  }

  for(int i=8; i>=3; i--){
    digitalWrite(i,1);
    delay(100);
    digitalWrite(i,0);
  }
  
  for(int i=0; i<=3; i++){
    digitalWrite(leds[i],1);
    digitalWrite(leds[i+4],1);
    delay(200);
    digitalWrite(leds[i],0);
    digitalWrite(leds[i+4],0);
  }
  
}
