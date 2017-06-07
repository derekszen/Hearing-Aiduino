#include <Arduino.h>
#include <LiquidCrystal.h>
#include <avr/io.h>
#include <SoftwareSerial.h>

char first[] = "Testing";
char second[] = "Example";
int delayTime = 500;

//Initialize the LCD with the numbers of the interface pin.
LiquidCrystal lcd(4, 6, 10, 11, 12, 13);
void setup()
{
  // Set up the number of rows & columns.
  lcd.begin(16, 2);
  Serial.begin(115200);
  Serial.println("Interfacfing arduino with nodemcu");
  sw.begin(115200);
}

void loop()
{
  // Initial position of cursor
  lcd.setCursor(15, 0);

  for(int posCounter = 0; posCounter < 26; posCounter ++ ) {
    lcd.scrollDisplayLeft();
    lcd.print(first[posCounter]);
    delay(delayTime);
  }
  lcd.clear(); //Clears the LCD screen and positions the cursor in the upper-left corner.
  lcd.setCursor(15,1);
  for (int i = 0; i < 26; i++)
  {
    lcd.scrollDisplayLeft();
    lcd.print(second[i]);
    delay(delayTime);
  }
  lcd.clear();
  // NodeMCU data
  Serial.println("Sending data to nodemcu");
  int adc=analogRead(A0);
  Serial.print("{\"sensorid\":");
  Serial.print(id);//sensor id
  Serial.print(",");
  Serial.print("\"adcValue\":");
  Serial.print(adc);//offset
  Serial.print("}");
  Serial.println();
  sw.print("{\"sensorid\":");
  sw.print(id); //sensor id
  sw.print(",");
  sw.print("\"adcValue\":");
  sw.print(adc);//offset
  sw.print("}");
  sw.println();
  delay(5000);

}
