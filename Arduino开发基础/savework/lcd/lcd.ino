#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x20,16,2);

#include <dht11.h>
#define DHT11_PIN 4
dht11 DHT;

void setup() {
  // put your setup code here, to run once:
  lcd.init(); 
  lcd.backlight();
  lcd.setCursor(0,1);    //x=0, y=1
  lcd.print("Arduino");
  //humidity
  Serial.begin(9600);
}

void loop() {
  int chk;
  chk = DHT.read(DHT11_PIN); 
  if(chk== DHTLIB_OK){
  lcd.setCursor(0,0);
  lcd.print(DHT.humidity);
  lcd.setCursor(8,0);
  lcd.print(DHT.temperature);
  } 
   delay(1000);
}
