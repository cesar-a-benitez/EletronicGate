#include <Ultrasonic.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define BLYNK_PRINT Serial
#define LED LED_BUILTIN
#define R D5
#define Y D1
#define G D3

#define TRG  D6
#define ECHO D7

Ultrasonic ultrasonic(TRG, ECHO); // (Trig, Echo)
long dist;

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "Z5JS58MlIjcm-TYp8p9FG6-AVoGvWyy8";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "SmartPTI";
char pass[] = "SmartPT12017.";

WidgetLCD lcd(V1);
WidgetLED r(V5);
WidgetLED y(V6);
WidgetLED g(V7);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
    
  pinMode(LED, OUTPUT);
  pinMode(R, OUTPUT);
  pinMode(Y, OUTPUT);
  pinMode(G, OUTPUT);



  digitalWrite(LED, HIGH);

  lcd.clear();
  lcd.print(0, 0, "Distância:");
}

void loop() {
  lcd.clear();
  lcd.print(0, 0, "Distância:"); // use: (position X: 0-15, position Y: 0-1, "Message you want to print")
  
  dist = ultrasonic.Ranging(CM); // CM -> Centimetros | INC -> Polegadas
  Serial.println("Distância lida: " + String(dist) + "cm");

  if(dist > 35) {
    digitalWrite(R, LOW);
    digitalWrite(Y, LOW);
    digitalWrite(G, LOW);
    r.off();
    y.off();
    g.off();
  }else if(dist > 25){
    digitalWrite(R, LOW);
    digitalWrite(Y, LOW);
    digitalWrite(G, HIGH);
    r.off();
    y.off();
    g.on();
  }else if (dist > 15) {
    digitalWrite(R, LOW);
    digitalWrite(Y, HIGH);
    digitalWrite(G, HIGH);
    r.off();
    y.on();
    g.on();
  }else {
    digitalWrite(R, HIGH);
    digitalWrite(Y, HIGH);
    digitalWrite(G, HIGH);
    r.on();
    y.on();
    g.on();
  }

  lcd.print(7, 1, String(dist) + "cm");
  Blynk.run();
  delay(500);
}
