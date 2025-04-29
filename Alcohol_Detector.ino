#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int mq2Pin = A0;     // MQ2 analog pin
const int buzzerPin = D5;   // Buzzer pin (active-low)
const int threshold = 365;  // Adjust this threshold based on your testing

void setup() {
  Serial.begin(9600);
  
  // Initialize the LCD
  lcd.init();
  lcd.backlight();
  
  // Initialize buzzer pin as output and set it HIGH (silent for active-low)
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(buzzerPin, HIGH); // Turn buzzer off initially
  
  lcd.setCursor(0, 0);
  lcd.print("Alcohol Detector");
  lcd.setCursor(0, 1);
  lcd.print("Initializing...");
  
  delay(2000); // Warm-up time for MQ2 sensor
  lcd.clear();
}

void loop() {
  int sensorValue = analogRead(mq2Pin);
  
  Serial.print("Alcohol Level: ");
  Serial.println(sensorValue);
  
  lcd.setCursor(0, 0);
  lcd.print("Alcohol Level:");
  lcd.setCursor(0, 1);
  lcd.print(sensorValue);
  lcd.print("    "); // Clear any remaining digits
  
  if (sensorValue > threshold) {
    lcd.setCursor(8, 1);
    lcd.print("DANGER!");
    // Active-low buzzer - sound the alarm
    digitalWrite(buzzerPin, LOW); // Turn buzzer ON
    delay(500);
    digitalWrite(buzzerPin, HIGH); // Turn buzzer OFF
    delay(500);
  } else {
    lcd.setCursor(8, 1);
    lcd.print("Normal ");
    digitalWrite(buzzerPin, HIGH); // Ensure buzzer is OFF
  }
  
  delay(1000); // Wait for a second before next reading
}