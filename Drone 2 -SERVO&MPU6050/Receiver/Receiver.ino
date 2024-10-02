 
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
 #include<Servo.h>
#include "Wire.h"       
#include "I2Cdev.h"     
#include "MPU6050.h"   
 MPU6050 mpu;
 

 Servo motor1;
 Servo motor2;
 int Throttle; 

 int ax,ay,az,gx,gy,gz;
RF24 radio(9, 8);  
const byte address[6] = "00001";
void setup() 

{
  Wire.begin();
  mpu.initialize();
  while (!Serial);
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address); 
  radio.startListening();
motor1.attach(5);
motor2.attach(3);
 
}

void loop() { 

mpu.getMotion6(&ax, &ay, &az, &gx,  &gy,  &gz);
  //Serial.print("X:-->"); Serial.print(map(ax,-17000, 17000, 0, 255));
  Serial.print("Kordination Y:-->"); Serial.println(map(ay,-17000, 17000, 0, 255));
  //Serial.print("Z:-->"); Serial.println(map(az,-17000, 17000, 0, 255));
      delay(200);



  if (radio.available()) {   
     radio.read(&Throttle, sizeof(Throttle));
    Serial.print("Throttle :");
    Serial.println(Throttle);
    motor1.write(Throttle);
    motor2.write(Throttle);
     
  }

  else{
  Serial.println("No Connect");
  Throttle=0;
}
 
}