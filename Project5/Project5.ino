#define LED_PIN 10
#define BUTTON_PIN 2
#define POTENTIOMETER_PIN A0

bool LEDon = true; // toggle state
byte lastButtonState = LOW; // track last debounced button state
int consecutiveReads = 0; // count consistent HIGH reads
const int requiredReads = 3; // number of consistent reads to accept press

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT); // regular wiring
  pinMode(POTENTIOMETER_PIN, INPUT);
}

void loop() {
  byte reading = digitalRead(BUTTON_PIN);

  // count consecutive HIGH reads
  if (reading == HIGH) {
    consecutiveReads++;
    if (consecutiveReads >= requiredReads && lastButtonState == LOW) {
      LEDon = !LEDon; // toggle LED
      lastButtonState = HIGH;
      consecutiveReads = 0;
    }
  } else {
    lastButtonState = LOW; // reset state when button released
    consecutiveReads = 0;
  }

  // LED brightness
  if (LEDon) {
    int potValue = analogRead(POTENTIOMETER_PIN);
    Serial.println(potValue);

    int brightness = map(potValue, 0, 1023, 0, 255);
    analogWrite(LED_PIN, brightness);
  } else {
    analogWrite(LED_PIN, 0);
  }
}
