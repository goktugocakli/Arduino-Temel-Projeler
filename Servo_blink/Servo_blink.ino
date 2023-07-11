#include <Servo.h>

Servo myServo;


void setup() {
  // put your setup code here, to run once:
  myServo.attach(6);
  myServo.write(90);
}

void loop() {
  // put your main code here, to run repeatedly:
  myServo.write(0);
  delay(500);
  myServo.write(180);
  delay(500);  
}
