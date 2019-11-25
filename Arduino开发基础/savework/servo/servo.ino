#include <Servo.h>    // 声明调用Servo.h库
#define SERVO_PIN 9    // 舵机对象使用9脚进行控制
Servo myservo;        // 创建一个舵机对象

void setup() {
  // put your setup code here, to run once:
  myservo.attach(SERVO_PIN); 
}

void loop() {
  // put your main code here, to run repeatedly:
 myservo.write(0);
 delay(5000);     
 myservo.write(90);
 delay(5000);
 myservo.write(180); 
 delay(5000);
}
