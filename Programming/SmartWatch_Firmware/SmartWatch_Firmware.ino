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

uint8 segmentWidth = 38;
uint8 segmentStroke = 4;
uint16_t segmentColor = c_white;
uint16_t segmentFillColor = c_red;

unsigned long int loopTime = 0;
float delta = 0;
float deltaHedef = 0;

uint  fpsFinal = 100;

void setup(void) {
  backlight_init();
  lcd_init();
  rtc_init();
  button_init();
  ssaver_init();
  menu_init();



  colorBack = c_black;
  fillScreen( colorBack );

  ssaverSetAnimation(0);

  //drawLine(0, 0, 127, 0 , c_green);
  //drawLine(0, 15, 127, 15, c_green);
  //drawLine(0, 127, 127, 127 , c_green);
}

void loop() {
  loopTime = millis();


  backlight_loop();
  lcd_loop();
  rtc_loop();
  button_loop();
  ssaver_loop();
  menu_loop();


  if (isPressed(0))
    ssaverSetAnimation(0);

  if (isPressed(1))
    ssaverSetAnimation(1);

  if (isPressed(2))
    ssaverSetAnimation(2);

  drawSegmentWatch(c_green, c_green,    c_black, c_black , true, false);
  //colorText = c_green;
  //drawTimeAlways();

  end_loop();


}

void end_loop()
{
  setCurrentFont(FONT_SMALL);

  drawNumber(fpsFinal    , 0, 0, 3, ' ', c_black);

  deltaHedef = millis() - loopTime;

  delta += (deltaHedef - delta)/24.0; //
  fpsFinal = (1000.0 / delta);
/*
  if (abs(fpsFinal - floor(fps)) > 1)
  {
    fpsFinal = floor(fps);
  }*/

  drawNumber(fpsFinal , 0, 0, 3, ' ', (fpsFinal > 55)*c_white + (fpsFinal <= 55)*c_blue);

  delay(max(0, 20 - delta));
}

