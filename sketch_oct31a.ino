#include <Servo.h>

Servo slowServo1;

const int startAngle1 = 0;   
const int endAngle1 = 180;   
const long totalTime1 = 60000;
const int totalSteps1 = 180;

const long delayPerStep1 = totalTime1 / totalSteps1; 

void setup() {
  slowServo1.attach(10);
  slowServo1.write(startAngle1);
  Serial.begin(9600);
  Serial.println("60초 동안 180도 등속 이동 시작");
}

void loop() {
  for (int pos = startAngle1; pos <= endAngle1; pos += 1) { 
    slowServo1.write(pos); 
    delay(delayPerStep1); 
  }
  
  while(true) {
    Serial.println("180도 등속 이동 완료.");
    delay(5000);
  }
}
