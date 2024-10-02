//Include Libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 8);


const byte address[6] = "00001";

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.stopListening();
}
void loop() {
  int Throttle;
  Throttle = analogRead(A1);
  Throttle = map(Throttle, 0, 1023, 0, 180);
  radio.write(&Throttle, sizeof(Throttle));




}