#include <Servo.h>

#define axis_X A0
#define axis_Y A1
#define SW_pin 7
#define servo_pin 5

Servo myServo;

void setup() {
  // put your setup code here, to run once:
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);

  myServo.attach(servo_pin);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int X_degeri = analogRead(axis_X);
  //int Y_degeri = analogRead(axis_Y);
  Serial.print("X degeri: ");
  Serial.println(X_degeri);
  /*Serial.print("Y degeri: ");
  Serial.println(Y_degeri);
  Serial.print("Switch: ");
  Serial.println(digitalRead(SW_pin));*/
  int angle = map(X_degeri, 0, 1023, 180, 0);
  Serial.print("Angle:");
  Serial.println(angle);
  myServo.write(angle);
}
