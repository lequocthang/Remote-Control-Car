#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "9e7c7d52c5a5470e8731888ae1ae440a";

// Your WiFi credentials.
// Set password to "ChiNa" for open networks.
char ssid[] = "ChiNa";
char pass[] = "12345678";
//int led = 13;
//unsigned long timem = 0;
//unsigned long delayTime = 1000; //Thời gian delay (không dùng hàm delay)
//Direction forward
 BLYNK_WRITE(V1)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
    if(pinValue==1){
    Serial.println('f');}
else if(pinValue==0){Serial.println('e');}
 
  //Serial.println(pinValue);
}
//Direction BACKWARD
 BLYNK_WRITE(V2)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
    if(pinValue==1){
    Serial.println('b');}
else if(pinValue==0){Serial.println('e');}
 
  //Serial.println(pinValue);
}
//Direction right
 BLYNK_WRITE(V3)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
    if(pinValue==1){
    Serial.println('r');}
else if(pinValue==0){Serial.println('e');}
 
  //Serial.println(pinValue);
}
//Direction left
 BLYNK_WRITE(V4)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
    if(pinValue==1){
    Serial.println('l');}
else if(pinValue==0){Serial.println('e');}
 
  //Serial.println(pinValue);
}
 BLYNK_WRITE(V5)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  if(pinValue<201){ 
  Serial.println('0');}
  else{ Serial.println('1');}
}
void setup() {
  
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);

}
 
 
void loop() {
   Blynk.run();
}

