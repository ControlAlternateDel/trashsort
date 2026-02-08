//pins
#define IR1 2
#define IR2 3
#define IR3 4
#define IR4 5
#define IR5 6
#define IR6 7
#define IR7 8
#define IR8 9
#define RFWD 10
#define RBWD 11
#define LBWD 12
#define LFWD 13

void setup() {
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  pinMode(IR3, INPUT);
  pinMode(IR4, INPUT);
  pinMode(IR5, INPUT);
  pinMode(IR6, INPUT);
  pinMode(IR7, INPUT);
  pinMode(IR8, INPUT);
  pinMode(RFWD, OUTPUT);
  pinMode(RBWD, OUTPUT);
  pinMode(LBWD, OUTPUT);
  pinMode(LFWD, OUTPUT);
}


void loop() {
  int s1 = digitalRead(IR1);
  int s2 = digitalRead(IR2);
  int s3 = digitalRead(IR3);
  int s4 = digitalRead(IR4);
  int s5 = digitalRead(IR5);
  int s6 = digitalRead(IR6);
  int s7 = digitalRead(IR7);
  int s8 = digitalRead(IR8);

  if ((s6==HIGH) || (s5==HIGH)){
  digitalWrite(RFWD, HIGH);
  digitalWrite(RBWD, LOW);
  digitalWrite(LBWD, LOW);
  digitalWrite(LFWD, HIGH);
  }
  else if((s6==HIGH) && (s7==HIGH)&&(s8==HIGH)&&(s1==LOW)&&(s2==LOW)&&(s3==LOW)){
  digitalWrite(RFWD, HIGH);
  digitalWrite(RBWD, LOW);
  digitalWrite(LBWD, HIGH);
  digitalWrite(LFWD, LOW);
  }
  else if ((s3==HIGH)&&(s2==HIGH)&&(s1==HIGH)&&(s6==LOW)&&(s7==LOW)&&(s8==LOW)){
  digitalWrite(RFWD, LOW);
  digitalWrite(RBWD, HIGH);
  digitalWrite(LBWD, HIGH);
  digitalWrite(LFWD, LOW);
  }
  else {
    digitalWrite(RFWD, LOW);
  digitalWrite(RBWD, LOW);
  digitalWrite(LBWD, LOW);
  digitalWrite(LFWD, LOW);
  }

  }