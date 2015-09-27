#include <SPI.h>
#include <RTClock.h>

#include "FontPack.c"
#include "Parameters.h"

#define VERSION  0.25

//MODE
uint8 mode = 0;
int page = -1;

#define MODE_TEST  99
#define MODE_MENU  10
#define MODE_CLOCK  2

#define THEME_NONE  0
#define THEME_SPACE 3

uint8 themeSegWatch = 0;
uint8 themeMenu = 0;

boolean segWatchAutoUpdateTime = true;
uint32 alarmDisableWatch = 0;

boolean isCornerTimeEnabled = false;
float alphaCornerTime = 0;

uint8 batLevel = 8;
uint8 batLevelMax = 8;

uint8 menuActive = 0;
uint8 menuNumber = 4;

struct Position {
  float x ;
  float y ;
  int16 xpre ;
  int16 ypre ;
  int16 xTarget ;
  int16 yTarget ;
};

Position barTop      = {0, 0, 0, 0, 0, 0};

Position menuLines[8] =  {
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},

  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0}
};

void setup(void) {
  backlight_init();
  lcd_init();
  rtc_init();
  button_init();
  ssaver_init();
  menu_init();
  segmentWatch_init();
  page_init();
  alarm_init();

  setBacklight(64);

  mode = MODE_CLOCK;

  themeSpace_init();
}


void drawBarTop(int8 _x, int8 _y, uint16_t _col)
{
  drawLine(0,          _y + 2 - 1,       82,   _y + 2 - 1 , _col); //   -----
  drawLine(80  + 10 + 1, _y + 14 - 1,      82 + 1, _y + 2 - 1 , _col); //        \
  drawLine(80  + 10  , _y + 14 - 1,      82,   _y + 2 - 1 , _col); //         \
  drawLine(80  + 10,   _y + 14 - 1,     127,   _y + 14 - 1, _col); //           ---

  drawLine(0,        _y + 2,       82, _y + 2 , _col);//   -----
  drawLine(80  + 10, _y + 14,      82, _y + 2 , _col);//        \
  drawLine(80  + 10, _y + 14,     127, _y + 14, _col);//          ---

  drawLine(0,        _y + 12,       88 ,  _y + 12 , _col);

  //BATTERY ICON
  drawRect(2, _y + 2 + 2, batLevelMax + 3, 6, _col);
  drawLine(batLevelMax + 3 + 2 + 1, _y + 2 + 4, batLevelMax + 3 + 2 + 1, _y + 2 + 6, _col );

  for (uint8 i = 0; i < batLevel ; i++ )
    drawLine(4 + i, _y + 2 + 4, 4 + i, _y + 2 + 4 + 2, _col);

  //USB ICON
  uint8 xx = 14;
  if (_col == c_green) _col = c_yellow;

  drawLine(xx + 4, _y + 2 + 5 + 1, xx + 5, _y + 2 + 5 + 1, _col);
  drawLine(xx + 4, _y + 2 + 5 - 1, xx + 5, _y + 2 + 5 - 1, _col);

  drawLine(xx + 3, _y + 2 + 5, xx + 14, _y + 2 + 5, _col);

  drawLine(xx + 8, _y + 2 + 3, xx + 11, _y + 2 + 3, _col); //top line
  drawPixel(xx + 7, _y + 2 + 4, _col); //top line's point

  drawLine(xx + 10, _y + 2 + 7, xx + 12, _y + 2 + 7, _col); //bottom line
  drawPixel(xx + 9, _y + 2 + 6, _col); //bottom line's point


  //BLUETOOTH LOGO
  xx = 32;
  if (_col == c_yellow) _col = color(65, 150, 255);

  drawLine(xx + 2, _y + 2 + 2 , xx + 2, _y + 2 + 8 , _col);
  drawPixel(xx + 3, _y + 2 + 3, _col);
  drawPixel(xx + 4, _y + 2 + 4, _col);
  drawPixel(xx + 3, _y + 2 + 5, _col);
  drawPixel(xx + 4, _y + 2 + 6, _col);
  drawPixel(xx + 3, _y + 2 + 7, _col);

  drawPixel(xx + 0, _y + 2 + 4, _col);
  drawPixel(xx + 1, _y + 2 + 5, _col);
  drawPixel(xx + 0, _y + 2 + 6, _col);
}


void loop() {
  lcd_loop();
  backlight_loop();
  rtc_loop();
  button_loop();
  ssaver_loop();
  menu_loop();
  segmentWatch_loop();
  alarm_loop();


  themeSpace_loop();

  if ( mode == MODE_MENU)
  {
    for (int i = 0; i < 4; i++)
    {

    }
  }

  //MOTION CONTROL
  barTop.ypre = floor(barTop.y);
  barTop.y += (barTop.yTarget -  barTop.y) / 6.0;

  if (barTop.ypre != floor(barTop.y))
  {
    drawBarTop(0, barTop.ypre, colorBack);
    drawBarTop(0, floor(barTop.y)   , color(0, 125 , 0));
  }


  ///SWITCHERS IN CHAIN
  if (alphaCornerTime > 240 && mode == MODE_MENU)
  {
    drawBarTop(0, floor(barTop.y)   , color(0, 125 + 130 * ((int)(ceil(alphaCornerTime)) % 5 == 0) , 0));

  }
  if (barTop.y > -1 && mode == MODE_MENU)
  {
    isCornerTimeEnabled = true;
  }
  if (alphaCornerTime < 5 && mode == MODE_CLOCK)
    barTop.yTarget = -16;

  if (barTop.y < -12 && mode == MODE_CLOCK)
  {
    setSegmentWatchMode(SEG_WATCH_ENABLE);
    segWatchAutoUpdateTime = true;
    setSegmentWatchSmooth(mytime.hour, mytime.minute);
  }



  if (isReleased(1))
  {
    if (isBacklightOff() == true)
      setBacklight(64);
    else if (mode == MODE_CLOCK)
    {
      setAlarm(alarmDisableWatch , 1000);
      segWatchAutoUpdateTime = false;

      for (uint8 j = 0 ; j < 7; j++)
        for (uint8 i = 0 ; i < 4; i++)
          segWatchAlphaTarget[i][j] = 0;

      barTop.yTarget = 0;

      mode = MODE_MENU;

      exit;
    }
    else
    {
      isCornerTimeEnabled = false;
      mode = MODE_CLOCK;
    }
  }


  fps_control();
}


