// 60초 동안 180도 등속 이동 (속도: 약 3도/초)
#include <Servo.h>

Servo slowServo1; // 첫 번째 서보 객체 생성

// 저속 구동을 위한 변수 설정
const int startAngle1 = 0;   // 시작 각도
const int endAngle1 = 180;   // 목표 각도
const long totalTime1 = 60000; // 총 이동 시간 (60초 = 60000ms)
const int totalSteps1 = 180; // 이동 단계 수 (1도당 1단계로 설정하여 부드럽게)

// 단계당 시간 간격 (ms) 계산: 60000ms / 180단계 = 약 333.3ms
const long delayPerStep1 = totalTime1 / totalSteps1; 

void setup() {
  slowServo1.attach(10); // 서보 모터를 10번 핀에 연결
  slowServo1.write(startAngle1); // 시작 각도로 초기 설정
  Serial.begin(9600);
  Serial.println("60초 동안 180도 등속 이동 시작");
}

void loop() {
  // 등속 이동 로직
  for (int pos = startAngle1; pos <= endAngle1; pos += 1) { // 1도씩 증가
    slowServo1.write(pos); 
    // 계산된 시간 간격만큼 대기
    delay(delayPerStep1); 
  }
  
  // 이동 완료 후, 더 이상 움직이지 않도록 loop 함수를 빠져나가지 않음
  while(true) {
    // 이동 완료
    Serial.println("180도 등속 이동 완료.");
    delay(5000); // 5초 대기 후 다시 출력 (혹은 break; 로 빠져나가서 더 이상 실행되지 않도록 할 수 있음)
  }
}
