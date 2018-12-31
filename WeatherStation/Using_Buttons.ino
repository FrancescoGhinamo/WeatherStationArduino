//used pins

#define DEBOUNCE_DELAY 10


/*
 * Keeps the program waiting until the state of a button has changed
 */
void waitForButtonStateChanged() {
  int prevState = digitalRead(buttonPin);
  int butState = 0;
  while((butState = digitalRead(buttonPin)) == prevState) {
    prevState = butState;
  }
}

/*
 * Keep the program waiting until a button is bumped
 */
void waitForBumpedButton() {
  //the button state has to change for two times
  waitForButtonStateChanged();
  //debounce delay
  delay(DEBOUNCE_DELAY);
  waitForButtonStateChanged();
}
