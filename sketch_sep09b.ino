#include <SPI.h>
#include <Wire.h>
#include <MFRC522.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SS_PIN 10
#define RST_PIN 9
#define LED1 3
#define LED2 4

Adafruit_SSD1306 display(128, 64, &Wire, 5);

MFRC522 rfid(SS_PIN, RST_PIN);

byte led1 = 0;
byte led2 = 0;



void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.display();
  
  Serial.begin(9600);
  
  Serial.println("Please put your card..");
  SPI.begin();
  rfid.PCD_Init();

  
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);

   display.setCursor(3,2);
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.print("put your card"); 
    display.display();
    delay(200);
    display.clearDisplay();
}

void loop() {

  if ( ! rfid.PICC_IsNewCardPresent())
    return;
  if ( ! rfid.PICC_ReadCardSerial())
    return;

  Serial.print("NUID tag is :");
  delay(200);
  String ID = "";
  for (byte i = 0; i < rfid.uid.size; i++) {
    Serial.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(rfid.uid.uidByte[i], HEX);
    ID.concat(String(rfid.uid.uidByte[i] < 0x10 ? " 0" : " "));
    ID.concat(String(rfid.uid.uidByte[i], HEX));
    delay(300);
  }
  Serial.println();
  ID.toUpperCase();
  
 if (ID.substring(1) == "73 80 62 1E") {
      digitalWrite(LED2, LOW);
    led2 = 0;
    delay(500);
      digitalWrite(LED1, HIGH);
    led1 = 1;
    delay(500);
    
    display.setCursor(3,16);
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.print("name= amirreza"); 
    display.display();

    display.setCursor(3,24);
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.print("dad= sasan"); 
    display.display();
   
    display.setCursor(3,32);
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.print("age= 15"); 
    display.display();

    display.setCursor(3,40);
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.print("national= 2581868422"); 
    display.display();

    display.setCursor(3,48);
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.print("grade= 10th"); 
    display.display();

    display.setCursor(3,56);
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.print("school= sampad"); 
    display.display();
    display.clearDisplay();
  }
  /* else if (ID.substring(1) == "32 5C D5 22") {
    digitalWrite(LED2, HIGH);
    led2 = 1;
    delay(500);
     
    display.setCursor(3,16);
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.print("name= pop smoke"); 
    display.display();

    display.setCursor(3,24);
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.print("dad= greg"); 
    display.display();
   
    display.setCursor(3,32);
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.print("age= 20"); 
    display.display();

    display.setCursor(3,40);
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.print("national= a19002874"); 
    display.display();

    display.setCursor(3,48);
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.print("grade= 12th"); 
    display.display();

    display.setCursor(3,56);
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.print("school= brooklyn"); 
    display.display();
    } */
    else{
        digitalWrite(LED1, LOW);
    led1 = 0;
    delay(500);
      digitalWrite(LED2, HIGH);
    led2 = 1;
    delay(500);
    
      display.setCursor(3,30);
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.print("wrong card!"); 
    display.display();
     display.clearDisplay();
    }
 }
