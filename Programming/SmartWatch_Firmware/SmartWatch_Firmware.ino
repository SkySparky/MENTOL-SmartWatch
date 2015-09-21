#include <SPI.h>
#include <RTClock.h>

#include "FontPack.c"

int seconds = 0;

struct Font
{
  fontdatatype* font;
  uint8_t x_size;
  uint8_t y_size;
  uint8_t offset;
  uint8_t numchars;
};

Font cfont;

fontdatatype* fontData;
uint8_t fontXsize;
uint8_t fontYsize;
uint8_t fontOffset;
uint8_t fontNumchars;


volatile uint32  *dcport, *csport;
uint32_t   cspinmask, dcpinmask;

#define swap(a, b) { int16_t t = a; a = b; b = t; }

//PIN CONFIGURATIONS
#define TFT_SDA    PA7
//SPI_MISO(passive)PA6
#define TFT_SCK    PA5
#define TFT_CS     PA4
#define TFT_RS     PA3
#define TFT_RST    PA2
#define TFT_LED    PB7 


//LCD PARAMETERS
#define TFT_WIDTH     128
#define TFT_HEIGHT    128

#define ST7735_NOP     0x00
#define ST7735_SWRESET 0x01
#define ST7735_RDDID   0x04
#define ST7735_RDDST   0x09

#define ST7735_SLPIN   0x10
#define ST7735_SLPOUT  0x11
#define ST7735_PTLON   0x12
#define ST7735_NORON   0x13

#define ST7735_INVOFF  0x20
#define ST7735_INVON   0x21
#define ST7735_DISPOFF 0x28
#define ST7735_DISPON  0x29
#define ST7735_CASET   0x2A
#define ST7735_RASET   0x2B
#define ST7735_RAMWR   0x2C
#define ST7735_RAMRD   0x2E

#define ST7735_PTLAR   0x30
#define ST7735_COLMOD  0x3A
#define ST7735_MADCTL  0x36

#define ST7735_FRMCTR1 0xB1
#define ST7735_FRMCTR2 0xB2
#define ST7735_FRMCTR3 0xB3
#define ST7735_INVCTR  0xB4
#define ST7735_DISSET5 0xB6

#define ST7735_PWCTR1  0xC0
#define ST7735_PWCTR2  0xC1
#define ST7735_PWCTR3  0xC2
#define ST7735_PWCTR4  0xC3
#define ST7735_PWCTR5  0xC4
#define ST7735_VMCTR1  0xC5

#define ST7735_RDID1   0xDA
#define ST7735_RDID2   0xDB
#define ST7735_RDID3   0xDC
#define ST7735_RDID4   0xDD

#define ST7735_PWCTR6  0xFC

#define ST7735_GMCTRP1 0xE0
#define ST7735_GMCTRN1 0xE1

// Color definitions
#define	c_black   0x0000
#define	c_blue    0x001F
#define	c_red     0xF800
#define	c_green   0x07E0
#define c_cyan    0x07FF
#define c_magenta 0xF81F
#define c_yellow  0xFFE0
#define c_white   0xFFFF


float ledLevelHedef = 0;
float ledLevel = 0;

uint16_t lineBuffer[TFT_HEIGHT];

uint16_t textcolor   = 1;
uint16_t textbgcolor = 1;

void setup(void) {
  pinMode(PC13, OUTPUT);
  digitalWrite(PC13, 1);

  backlight_init();
  lcd_init();
  rtc_init();
  //button_init();


  fillScreen(c_black);
  drawLine(0, 0, 127, 0, c_green);
  drawLine(0, 21, 127, 21, c_green);
  drawLine(0, 127, 127, 127, c_green);

  setCurrentFont(DotMatrix);

  //setTextColor(c_green);

  //printNumber(18, 70, 50  , 2 , '-');
}

void loop() {
  backlight_loop();
  rtc_loop();
  //button_loop();


  setTextColor(c_green);
  drawString(":" , 54, 50);
  delay(750);

  setTextColor(c_black);
  drawString(":" , 54, 50);
  delay(250);


}

void setCurrentFont(fontdatatype* font)
{
  fontData   = font;
  fontXsize  = font[0];
  fontYsize  = font[1];
  fontOffset = font[2];
  fontNumchars = font[3];
}


