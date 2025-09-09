#define LED_COUNT 4
#define BTN_PIN 2
const int ledPins[LED_COUNT] = {13, 12, 11, 10};

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < LED_COUNT; i++)
    pinMode(ledPins[i], OUTPUT);

    pinMode(BTN_PIN, INPUT_PULLUP);
}

int idx = 0;
int prevLed;
int lastBtnState = HIGH;

void loop() {
  int btnState = digitalRead(BTN_PIN);

  if (btnState == LOW && lastBtnState == HIGH) { // button is pressed (because of INPUT_PULLUP)
    digitalWrite(ledPins[idx], HIGH);
    prevLed = ledPins[(idx - 1 + LED_COUNT) % LED_COUNT];
    digitalWrite(prevLed, LOW);

    idx = (idx + 1) % LED_COUNT;
  }

  lastBtnState = btnState;
}
