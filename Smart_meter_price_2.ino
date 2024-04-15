#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

float current, power;
int maxSensorValue = 0;

void setup() {
  lcd.begin(16, 2);
  lcd.print("SMART METER BY PRICE");
  
  // Initialize Serial communication
  Serial.begin(9600);
}

void loop() {
  maxSensorValue = 0;
  
  for (int i = 0; i < 100; i++) {
    int sensorReading = analogRead(A0);
    if (sensorReading > maxSensorValue) maxSensorValue = sensorReading;
    delay(10);
  }
  
  current = maxSensorValue * 0.9049;
  power = current * 220; // Assuming voltage is 220V

  // Print the results to the LCD
  lcd.setCursor(7, 0);
  lcd.print(" ", 3 - int(log10(power)));
  lcd.print(power);

  // Print the results to the Serial Monitor on the same line
  Serial.print("Current: ");
  Serial.print(current);
  Serial.print(" A - Power: ");
  Serial.print(" ", 3 - int(log10(power)));
  Serial.print(power);
  Serial.println(" W");
}
