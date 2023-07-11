const int led=3;
const int pir_sensor=2;
int hareket=0;
int x;


void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
  pinMode(pir_sensor, INPUT);
  Serial.begin(9600);
  Serial.setTimeout(1);
}

void loop() {
  // put your main code here, to run repeatedly:
  hareket = digitalRead(pir_sensor);
  Serial.println(hareket);
  if(hareket==true){
    digitalWrite(led,1);
  } else{
    digitalWrite(led,0);
  }
  

}
