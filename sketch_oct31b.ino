#include <Servo.h>

Servo slowServo2;

const int startAngle2 = 0;  
const int endAngle2 = 90;    
const long totalTime2 = 300000; 
const int totalSteps2 = 90; 

const long delayPerStep2 = totalTime2 / totalSteps2; 

void setup() {
  slowServo2.attach(10); 
  slowServo2.write(startAngle2); 
  Serial.begin(9600);
  Serial.println("300초 동안 90도 등속 이동 시작");
}

void loop() {
  for (int pos = startAngle2; pos <= endAngle2; pos += 1) {
    slowServo2.write(pos); 
    delay(delayPerStep2); 
  }
  
  while(true) {
    Serial.println("90도 등속 이동 완료.");
    delay(5000); 
  }
}
