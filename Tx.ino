
#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
int msg[1];
RF24 radio(9,10);
const uint64_t pipe = 0xE8E8F0F0E1LL;
int SW1 = 7;

void setup(void){
  Serial.begin(9600);
  Serial.println("Startup Tx!");
  radio.begin();
  radio.openWritingPipe(pipe);
}

void loop(void){
   int i;
   for (i=0; i< 255; i++) {
     msg[0] = i;
     radio.write(msg, 1);
   }
}

