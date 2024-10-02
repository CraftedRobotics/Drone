 
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
 int Throttle; 
RF24 radio(9, 8);  
const byte address[6] = "00001";
void setup() {
  while (!Serial);
  Serial.begin(9600);
  radio.begin();
   radio.openReadingPipe(0, address); 
  radio.startListening();
}

void loop() { 

  if (radio.available()) {   
     radio.read(&Throttle, sizeof(Throttle));
    Serial.println(Throttle);

     
  }

  else{
  Serial.println("No Connect");
}
 
}