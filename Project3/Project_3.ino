const int LED_PIN = 13;
const int PHOTO_PIN = A0;
const int TRESHOLD = 300;

void setup() {
  Serial.begin(9600);
  
  pinMode(LED_PIN, OUTPUT);
  pinMode(PHOTO_PIN, INPUT);
}

void loop() {
  int photoStatus = analogRead(PHOTO_PIN);
  // read the analog input from the photoresistor
  // we get the input as a number in range from 0 - 1023
  // !!! 0 is really dark and 1023 is really bright !!!

  Serial.println(photoStatus);

  if (photoStatus < TRESHOLD)
    digitalWrite(LED_PIN, HIGH);
  else
    digitalWrite(LED_PIN, LOW);

}
