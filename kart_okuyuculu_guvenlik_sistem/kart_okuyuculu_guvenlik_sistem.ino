#include <MFRC522.h>
#include <SPI.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

#define red_led 5
#define green_led 4
#define RST_PIN 9
#define SS_PIN 10
#define servo_pin 6

String const myCardUID = "A3B38AA9";

Servo myServo;
LiquidCrystal_I2C lcd(0x27, 16,2);
MFRC522 rfid(SS_PIN, RST_PIN); // Instance of the class

//MFRC522::MIFARE_Key key; 

void setup() { 
  pinMode(red_led, OUTPUT);
  pinMode(green_led, OUTPUT);

  myServo.attach(servo_pin);
  
  Serial.begin(9600);
  
  SPI.begin(); // Init SPI bus
  rfid.PCD_Init(); // Init RC522 
  
  lcd.begin();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Karti Okutunuz");
}
 
void loop() {
  myServo.write(180);

  // Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
  if ( ! rfid.PICC_IsNewCardPresent())
    return;

  // Verify if the NUID has been readed
  if ( ! rfid.PICC_ReadCardSerial())
    return;
  
  String cardUID = getCardUID();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Card Id:");
  lcd.setCursor(0,1);
  lcd.print(cardUID);
  delay(2000);

  if(myCardUID.equals(cardUID)){

    Serial.println("Yetlkili girişi");
    
    lcd.setCursor(0,0);
    lcd.print("Yekili giris");
    
    digitalWrite(green_led, HIGH);
    myServo.write(0);
    delay(3000);
    digitalWrite(green_led, LOW);
  }else{
    lcd.setCursor(0,0);
    lcd.print("Yekisiz giris");

    Serial.println("Yetkisiz giris");

    digitalWrite(red_led, HIGH);
    delay(5000);
    digitalWrite(red_led,LOW);
  }

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Karti Okutunuz");

}

String getCardUID(){
  String tagID = "";
  for (int i = 0; i < 4; i++) { // The MIFARE PICCs that we use have 4 byte UID
    tagID.concat(String(rfid.uid.uidByte[i], HEX)); // Adds the 4 bytes in a single String variable
  }
  tagID.toUpperCase();
  rfid.PICC_HaltA(); // Stop reading
  return tagID;
}
  