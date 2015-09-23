#include <SPI.h>
#include <RTClock.h>

#include "FontPack.c"
#include "Parameters.h"

#define VERSION  0.12

//MODE
uint8_t mode = 0;
#define MODE_MAIN 10
#define MODE_CLOCK  2

//SEGMENT
boolean segmentData[10][7] = {
  {true, true, true, true, true, true, false}, //0
  {false, true, true, false, false, false, false}, //1
  {true, true, false, true, true, false, true}, //2
  {true, true, true, true, false, false, true}, //3
  {false, true, true, false, false, true, true}, //4
  {true, false, true, true, false, true, true}, //5
  {true, false, true, true, true, true, true}, //6
  {true, true, true, false, false, false, false}, //7
  {true, true, true, true, true, true, true},  //8
  {true, true, true, true, false, true, true}, //9
};

uint8 segmentWidth = 18;
uint8 segmentStroke = 2;
uint16_t segmentColor = c_white;

void setup(void) {
  backlight_init();
  lcd_init();
  rtc_init();
  button_init();
  ssaver_init();
  menu_init();

  setCurrentFont(FONT_SMALL);

  colorBack = c_black;
  fillScreen( colorBack );

  ssaverSetAnimation(0);

  drawLine(0, 0, 127, 0 , c_green);
  //drawLine(0, 15, 127, 15, c_green);
  drawLine(0, 127, 127, 127 , c_green);
}

void loop() {
  backlight_loop();
  lcd_loop();
  rtc_loop();
  button_loop();
  ssaver_loop();
  menu_loop();

  /*
    if (isMinuteChanged)
    {
      drawSegmentNumber(minute - 1, 6, 36, c_white );
      drawSegmentNumber(minute, 6, 36, c_black );

      isMinuteChanged = false;
    }
  */

  drawSegmentWatch(c_orange);

  if (isPressed(0))
    ssaverSetAnimation(0);

  if (isPressed(1))
    ssaverSetAnimation(1);

  if (isPressed(2))
    ssaverSetAnimation(2);

  //colorText = c_green;
  //drawTimeAlways();

  end_loop();
}

void end_loop()
{

}

