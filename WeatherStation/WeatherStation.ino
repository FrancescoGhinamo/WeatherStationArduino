#include <LiquidCrystal.h>
#define STABILITY_DELAY 100

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


//used pins
const int buttonPin = 8;

const int lightSensorPin = A5;

void setup() {
  //beginning lcd output
  lcd.begin(16, 2);

  //beginning serial communication with pc
  Serial.begin(9600);

  //setting pin modes
  pinMode(buttonPin, INPUT);
  pinMode(lightSensorPin, INPUT);
  

}

void loop() {
  lcd.clear();
  lcd.write("Weather");
  lcd.setCursor(0, 1);
  lcd.write("Station");
  waitForBumpedButton();
  displayTemperature();
  waitForBumpedButton();
  displayPressure();
  waitForBumpedButton();
  displayHumidity();
  waitForBumpedButton();
  displayLightLevel();
  waitForBumpedButton();



}

/*
 * Displays temperature on LCD
 */
void displayTemperature() {
  int prevState = digitalRead(buttonPin);
  int butState = 0;
  lcd.clear();
  lcd.print("Temperature:"); 
  while((butState = digitalRead(buttonPin)) == prevState) {
    float temp = readTemp();
    lcd.setCursor(0, 1);
    lcd.print(temp);
    Serial.print("Temperature: ");
    Serial.println(temp);
    prevState = butState;
  }

  waitForButtonStateChanged();
  
}

/*
 * Displays pressure on LCD
 */
void displayPressure() {
  int prevState = digitalRead(buttonPin);
  int butState = 0;
  lcd.clear();
  lcd.print("Pressure:"); 
  while((butState = digitalRead(buttonPin)) == prevState) {
    float pres = readPressure();
    lcd.setCursor(0, 1);
    lcd.print(pres);
    Serial.print("Pressure: ");
    Serial.println(pres);
    prevState = butState;
  }

  waitForButtonStateChanged();
  
}

/*
 * Displays humidity on LCD
 */
void displayHumidity() {
  int prevState = digitalRead(buttonPin);
  int butState = 0;
  lcd.clear();
  lcd.print("Humidity:"); 
  while((butState = digitalRead(buttonPin)) == prevState) {
    float humid = readHUMID();
    lcd.setCursor(0, 1);
    lcd.print(humid);
    Serial.print("Humidity: ");
    Serial.println(humid);
    prevState = butState;
  }

  waitForButtonStateChanged();
}

/*
 * Displays light level on LCD
 */
void displayLightLevel() {
  int prevState = digitalRead(buttonPin);
  int butState = 0;
  lcd.clear();
  lcd.print("Light level:"); 
  while((butState = digitalRead(buttonPin)) == prevState) {
    float ll = readLightSensorConstrained();
    lcd.setCursor(0, 1);
    lcd.print(ll);
    Serial.print("Light level: ");
    Serial.println(ll);
    prevState = butState;
  }

  waitForButtonStateChanged();
}
