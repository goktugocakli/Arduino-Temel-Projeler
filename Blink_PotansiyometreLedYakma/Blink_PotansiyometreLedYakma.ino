#define LED_Kirmizi 3
#define LED_Sari 5
#define POT A0

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_Kirmizi, OUTPUT);
  pinMode(LED_Sari, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int pot_deger = analogRead(POT);
  Serial.println(pot_deger);

  int output_guc = map(pot_deger, 0, 1023, 0, 255);
  analogWrite(LED_Kirmizi, output_guc);
}
