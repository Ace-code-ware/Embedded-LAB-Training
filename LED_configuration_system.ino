#include <LiquidCrystal.h>

const float voltageTotal = 5.0;
const float current = 0.02;
const float voltageAlt = 3.3;
const char ohm = 0xf4;
//voltage reading resoulution factor
const float resolution = (5.0 / 1023.0);
//assign the pins of the LCD to respective sockets of Arduino
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
//Initialize the library with 4 bit data exchange interface
int sensepin = A2;
int Read;
float voltage;
float resistance;
float resistanceAlt;
float power;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void setup() {
  //initialize 16x2 LCD
  lcd.begin(16, 2);
}

void loop() {
  //read analog signal
  Read = analogRead(sensepin);
  voltage = Read * resolution;
  resistance = (voltageTotal - voltage) / current;
  power = voltage * current;
  //Resistance at different source voltage
  resistanceAlt = ((voltageAlt - voltage) / current);
 
 //checks wheather LED is connected
    
 if (voltage<5.0 && voltage>0)
 {
    lcd.setCursor(0, 0);
    lcd.print("LED PARAMETERS:");
    lcd.setCursor(0, 1);
    lcd.print(voltage);
    lcd.print("V  ");
    lcd.print(power * 1000);
    lcd.print("mW");
    delay(9000);
    lcd.clear();

    //displaying LED recomendations at 5 volt supply
    lcd.setCursor(0, 0);
    lcd.print("R at5V,");
    lcd.print(resistance);
    lcd.print(ohm);
    //displaying LED recomendations at 3.3 volt supply
    lcd.setCursor(0, 1);
    lcd.print("R at3.3V,");
    lcd.print(resistanceAlt);
    lcd.print(ohm);
    delay(9000);
    lcd.clear();
  }
  else if (voltage = 5.0)
  {
    lcd.setCursor(0, 0);
    lcd.print("LED DISCONNECTED");
    delay(500);
    lcd.clear();
  } 
  
}
