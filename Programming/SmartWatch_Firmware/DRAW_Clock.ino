void drawTextTime(uint16_t _colBack, uint16_t _colText, boolean _always)
{
  drawBigTime(12, 44, _colBack, _colText, _always); //Draws it in the middle of the screen
}

void drawBigTime(uint8 x, uint8 y, uint16_t colBack, uint16_t colText, boolean _always)
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


  if (_always) //SECOND: Draw new Hour text
    drawNumber(hour, x, y  , 2 , '0', colText);

  if (isMinuteChanged)
  {
    //FIRST: Clear the previous Minute text
    if (minute == 0)
      drawString("59", x + 58, y  , colBack);
    else
      drawNumber(minute - 1, x + 58, y  , 2 , '0', colBack);
    fillRect(x + 58, y, 55, 50, colBack);

    //SECOND: Draw new Minute text
    drawNumber(minute, x + 58, y  , 2 , '0', colText);

    isMinuteChanged = false; //Clear the flag
  }
  if (_always) //SECOND: Draw new Minute text
    drawNumber(minute, x + 58, y  , 2 , '0', colText);

  if (isSecondChanged || _always)
  {
    if (second % 2 == 0)
      setTextColor(colText);
    else
      setTextColor(colBack);


    drawString(":" , x + 41, y);

    if (isSecondChanged)
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
