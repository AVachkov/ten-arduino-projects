#define LED_PIN 10
#define BUTTON_DECREASE_PIN 4
#define BUTTON_INCREASE_PIN 2

int lastState1 = HIGH; // last state of decrease button
int lastState2 = HIGH; // last state of increase button
int fadeValue = 0;     // LED brightness 0-255

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_DECREASE_PIN, INPUT_PULLUP);
  pinMode(BUTTON_INCREASE_PIN, INPUT_PULLUP);
}

void loop() {
  int currentState1 = digitalRead(BUTTON_DECREASE_PIN);
  int currentState2 = digitalRead(BUTTON_INCREASE_PIN);

  // Button pressed = LOW because of INPUT_PULLUP
  if (currentState1 == LOW && lastState1 == HIGH) { // decrease pressed
    fadeValue -= 32; // adjust step as needed
    if (fadeValue < 0) fadeValue = 0; // limit min
  }

  if (currentState2 == LOW && lastState2 == HIGH) { // increase pressed
    fadeValue += 32; // adjust step as needed
    if (fadeValue > 255) fadeValue = 255; // limit max
  }

  lastState1 = currentState1; // save last state
  lastState2 = currentState2;

  analogWrite(LED_PIN, fadeValue); // set LED brightness

  Serial.print("Fade value: ");
  Serial.println(fadeValue);

  delay(50); // simple debounce, adjust as needed
}