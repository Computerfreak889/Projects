#include <LiquidCrystal_I2C.h>
#include <HCSR04.h>

HCSR04 hc(12, 10); //initialisation class HCSR04 (trig pin , echo pin)
LiquidCrystal_I2C lcd(0x27, 16, 2); 


float resetDistance;

void setup()
{
  // initialize LCD
  lcd.init();
  // turn on LCD backlight                      
  lcd.backlight();
  Serial.begin(9600);
 
}

void loop()
{
  float  distance = hc.dist();
 //Serial.println(distance);
  
    if(distance<14){
      resetDistance =((12.50) - (distance));

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Deep");
      lcd.setCursor(0, 1);
      lcd.print(resetDistance);
      Serial.println(resetDistance);
      delay(150);}
}