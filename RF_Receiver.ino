/* Include these libraries*/
#include <RH_ASK.h>
#include <SPI.h> /* Not actually used but needed
to compile*/
/* Name the receiver*/
RH_ASK driver;
void setup(){
 /* Initiate the receiver*/
 Serial.begin(9600);
 if (!driver.init())
 Serial.println("init failed");
}
void loop(){
/* Receive and print message on Serial Monitor*/
 uint8_t buf[12];
 uint8_t buflen = sizeof(buf);
 if (driver.recv(buf, &buflen))/*Non-blocking*/
 {
 int i;
 Serial.print("Message: ");
 Serial.println((char*)buf);
 }
}
