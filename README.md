# 🔗 Demo Online
Simulasi proyek ini dapat Anda lihat di:

 [Jalankan langsung di Wokwi](https://wokwi.com/projects/438782342050018305) <br>
 [Tonton tutorial di YouTube](https://www.youtube.com/@Ri.tonga24)

 # Sensor Parkir dengan LCD dan Buzzer

Proyek ini mengimplementasikan sistem sensor parkir menggunakan sensor ultrasonik HC-SR04, LED RGB, buzzer, dan LCD I2C. Sistem ini secara otomatis mendeteksi jarak kendaraan dan memberikan indikasi visual dan suara untuk membantu proses parkir.

---

## 📦 Komponen yang Dibutuhkan

- 1 × **Arduino Uno** atau kompatibel  
- 1 × **Sensor Ultrasonik HC-SR04**  
- 1 × **LED Merah**  
- 1 × **LED Kuning**  
- 1 × **LED Hijau**  
- 1 × **Buzzer**  
- 1 × **LCD 16x2 I2C**  
- Kabel jumper  

---

## 🔌 Skematik Rangkaian

Hubungkan komponen sesuai dengan skematik berikut:

- **Sensor Ultrasonik HC-SR04**:
  - VCC → 5V
  - GND → GND
  - TRIG → Pin 9
  - ECHO → Pin 8

- **LED**:
  - LED Merah → Pin 5
  - LED Kuning → Pin 4
  - LED Hijau → Pin 3

- **Buzzer**:
  - Buzzer → Pin 6

- **LCD I2C**:
  - SDA → A4
  - SCL → A5

---

## 🧑‍💻 Kode Arduino

```cpp
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
```

 ## 📷 **skema / rangkaian**

![Lampu RGB Arduino](https://github.com/Luddinritonga/Arduino-Sensor-Parkir/blob/main/skema.png)

## 🔧 **Cara Upload**
1. Sambungkan Arduino ke PC via kabel USB
2. Buka file `.ino` di Arduino IDE
3. Pilih board dan port yang sesuai
4. Upload kode ke Arduino




## 📫 Contact Me
[![Website](https://img.shields.io/badge/Website-000000?style=for-the-badge&logo=about-dot-me&logoColor=white)](https://luddinritonga.github.io/fortopolio/)
[![GitHub](https://img.shields.io/badge/GitHub-181717?style=for-the-badge&logo=github&logoColor=white)](https://github.com/luddinritonga)
[![Email](https://img.shields.io/badge/Email-D14836?style=for-the-badge&logo=gmail&logoColor=white)](mailto:luddinritonga03@gmail.com)
[![YouTube](https://img.shields.io/badge/YouTube-FF0000?style=for-the-badge&logo=youtube&logoColor=white)](https://www.youtube.com/@Ri.tonga24)
[![LinkedIn](https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/luddin-ritonga-727920307?)
