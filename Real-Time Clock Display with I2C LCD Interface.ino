#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <RTClib.h>
LiquidCrystal_I2C lcd(0x27,  16, 2);

RTC_DS3231 rtc;

void setup () {
  lcd.init();

 lcd.backlight( );
  Serial.begin(115200);
  if (!rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }


  if (rtc.lostPower()) {
    Serial.println("RTC lost power, let's set the time!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
}

void loop () {
  DateTime now = rtc.now();

 lcd.setCursor(0,0);

  Serial.print(now.year(), DEC);
  Serial.print('/');
  lcd.print(now.year());
  lcd.print('/');

  Serial.print(now.month(), DEC);
  Serial.print('/');
  lcd.print(now.month());
  lcd.print('/');

  Serial.print(now.day(), DEC);
  Serial.print(" ");
  lcd.print(now.day());
  lcd.print('/');

  lcd.setCursor(0,1);

  Serial.print(now.hour(), DEC);
  Serial.print(':');
  lcd.print(now.hour());
  lcd.print('/');

  Serial.print(now.minute(), DEC);
  Serial.print(':');
  lcd.print(now.minute());
  lcd.print('/');

  Serial.print(now.second(), DEC);
  lcd.print(now.second());
  lcd.print('/');
  Serial.println();

  delay(1000);
}