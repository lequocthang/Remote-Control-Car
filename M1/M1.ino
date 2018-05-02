#include <SerialCommand.h>
#include <SoftwareSerial.h>
#include <AFMotor.h>
 
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

SerialCommand sCmd;

char sign;
int td;
void setup() {
  Serial1.begin(115200);
  Serial.begin(9600);
 
  
  motor1.setSpeed(255);     // ch?n t?c d? maximum 255`/255
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);
  
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}
void loop() {
  if(Serial1.available()>0) {
    while(Serial1.available()>0){
      sign = Serial1.read();
      
      Serial.println(sign);
      switch(sign){
        case '0': td=200;
        case '1': td=255;
        case 'f': forward();
        break;
        case 'b': backward();
        break;
        case 'r': right();
        break;
        case 'l': left();
        break;
        case 'e': rele();
      }
    }
    
  }
 }
 //DIRECTION FORWARD
 void forward() {
  setspeed(td);
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}
//DIRECTION BACKWARD
void backward() {
  setspeed(td);
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}
//DIRECTION RIGHT
void right() {
  motor3.setSpeed(225);
  motor2.setSpeed(225);
  motor1.setSpeed(60);
  motor4.setSpeed(60);
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(BACKWARD);
}
//DIRECTION LEFT
void left() {
  motor3.setSpeed(60);
  motor2.setSpeed(60);
  motor1.setSpeed(225);
  motor4.setSpeed(225);
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}
//DIRECTION RELEASE
void rele() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}
//SET SPEED
void setspeed(int sp){
  motor1.setSpeed(sp);     // ch?n t?c d? maximum 255`/255
  motor2.setSpeed(sp);
  motor3.setSpeed(sp);
  motor4.setSpeed(sp);
  
}


