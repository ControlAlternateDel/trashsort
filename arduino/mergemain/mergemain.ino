#include <Servo.h>

#define TRIG_PIN_DRY A4
#define ECHO_PIN_DRY A5
#define TRIG_PIN_WET 2
#define ECHO_PIN_WET 3

Servo trashL;
Servo trashR;
Servo d;

int servoRup = 135;
int servoRdown= 45;

int servoLup = 60;
int servoLdown= 180;

void setup() {
  trashL.attach(7);
  trashR.attach(5);

  pinMode(TRIG_PIN_DRY, OUTPUT);
  pinMode(ECHO_PIN_DRY, INPUT);
  pinMode(TRIG_PIN_WET, OUTPUT);
  pinMode(ECHO_PIN_WET, INPUT);
  Serial.begin(9600);

  d.attach(6);
  trashR.write(servoRup);
  trashL.write(servoLup);
  d.write(90);

}

void loop() {
  // Send trigger pulse
  digitalWrite(TRIG_PIN_DRY, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN_DRY, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN_DRY, LOW);

  long durationDry = pulseIn(ECHO_PIN_DRY, HIGH);

  digitalWrite(TRIG_PIN_WET, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN_WET, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN_WET, LOW);

  long durationWet = pulseIn(ECHO_PIN_WET, HIGH);

  // Calculate distance (cm)
  float distance_cm_dry = durationDry * 0.0343 / 2;
  float distance_cm_wet = durationWet * 0.0343 / 2;

  Serial.println("Dry: " + String(distance_cm_dry));  // send as text
  Serial.println("Wet: " + String(distance_cm_wet));
  if (distance_cm_dry < 8.05) {
    leftOpen();
    delay(5000);
    leftClose();
  }
  if (distance_cm_wet < 8.05) {
    rightOpen();
    delay(5000);
    rightClose();
  }
  delay(500);
}

void rightOpen(){
  trashR.write(servoRdown);
}


void rightClose(){
  trashR.write(servoRup);
}


void leftOpen(){
  trashL.write(servoLdown);
}


void leftClose(){
  trashL.write(servoLup);
}