/* Include these libraries*/
#include <RH_ASK.h>
#include <SPI.h>
/* Name the transmitter*/
RH_ASK driver;
void setup()
{
 /* Initiate the transmitter*/
 Serial.begin(9600);
 if (!driver.init())
 Serial.println("init failed");
}
void loop()
{
 /* Set and send message*/
 const char *msg = "Hello World!";
 driver.send((uint8_t *)msg,
strlen(msg));
 driver.waitPacketSent();
 delay(1000);
}
