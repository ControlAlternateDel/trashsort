#include <Servo.h>
Servo trashL;
Servo trashR;
Servo d;

int servoRup = 135;
int servoRdown= 45;

int servoLup = 55;
int servoLdown= 180;

void setup() {
  trashL.attach(7);
  trashR.attach(5);
  d.attach(6);
  trashR.write(servoRup);
  trashL.write(servoLup);
  d.write(90);
  Serial.begin(9600);
  delay(1000);
  Serial.println("bro let me go home you stupid computer");
}

void loop() {  // keep centered

  if (Serial.available()) {
    char cmd = Serial.read();

    if (cmd == 100) {
      Serial.println("dry");
      d.write(135);
      delay(1000);
      d.write(90);
    }
    else if (cmd == 119){
      Serial.println("wet");
      d.write(45);
      delay(1000);
      d.write(90);
    }
    else if (cmd == 101){
      d.write(90);
      delay(1000);
      d.write(90);
    }
    else {
      d.write(90);
    }
    while(Serial.available()) Serial.read();
  }
  delay(200);
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