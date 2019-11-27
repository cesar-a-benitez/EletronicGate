#include <Ultrasonic.h>

#define LED LED_BUILTIN

Ultrasonic ultrasonic(D6, D7); // (Trig, Echo)
long dist;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  dist = ultrasonic.Ranging(CM); // CM -> Centimetros | INC -> Polegadas
  Serial.println("Distância lida: " + String(dist) + "cm");
  
  if(dist >= 50) {
    digitalWrite(LED, HIGH);
    delay(100);
  }else {
      int sleep = dist * 10;

      delay(sleep);
      digitalWrite(LED, HIGH);
      delay(sleep);
      digitalWrite(LED, LOW);
  }
}
