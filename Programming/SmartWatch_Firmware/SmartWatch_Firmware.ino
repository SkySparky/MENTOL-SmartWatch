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
  isMinuteChanged = true;
}

void loop() {
  backlight_loop();
  //lcd_loop()
  rtc_loop();
  button_loop();

  if (isMinuteChanged || isHourChanged)
  {
    fillScreen(c_white);

    setTextColor(c_black);
    printNumber(hour, 12, 50  , 2 , ' ');
    printNumber(minute, 70, 50  , 2 , '0');

    isHourChanged   = false;
    isMinuteChanged = false;  
  }


  if (isSecondChanged)
  {
    if (second %2 == 0)
    setTextColor(c_black);
    else
    setTextColor(c_white);
    
    drawString(":" , 53, 50);

    isSecondChanged = false;
  }

}


