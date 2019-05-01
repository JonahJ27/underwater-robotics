#include <Servo.h>

int inByte;
int currentServo = 2; // changes based on values sent over serial
Servo myservos[24];  // create servo object to control a servo

void setup() {
  for (int x = 2; x <= 13; x++) {
    pinMode(x, OUTPUT);
  }

  digitalWrite(12, HIGH); // Direction pin for A
  digitalWrite(13, HIGH); // Direction pin for B
  
  for (int x = 2; x <= 11; x++) {
    myservos[x - 2].attach(x);  // attaches the servo on pin 9 to the servo object
//    if (!block(x)) {
//      myservos[x - 2].attach(x);  // attaches the servo on pin 9 to the servo object
//    }
  }

  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    inByte = Serial.read();
    if (inByte >= 182 && inByte < 192) { // if it's a reasonable servo value
      inByte -= 180;
      currentServo = inByte;
//      if(!block(inByte)) {
//        Serial.println(currentServo);
//      }
    } else if(inByte <= 180) {
      myservos[currentServo - 2].write(inByte);
//      Serial.print(currentServo);
//      Serial.print('\t');
//      Serial.println(inByte);
    }
  }
}

//bool block(int pin) { // special pins for motor shield
//  return (pin == 12 || pin == 13);
//}
