#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int trigPin = 9;
const int echoPin = 8;
const int ledMerah = 5;
const int ledKuning = 4;
const int ledHijau = 3;
const int buzzer = 6;

long duration;
int distance;

void setup() {
  lcd.init();
  lcd.backlight();

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledMerah, OUTPUT);
  pinMode(ledKuning, OUTPUT);
  pinMode(ledHijau, OUTPUT);
  pinMode(buzzer, OUTPUT);

  lcd.setCursor(0, 0);
  lcd.print("Sensor Parkir");
}

void loop() {
  // Baca jarak dari HC-SR04
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  // Tampilkan di LCD
  lcd.setCursor(0, 1);
  lcd.print("Jarak: ");
  lcd.print(distance);
  lcd.print(" cm   ");

  // Logika LED dan Buzzer
  if (distance <= 10) {
    digitalWrite(ledMerah, HIGH);
    digitalWrite(ledKuning, LOW);
    digitalWrite(ledHijau, LOW);
    tone(buzzer, 1000); // bunyi terus
  }
  else if (distance <= 30) {
    digitalWrite(ledMerah, LOW);
    digitalWrite(ledKuning, HIGH);
    digitalWrite(ledHijau, LOW);
    tone(buzzer, 1000);
    delay(200);
    noTone(buzzer);
  }
  else if (distance <= 40) {
    digitalWrite(ledMerah, LOW);
    digitalWrite(ledKuning, LOW);
    digitalWrite(ledHijau, HIGH);
    tone(buzzer, 1000);
    delay(500);
    noTone(buzzer);
  }
  else {
    digitalWrite(ledMerah, LOW);
    digitalWrite(ledKuning, LOW);
    digitalWrite(ledHijau, HIGH);
    noTone(buzzer);
  }
}
