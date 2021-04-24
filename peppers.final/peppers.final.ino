#include <pcmConfig.h>
#include <pcmRF.h>
#include <TMRpcm.h>
#include <SD.h>                      // need to include the SD library
#define SD_ChipSelectPin 4  //example uses hardware SS pin 53 on Mega2560
//#define SD_ChipSelectPin 10  //using digital pin 4 on arduino nano 328
#include <TMRpcm.h>           //  also need to include this library...
#include <SPI.h>

#include <Servo.h>

TMRpcm tmrpcm;   // create an object for use in this sketch
char mychar;

Servo myServo;

void setup() { 
    tmrpcm.speakerPin = 5; //11 on Mega, 9 on Uno, Nano, etc

  Serial.begin(9600);
  if (!SD.begin(SD_ChipSelectPin)) {  // see if the card is present and can be initialized:
    Serial.println("SD fail");  
    return;   // don't do anything more if not
  }
  tmrpcm.setVolume(5);
  tmrpcm.play("COSTAL~3.wav"); //the sound file "music" will play each time the arduino powers up, or is reset
  
  myServo.attach(9);
  myServo.writeMicroseconds(1500);
  delay(49600);
  myServo.detach();
} 

void loop() { }


