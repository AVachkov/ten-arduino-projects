//
// How fast are your reactions? In this final project, we will make a game
// where you have to release the button exactly when the middle LED lights up.
// If you succeed, you move to the next level. To start the game,
// press and hold the button. One by one, the LEDs will start blinking.
// Release exactly when the middle LED lights up.
// To advance to the next level, press and hold the button until all LEDs light up.
// If we make a mistake, we start over.
//

#define BTN_PIN 13
const int leds[5] = {3, 4, 5, 6, 7};

void setup() {
  Serial.begin(9600);

  pinMode(BTN_PIN, INPUT_PULLUP);
  for (byte i = 0; i < 5; i++)
    pinMode(leds[i], OUTPUT);
}

int counter = 0;
unsigned long prevMillis = millis();
long interval = 1000;

void loop() {
  unsigned long currentMillis = millis();

  if (digitalRead(BTN_PIN) == LOW) { // button pressed
    // Checks if the button is released while LED 3 is lit
    if (counter == 3) {
      for (byte i = 0; i < 5; i++)
        digitalWrite(leds[i], HIGH);

      delay(500);

      for (byte i = 0; i < 5; i++)
        digitalWrite(leds[i], LOW);

      counter = 0;
      interval /= 1.5; // Speed up the game (next level)
    }
    else {
      for (byte i = 0; i < 5; i++)
        digitalWrite(leds[i], LOW);

      delay(500);
      interval = 1000; // Reset to level 1
      counter = 0;
    }
  }

  if (currentMillis - prevMillis >= interval) {
    prevMillis = currentMillis;

    switch (counter) {
      case 0:
        digitalWrite(leds[4], LOW);
        digitalWrite(leds[0], HIGH);
        counter++;
        break;
      case 1:
        digitalWrite(leds[0], LOW);
        digitalWrite(leds[1], HIGH);
        counter++;
        break;
      case 2:
        digitalWrite(leds[1], LOW);
        digitalWrite(leds[2], HIGH);
        counter++;
        break;
      case 3:
        digitalWrite(leds[2], LOW);
        digitalWrite(leds[3], HIGH);
        counter++;
        break;
      case 4:
        digitalWrite(leds[3], LOW);
        digitalWrite(leds[4], HIGH);
        counter = 0;
        break;
    }
  }
}
