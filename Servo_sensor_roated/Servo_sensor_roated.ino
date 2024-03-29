#include <Servo.h>

#define sensorPin 7

Servo myservo;

void setup() {
  Serial.begin(9600);
  myservo.attach(8);
  pinMode(sensorPin, INPUT);
}

void loop() {
  int sensorValue = digitalRead(sensorPin);
  Serial.println(sensorValue);
    
  if(sensorValue == LOW){ // Object detected
    delay(500);
    moveServo(80); // Move servo to 80 degrees
    delay(1000);
  }
  else { // No object detected
    moveServo(0); // Move servo back to 0 degrees
    delay(100);
  } 
}

void moveServo(int angle) {
  int currentPosition = myservo.read();
  if (currentPosition < angle) {
    for (int pos = currentPosition; pos <= angle; pos += 1) {
      myservo.write(pos);
      delay(8);
    }
  }
  else if (currentPosition > angle) {
    for (int pos = currentPosition; pos >= angle; pos -= 1) {
      myservo.write(pos);
      delay(8);
    }
  }
}
