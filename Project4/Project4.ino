const int RED_PIN = 11;
const int BLUE_PIN = 10;
const int GREEN_PIN = 9;

const int POTENTIOMETER_PIN = A0;

void setup() {
  Serial.begin(9600);
  
  pinMode(RED_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
}

void digitalWriteRGB(byte red, byte blue, byte green) {
  digitalWrite(RED_PIN, red);
  digitalWrite(BLUE_PIN, blue);
  digitalWrite(GREEN_PIN, green);
}

void loop() {
  int potentiometerValue = analogRead(POTENTIOMETER_PIN);
  Serial.println(potentiometerValue);

  long mode = map(potentiometerValue, 0, 1023, 0, 6);

  switch (mode) {
    case 0:
      digitalWriteRGB(HIGH, LOW, LOW);
      break;
    case 1:
      digitalWriteRGB(LOW, HIGH, LOW);
      break;
    case 2:
      digitalWriteRGB(LOW, LOW, HIGH);
      break;
    case 3:
      digitalWriteRGB(HIGH, HIGH, LOW);
      break;
    case 4:
      digitalWriteRGB(HIGH, LOW, HIGH);
      break;
    case 5:
      digitalWriteRGB(LOW, HIGH, HIGH);
      break;
    case 6:
      digitalWriteRGB(HIGH, HIGH, HIGH);
      break;
    default:
      digitalWriteRGB(LOW, LOW, LOW);
      break;
  }
}
