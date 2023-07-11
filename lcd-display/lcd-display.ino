#include <LiquidCrystal_I2C.h>
///I2C MODÜLÜNÜN ARKASINDAKİ POTANSİYOMETRE İLE KOTRAST AYARINI YAP. Adjusting The LCD Contrast
LiquidCrystal_I2C lcd(0x27, 16,2);

void setup() {
  // put your setup code here, to run once:
  lcd.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(5, 0);
  lcd.print("Goktug");
  lcd.setCursor(5,1);
  lcd.print("Ocakli");
  delay(2000);
  lcd.clear();

  

  lcd.noBacklight();
  delay(2000);
  lcd.backlight();




}
