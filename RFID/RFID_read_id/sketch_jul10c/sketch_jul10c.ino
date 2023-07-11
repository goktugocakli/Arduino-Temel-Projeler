#include <MFRC522.h>
#include <SPI.h>
#include <LiquidCrystal_I2C.h>

//card id: A3 B3 8A A9
#define red_led 5
#define green_led 4
#define RST_PIN 9
#define SS_PIN 10

String const myCardUID = "a3 b3 8a a9 ";
LiquidCrystal_I2C lcd(0x27, 16,2);
MFRC522 rfid(SS_PIN, RST_PIN); // Instance of the class

MFRC522::MIFARE_Key key; 

void setup() { 
  pinMode(red_led, OUTPUT);
  pinMode(green_led, OUTPUT);
  Serial.begin(9600);
  SPI.begin(); // Init SPI bus
  rfid.PCD_Init(); // Init RC522 
  lcd.begin();
}
 
void loop() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Karti Okutunuz");
  // Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
  if ( ! rfid.PICC_IsNewCardPresent())
    return;

  // Verify if the NUID has been readed
  if ( ! rfid.PICC_ReadCardSerial())
    return;

  MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
  Serial.print(F("RFID Tag UID:"));
  String cardUID = toHexString(rfid.uid.uidByte, rfid.uid.size);
  rfid.PICC_HaltA(); // Halt PICC
  Serial.println("");

  Serial.println(myCardUID);
  Serial.println(cardUID);

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
    delay(3000);
    digitalWrite(green_led, LOW);
  }else{
    lcd.setCursor(0,1);
    lcd.print("Yekisiz giris");
    Serial.println("Yetkisiz giris");
    digitalWrite(red_led, HIGH);
    delay(5000);
    digitalWrite(red_led,LOW);
  }
}

//Routine to dump a byte array as hex values to Serial. 
String toHexString(byte *buffer, byte bufferSize) {
  String hexString = ""; // Boş bir string oluştur
  
  for (byte i = 0; i < bufferSize; i++) {
    if (buffer[i] < 0x10) {
      hexString += "0"; // Eğer değer 0x10'dan küçükse başına sıfır ekle
    }
    hexString += String(buffer[i], HEX); // Değeri stringe dönüştür ve hexString'e ekle
    hexString += " "; // Boşluk ekle
  }
  Serial.println(hexString);
  return hexString;
}