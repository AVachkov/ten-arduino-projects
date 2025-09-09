//
// Колко бързи са вашите реакции? В този финален проект ще направим игра,
// в която трябва да пуснем бутона точно когато светне средният светодиод.
// Ако успеете, ще преминете към следващото ниво. За да започнем играта,
// трябва да натиснем и задържим бутона. Един по един, светодиодите ще 
// започнат да примигват. Пускаме точно когато светне средният сетодиод.
// За да преминете към следващото ниво, натискаме и задържаме бутона, 
// докато всички светодиоди светят. Ако направим грешка, започваме от начало.
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

  if (digitalRead(BTN_PIN) == LOW) { // btn pressed
    // Проверява дали бутона е пуснат, докато свети светодиод 3
    if (counter == 3) {
      for (byte i = 0; i < 5; i++)
        digitalWrite(leds[i], HIGH);

      delay(500);

      for (byte i = 0; i < 5; i++)
        digitalWrite(leds[i], LOW);

      counter = 0;
      interval /= 1.5; // Забързване на играта (следващо ниво)
    }
    else {
      for (byte i = 0; i < 5; i++)
        digitalWrite(leds[i], LOW);

      delay(500);
      interval = 1000; // Отново преминаваме на ниво 1.
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
