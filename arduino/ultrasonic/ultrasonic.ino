#define TRIG_PIN_DRY A4
#define ECHO_PIN_DRY A5
#define TRIG_PIN_WET 2
#define ECHO_PIN_WET 3

void setup() {
  pinMode(TRIG_PIN_DRY, OUTPUT);
  pinMode(ECHO_PIN_DRY, INPUT);
  pinMode(TRIG_PIN_WET, OUTPUT);
  pinMode(ECHO_PIN_WET, INPUT);
  Serial.begin(19200);
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
  delay(500);
  
}

