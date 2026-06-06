#include <Servo.h>

Servo myservo;

// ---------------- PINS ----------------
const int Echo = A4;
const int Trig = A5;

const int LT_R = 10;
const int LT_M = 4;
const int LT_L = 2;

const int ENA = 5;
const int ENB = 6;
const int IN1 = 7;
const int IN2 = 8;
const int IN3 = 9;
const int IN4 = 11;

const int LEDR = 14;   // A0
const int LEDG = 15;   // A1
const int BUZZ = 18;   // A4 (be careful hardware wise)

// ---------------- SETTINGS ----------------
int carSpeed = 120;
int threshold = 40;

// ---------------- VARIABLES ----------------
int rightDistance = 0;
int leftDistance = 0;
int middleDistance = 0;

bool goRightPreference = true;

// ---------------- MOTOR CONTROL ----------------
void forward() {
  analogWrite(ENA, carSpeed);
  analogWrite(ENB, carSpeed);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void back() {
  analogWrite(ENA, carSpeed);
  analogWrite(ENB, carSpeed);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void left() {
  analogWrite(ENA, carSpeed);
  analogWrite(ENB, carSpeed);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void right() {
  analogWrite(ENA, carSpeed);
  analogWrite(ENB, carSpeed);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void stopCar() {
  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);
}

// ---------------- ULTRASONIC ----------------
int getDistance() {
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);

  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);

  long duration = pulseIn(Echo, HIGH, 30000);
  int distance = duration / 58;

  return distance;
}

// ---------------- SCAN ----------------
int scanLeft() {
  myservo.write(170);
  delay(400);
  return getDistance();
}

int scanRight() {
  myservo.write(10);
  delay(400);
  return getDistance();
}

void scanCenter() {
  myservo.write(90);
  delay(300);
}

// ---------------- SETUP ----------------
void setup() {
  Serial.begin(9600);

  pinMode(Echo, INPUT);
  pinMode(Trig, OUTPUT);

  pinMode(LT_R, INPUT);
  pinMode(LT_M, INPUT);
  pinMode(LT_L, INPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(BUZZ, OUTPUT);

  myservo.attach(3);
  myservo.write(90);

  stopCar();
}

// ---------------- MAIN LOOP ----------------
void loop() {

  scanCenter();
  middleDistance = getDistance();

  Serial.print("Distance: ");
  Serial.println(middleDistance);

  // ---------- OBSTACLE ----------
  if (middleDistance <= threshold && middleDistance > 0) {

    stopCar();
    digitalWrite(BUZZ, HIGH);
    digitalWrite(LEDR, HIGH);
    digitalWrite(LEDG, LOW);

    delay(300);

    rightDistance = scanRight();
    scanCenter();

    leftDistance = scanLeft();
    scanCenter();

    Serial.print("R: ");
    Serial.print(rightDistance);
    Serial.print(" | L: ");
    Serial.println(leftDistance);

    if (rightDistance > leftDistance) {
      right();
      delay(400);
      goRightPreference = true;
    }
    else {
      left();
      delay(400);
      goRightPreference = false;
    }

  }
  else {

    forward();

    digitalWrite(BUZZ, LOW);
    digitalWrite(LEDR, LOW);
    digitalWrite(LEDG, HIGH);
  }

}
