

void drawBigTime(uint16_t colBack, uint16_t colText)
{
  drawBigTime(12, 44, colBack, colText); //Draws it in the middle of the screen
}

void drawBigTime(uint8 x, uint8 y, uint16_t colBack, uint16_t colText)
{
  setCurrentFont(FONT_SEGMENT);

  if (isHourChanged)
  {
    //FIRST: Clear the previous Hour text
    if (hour == 0)
      drawString("23", x, y , colBack);
    else
      drawNumber(hour - 1, x, y  , 2 , '0', colBack);

    //SECOND: Draw new Hour text
    drawNumber(hour, x, y  , 2 , '0', colText);

    isHourChanged   = false; //Clear the flag
  }

  if (isMinuteChanged)
  {
    //FIRST: Clear the previous Minute text
    if (minute == 0)
      drawString("59", x + 58, y  , colBack);
    else
      drawNumber(minute - 1, x + 58, y  , 2 , '0', colBack);

    //SECOND: Draw new Minute text
    drawNumber(minute, x + 58, y  , 2 , '0', colText);

    isMinuteChanged = false; //Clear the flag
  }

  if (isSecondChanged)
  {
    if (second % 2 == 0)
      setTextColor(colText);
    else
      setTextColor(colBack);

    drawString(":" , x + 41, y);

    isSecondChanged = false; //Clear the flag
  }
}


void drawCornerTime(uint16_t colBack, uint16_t colText)
{
  uint8 x = 96;
  uint8 y = 2;

  setCurrentFont(FONT_SMALL);

  if (isHourChanged)
  {
    //FIRST: Clear the previous Hour text
    if (hour == 0)
      drawString("23", x, y , colBack);
    else
      drawNumber(hour - 1, x, y  , 2 , '0', colBack);

    //SECOND: Draw new Hour text
    drawNumber(hour, x, y  , 2 , '0', colText);

    isHourChanged   = false; //Clear the flag
  }

  if (isMinuteChanged)
  {
    //FIRST: Clear the previous Minute text
    if (minute == 0)
      drawString("59", x + 17, y  , colBack);
    else
      drawNumber(minute - 1, x + 17, y  , 2 , '0', colBack);

    //SECOND: Draw new Minute text
    drawNumber(minute, x + 17, y  , 2 , '0', colText);

    isMinuteChanged = false; //Clear the flag
  }

  if (isSecondChanged)
  {
    if (second % 2 == 0)
      setTextColor(colText);
    else
      setTextColor(colBack);

    drawString(":" , x + 12, y);

    isSecondChanged = false; //Clear the flag
  }
}


void drawTimeAlways()
{
  setCurrentFont(FONT_SEGMENT);
  //colorBack = c_black;


  if (isHourChanged)
  {
    //FIRST: Clear the previous Hour text
    if (hour == 0)
      drawString("23", 12, 44 , colorBack);
    else
      drawNumber(hour - 1, 12, 44  , 2 , '0', colorBack);

    //SECOND: Draw new Hour text


    isHourChanged   = false; //Clear the flag
  }

  if (isMinuteChanged)
  {
    //FIRST: Clear the previous Minute text
    if (minute == 0)
      drawString("59", 12 + 58, 44  , colorBack);
    else
      drawNumber(minute - 1, 12 + 58, 44  , 2 , '0', colorBack);

    //SECOND: Draw new Minute text


    isMinuteChanged = false; //Clear the flag
  }

  drawNumber(hour, 12, 44  , 2 , '0', colorText);
  drawNumber(minute, 12 + 58, 44  , 2 , '0', colorText);

  if (isSecondChanged)
  {
    if (second % 2 == 0)
      setTextColor(colorText);
    else
      setTextColor(colorBack);

    drawString(":" , 12 + 41, 44);

    isSecondChanged = false; //Clear the flag
  }
}

