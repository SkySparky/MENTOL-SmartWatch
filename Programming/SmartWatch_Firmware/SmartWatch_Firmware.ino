#include <SPI.h>
#include <RTClock.h>

#include "FontPack.c"
#include "Parameters.h"

#define VERSION  0.15

//MODE
uint8_t mode = 0;
uint8_t page = 1;

#define MODE_TEST  99
#define MODE_MAIN  10
#define MODE_CLOCK  2



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
  segmentWatch_init();
  page_init();

  mode = MODE_TEST;

  drawNumber(mode , 120, 0, 1, ' ', c_blue);
  clearScreen( c_black );
}

void loop() {
  lcd_loop();
  backlight_loop();
  rtc_loop();
  button_loop();
  ssaver_loop();
  menu_loop();
  segmentWatch_loop();
  

  if (isReleased(0))
  {
    clearScreen();
    pageMoveNext();
    segmentWatchUpdate();
  }

  if (isReleased(2))
  {
    clearScreen();   
    pageMovePrevious();  
    segmentWatchUpdate();   
  }

  fps_control();
}

