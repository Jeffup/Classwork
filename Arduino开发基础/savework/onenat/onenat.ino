//修改要上传的数据为温度和湿度在http函数中
#include <Adafruit_CC3000.h>
#include <ccspi.h>
#include <SPI.h>
#define Wido_IRQ   7
#define Wido_VBAT  5
#define Wido_CS    10

#include <dht11.h>
#define DHT11_PIN 4
dht11 DHT;

Adafruit_CC3000 Wido = 
Adafruit_CC3000(Wido_CS, Wido_IRQ,
Wido_VBAT,SPI_CLOCK_DIVIDER);

#define WLAN_SSID       "NX563J"           
// cannot be longer than 32 characters!
#define WLAN_PASS       "xxaq1701"

// WLAN_SEC_UNSEC, WLAN_SEC_WEP, WLAN_SEC_WPA or WLAN_SEC_WPA2
#define WLAN_SECURITY   WLAN_SEC_WPA2
#define TCP_TIMEOUT  3000

#define API_key  "E9v278TKtT7s9PWI=gTGB0PBkDw="
#define Hardware_key "528111056"

void setup() {
  Serial.begin(115200);
  pinMode(13,OUTPUT);
  delay(5000);
  Serial.println(F("Hello, CC3000!\n"));
  if (!Wido.begin())  
  {
    Serial.println(F("Unable to initialise the CC3000! Check your wiring?"));
    while(1);
  }
  if (!Wido.connectToAP(WLAN_SSID, WLAN_PASS,
          WLAN_SECURITY))  
   {
     Serial.println(F("Failed!"));
     while(1);
   }
  while (!Wido.checkDHCP())  {
    delay(100); // DHCP timeout!
  }
}

uint32_t ip = 0;
Adafruit_CC3000_Client httpLink; 
unsigned long RetryMillis = 0;           
unsigned long uploadtStamp = 0;
unsigned long rTimer;

void loop() {
  // put your main code here, to run repeatedly:
  loopHttpLink();  //数据上传
}

void loopHttpLink()
{
  if(!httpLink.connected()){
    if(millis() - RetryMillis > TCP_TIMEOUT){
       RetryMillis = millis();
       Serial.println(F("Try cloud server"));
       httpLink.close();
       uint32_t ip = Wido.IP2U32(183, 230, 40, 33);
       httpLink = Wido.connectTCP(ip, 80);
    }
  }  else  {
    if(millis() - uploadtStamp > 2000){
      uploadtStamp = millis();
      int chk;
      chk = DHT.read(DHT11_PIN);
      sendPostStr(8);
      if(chk== DHTLIB_OK){
      sendPostStr(DHT.temperature);  //发送温度数据
      sendPostStr(DHT.humidity);     //发送湿度数据
      }
      else
      {
        sendPostStr(8);
       }
      bool bAct=true;
      GetHttpAns();
      delay(1000);      //延时1秒再监测发送
   } 
 }
}

void sendPostStr(int ival)
{
    char valStr[200];
    char xStr[30];
    int iLen;
    sprintf(valStr,"POST /devices/%s/datapoints HTTP/1.1",Hardware_key);    
    httpLink.fastrprintln(valStr);  
    sprintf(valStr,"api-key: %s",API_key);    
    httpLink.fastrprintln(valStr);       
    httpLink.fastrprintln("Host:api.heclouds.com");
    sprintf(valStr,"{\"datastreams\":[{\"id\":\"sys_time\",\"datapoints\":[{\"value\":%d}]}]}",ival);
    iLen=strlen(valStr);
    sprintf(xStr,"Content-Length:%d",iLen);
    httpLink.fastrprintln(xStr);
    httpLink.fastrprintln("");
    httpLink.fastrprintln(valStr);
}

void GetHttpAns(){
   unsigned long rTimer = millis();
   int count=0;
      while (millis() - rTimer < 2000) {
          while (httpLink.available()) {
            char c = httpLink.read();
            Serial.print(c);
      count++;
          }
    }    
   if(count==0)      
    httpLink.close();      
}


