#define LED_PIN 4
#define SPEAKER_PIN 13
#define PHOTO_PIN A5

unsigned long openedAt = 0;
bool alerting = false;
unsigned long lastBlink = 0;

int main() {
  init();

  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  pinMode(SPEAKER_PIN, OUTPUT);
  pinMode(PHOTO_PIN, INPUT);

  while (true) {
    int lightReading = analogRead(PHOTO_PIN);

    Serial.println(lightReading);

    if (lightReading > 500) { // fridge opened
      if (openedAt == 0)
        openedAt = millis(); // start timer

      if (millis() - openedAt >= 30000)
        alerting = true;
    }
    else { // fridge closed
      alerting = false;
      openedAt = 0;
      digitalWrite(LED_PIN, LOW);
      digitalWrite(SPEAKER_PIN, LOW);
    }

    // Blink LED and speaker if alerting
    if (alerting) {
      if (millis() - lastBlink >= 200) { // 200ms toggle
        lastBlink = millis();
        digitalWrite(LED_PIN, !digitalRead(LED_PIN));
        digitalWrite(SPEAKER_PIN, !digitalRead(SPEAKER_PIN));
      }
    }
  }
}