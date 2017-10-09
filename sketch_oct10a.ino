const int buttonPin = 2;
int numberOfPress = 0;
int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  // Interrupts can happen on "edges" of signals.
  Serial.begin(9600);
}

void loop() {
  for (int i = 0; i < 100; i++) {
    int reading = digitalRead(buttonPin);
    if (reading != lastButtonState) {
      // reset the debouncing timer
      lastDebounceTime = millis();
    }
    if (millis() > debounceDelay) {
      // whatever the reading is at, it's been there for longer than the debounce
      // delay, so take it as the actual current state:

      // if the button state has changed:
      if (reading != buttonState) {
        buttonState = reading;
      }
      Serial.println(i - 30);
      if (buttonState == LOW) {
        Serial.println("interrupt");
      }
      delay(1000);
    }

  }
}
