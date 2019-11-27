#include <Ultrasonic.h>

#define LED LED_BUILTIN
#define R D5
#define Y D1
#define G D3
#define DGR 100

#define TRG D6
#define ECHO D7

Ultrasonic ultrasonic(D6, D7); // (Trig, Echo)
long dist;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);
  
  pinMode(R, OUTPUT);
  pinMode(Y, OUTPUT);
  pinMode(G, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  dist = ultrasonic.Ranging(CM); // CM -> Centimetros | INC -> Polegadas
  Serial.println("Distância lida: " + String(dist) + "cm");

  if(dist > 40) {
    digitalWrite(R, LOW);
    digitalWrite(Y, LOW);
    digitalWrite(G, LOW);
  }else if(dist > 30){
    digitalWrite(R, LOW);
    digitalWrite(Y, LOW);
    digitalWrite(G, HIGH);
  }else if (dist > 20) {
    digitalWrite(R, LOW);
    digitalWrite(Y, HIGH);
    digitalWrite(G, HIGH);
  }else if (dist > 10){
    digitalWrite(R, HIGH);
    digitalWrite(Y, HIGH);
    digitalWrite(G, HIGH);
  }else {
    digitalWrite(R, HIGH);
    digitalWrite(Y, HIGH);
    digitalWrite(G, HIGH);
    delay(DGR);
    digitalWrite(R, LOW);
    digitalWrite(Y, LOW);
    digitalWrite(G, LOW);
    delay(DGR);
  }
}
