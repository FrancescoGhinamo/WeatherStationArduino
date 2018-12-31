/*
 * Reads the value of the light sensor, mapped and constrained in a value between 0 and 100
 */

 int readLightSensorConstrained() {
  int readValue = analogRead(lightSensorPin);
  int parseValue = map(readValue, 0, 1023, 0, 100);
  return constrain(parseValue, 0, 100);
 }
