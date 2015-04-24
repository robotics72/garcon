
#include <IRremote.h>

#define BEACON_PASS 0xAC
#define BEACON_ID 0x01

IRsend irsend;
int t;

void setup()
{
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);  
  t = 0;
}

void loop() {
 irsend.sendSony((BEACON_PASS << 8) | BEACON_ID, 16); // Sony TV power code
 delay(100);
 t++;
 if (t == 30){
   digitalWrite(13, HIGH);
 }
 if (t == 33){
   digitalWrite(13, LOW);
   t = 0;
 }   
}


