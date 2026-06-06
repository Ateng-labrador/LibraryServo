#include "MyServoESP32.h"

MyServoESP32 myServo;

// parameter
static const int servoPin = 4;
static const int trig = 32;
static const int echo = 26;
float duration;
long long distance;


// setting awal
void setup() {
  Serial.begin(115200);
  pinMode(trig, OUTPUT);
  pinMode(echo, OUTPUT);
  myServo.attach(servoPin);
  myServo.write(0);
}

// looping
void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);

  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);
  distance = (duration * 0.0343) / 2.0;

  if(distance < 14){
    myServo.write(180);
  }
  if(distance > 14.5){
    myServo.write(0);
  }

  Serial.print(distance);
  Serial.println(" ");
  delay(20);
}
