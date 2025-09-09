#define BLUE_PIN 7
#define RED_PIN 8
#define POTENTIOMETER_PIN A0

void setup() {
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(RED_PIN, OUTPUT);
}

void loop() {
  int reading = analogRead(POTENTIOMETER_PIN);
  int time = map(reading, 0, 1023, 10, 500);

  // turn on the red diode
  digitalWrite(RED_PIN, HIGH);
  delay(time);
  digitalWrite(RED_PIN, LOW);
  delay(time);
  digitalWrite(RED_PIN, HIGH);
  delay(time);
  digitalWrite(RED_PIN, LOW);
  delay(time);

  // turn on the blue diode
  digitalWrite(BLUE_PIN, HIGH);
  delay(time);
  digitalWrite(BLUE_PIN, LOW);
  delay(time);
  digitalWrite(BLUE_PIN, HIGH);
  delay(time);
  digitalWrite(BLUE_PIN, LOW);
  delay(time);
}
