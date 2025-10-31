// 300초 동안 90도 등속 이동 (속도: 약 0.3도/초)
#include <Servo.h>

Servo slowServo2; // 두 번째 서보 객체 생성

// 저속 구동을 위한 변수 설정
const int startAngle2 = 0;   // 시작 각도
const int endAngle2 = 90;    // 목표 각도
const long totalTime2 = 300000; // 총 이동 시간 (300초 = 300000ms)
const int totalSteps2 = 90; // 이동 단계 수 (1도당 1단계로 설정하여 부드럽게)

// 단계당 시간 간격 (ms) 계산: 300000ms / 90단계 = 약 3333.3ms
const long delayPerStep2 = totalTime2 / totalSteps2; 

void setup() {
  slowServo2.attach(10); // 서보 모터를 10번 핀에 연결
  slowServo2.write(startAngle2); // 시작 각도로 초기 설정
  Serial.begin(9600);
  Serial.println("300초 동안 90도 등속 이동 시작");
}

void loop() {
  // 등속 이동 로직
  for (int pos = startAngle2; pos <= endAngle2; pos += 1) { // 1도씩 증가
    slowServo2.write(pos); 
    // 계산된 시간 간격만큼 대기
    delay(delayPerStep2); 
  }
  
  // 이동 완료 후, 더 이상 움직이지 않도록 loop 함수를 빠져나가지 않음
  while(true) {
    // 이동 완료
    Serial.println("90도 등속 이동 완료.");
    delay(5000); // 5초 대기 후 다시 출력
  }
}
