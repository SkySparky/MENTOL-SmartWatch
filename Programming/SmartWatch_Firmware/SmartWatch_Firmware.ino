#include <SPI.h>
#include <RTClock.h>

#include "FontPack.c"
#include "Parameters.h"

uint16_t textColor   = 1;
uint16_t textBgColor = 1;

void setup(void) {
  backlight_init();
  lcd_init();
  rtc_init();
  button_init();

  setCurrentFont(Segment);
}

void loop() {
  backlight_loop();
  //lcd_loop()
  rtc_loop();
  button_loop();

  if (isMinuteChanged || isHourChanged)
  {
    fillScreen(c_white);
    
    isHourChanged   = false;
    isMinuteChanged = false;
  }
  
  setTextColor(c_black);
  printNumber(hour, 12, 50  , 2 , ' ');
  drawString(":" , 53, 50);
  printNumber(minute, 70, 50  , 2 , '0');


}


