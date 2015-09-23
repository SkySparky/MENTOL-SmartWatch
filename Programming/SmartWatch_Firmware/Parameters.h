////////////// PIN CONFIGURATIONS
#define TFT_SDA    PA7
//SPI_MISO(passive)PA6
#define TFT_SCK    PA5
#define TFT_CS     PA4
#define TFT_RS     PA3
#define TFT_RST    PA2
#define TFT_LED    PB7

#define PIN_BUTTON_1   PB6
#define PIN_BUTTON_2   PB5
#define PIN_BUTTON_3   PB4

////////////// BUTTON 
#define BUTTON_LONG_PRESS_TRESHOLD 20

#define BUTTON_FREE        0
#define BUTTON_PRESSED     4
#define BUTTON_LONGPRESSED 5
#define BUTTON_RELEASED    6

#define BUTTON_ALL  7
#define BUTTON_ANY  8
#define BUTTON_NONE 9

boolean isButtonAllPressed  = false;
boolean isButtonAllReleased = false;
boolean isButtonAnyPressed  = false;
boolean isButtonAnyReleased = false;

struct Button
{
  uint8_t pinNo;
  boolean stateCurrent;
  uint8_t state;
  //boolean stateDoublePressed;

  uint8_t counterLongPress;
};

uint32_t back = 0;

Button buttons[3] = {
  {PIN_BUTTON_1, false,  0, 0},
  {PIN_BUTTON_2, false,  0, 0},
  {PIN_BUTTON_3, false,  0, 0}
};



////////////// RTC - DATE/TIME
uint8_t second = 0;
uint8_t minute  = 59;
uint8_t hour    = 21;
uint8_t day     = 21;
uint8_t month   = 9;
uint16_t year   = 2015;

boolean isMinuteChanged = true;
boolean isHourChanged   = true;
boolean isDayChanged    = true;
boolean isSecondChanged = true;

uint8_t DAYS[12] = {30, 31, 30, 29, 30, 31, 30, 31, 30, 31, 30, 31};

////////////// TEXT FONTS
fontdatatype* fontData;
uint8_t fontXsize;
uint8_t fontYsize;
uint8_t fontOffset;
uint8_t fontNumchars;


////////////// MATH
#define swap(a, b) { int16_t t = a; a = b; b = t; }

////////////// LCD BACKLIGHT LED 
float ledLevelHedef = 0;
float ledLevel = 0;

////////////// LCD PARAMETERS
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

//////////////  COLOR DEFINITIONS
#define	c_black   0x0000
#define	c_blue    0x001F
#define	c_red     0xF800
#define	c_green   0x07E0
#define c_cyan    0x07FF
#define c_magenta 0xF81F
#define c_yellow  0xFFE0
#define c_white   0xFFFF


////////////// SPI
volatile uint32  *dcport, *csport;
uint32_t   cspinmask, dcpinmask;

uint16_t lineBuffer[TFT_HEIGHT];
