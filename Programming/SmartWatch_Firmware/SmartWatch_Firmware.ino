#include <SPI.h>
#include <RTClock.h>

#include "FontPack.c"
#include "Parameters.h"

#define VERSION  0.1

#define FONT_NORMAL  NormalFont
#define FONT_SMALL   SmallFont
#define FONT_SEGMENT Segment
#define FONT_DOTS    DotMatrix

uint16_t colorText   = 1;
uint16_t colorBack = 0;

boolean ssaverEnabled = false;
uint8_t screensaver  = 0;
#define SSAVER_EMPTY 0
#define SSAVER_STAR 1
#define SSAVER_SNOW 2

uint8_t mode = 0;
#define MODE_MAIN 10
#define MODE_CLOCK  2

//mode = 1 //screensaver
//mode = 2 //screensaver with Clock
//mode = 10 main screen

struct Particle
{
  float x;
  float y;
  float xSpeed;
  float ySpeed;
  float color;
  float colorSpeed;
  float size;
};

uint8_t numParticle = 0;
#define MAX_NUMBER_OF_PARTICLES 40
Particle particleArray[MAX_NUMBER_OF_PARTICLES];

void setup(void) {
  backlight_init();
  lcd_init();
  rtc_init();
  button_init();
  ssaver_init();

  setCurrentFont(FONT_SMALL);

  colorBack = c_black;
  fillScreen( colorBack );

  ssaverSetAnimation(1);
  ssaverEnable(1);

  //drawLine(0, 0, 127, 0 , c_green);
  //drawLine(0, 15, 127, 15, c_green);
  //drawLine(0, 127, 127, 127 , c_green);

}

void loop() {
  backlight_loop();
  lcd_loop();
  rtc_loop();
  button_loop();
  ssaver_loop();

  ssaver_draw();

  if (isPressed(0))
    ssaverSetAnimation(0);

  if (isPressed(1))
    ssaverSetAnimation(1);

  if (isPressed(2))
    ssaverSetAnimation(2);

  colorText = c_green;
  drawTimeAlways();

  end_loop();
}

void end_loop()
{

}

