#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define TRIGGERPIN D6
#define ECHOPIN    D7

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "Z5JS58MlIjcm-TYp8p9FG6-AVoGvWyy8";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "SmartPTI";
char pass[] = "SmartPT12017.";

WidgetLCD lcd(V1);

void setup()
{
  // Debug console
  Serial.begin(115200);
  pinMode(TRIGGERPIN, OUTPUT);
  pinMode(ECHOPIN, INPUT);

  Blynk.begin(auth, ssid, pass);

  lcd.clear();
  lcd.print(0, 0, "Distance (cm):");
}

void loop()
{
  lcd.clear();
  lcd.print(0, 0, "Distance (cm):"); // use: (position X: 0-15, position Y: 0-1, "Message you want to print")
  long duration, distance;
  digitalWrite(TRIGGERPIN, LOW);  
  delayMicroseconds(3); 
  
  digitalWrite(TRIGGERPIN, HIGH);
  delayMicroseconds(12); 
  
  digitalWrite(TRIGGERPIN, LOW);
  duration = pulseIn(ECHOPIN, HIGH);
  distance = (duration/2) / 29.1;
  Serial.print(distance);
  Serial.println("Cm");
  lcd.print(7, 1, distance);
  Blynk.run();

  delay(3500);
}
