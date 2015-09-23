void drawPolygon(uint8* _data, uint8 size, uint16_t col)
{
  for (uint8 i = 0; i < size - 1; i++)
  {
    drawLine(_data[i * 2], _data[i * 2 + 1] , _data[i * 2 + 2], _data[i * 2 + 3] , col);
  }

  drawLine(_data[size * 2 - 2], _data[size * 2 - 1] , _data[0], _data[1] , col);
}

void drawQuad(uint8 _x1, uint8 _y1,   uint8 _x2, uint8 _y2,  uint8 _x3, uint8 _y3,  uint8 _x4, uint8 _y4,  uint16_t col)
{
  drawLine(_x1, _y1,  _x2, _y2, col);
  drawLine(_x2, _y2,  _x3, _y3, col);
  drawLine(_x3, _y3,  _x4, _y4, col);
  drawLine(_x4, _y4,  _x1, _y1, col);
}

void drawHex(uint8 _x1, uint8 _y1,   uint8 _x2, uint8 _y2,  uint8 _x3, uint8 _y3,  uint8 _x4, uint8 _y4,  uint8 _x5, uint8 _y5,  uint8 _x6, uint8 _y6, uint16_t _col)
{
  drawLine(_x1, _y1,  _x2, _y2, _col);
  drawLine(_x2, _y2,  _x3, _y3, _col);
  drawLine(_x3, _y3,  _x4, _y4, _col);
  drawLine(_x4, _y4,  _x5, _y5, _col);
  drawLine(_x5, _y5,  _x6, _y6, _col);
  drawLine(_x6, _y6,  _x1, _y1, _col);
}

void drawSegment(uint8 _num, uint8 x, uint8 y, uint16_t _col)
{
  uint8 w = segmentStroke ;
  uint8 h = segmentWidth;

  if (_num == 0)
    drawHex(x, y, x + w, y - w, x + h - w, y - w, x + h, y,  x + h - w, y + w,  x + w, y + w,  _col);

  if (_num == 1)
    drawHex(x + h, y, x + h + w, y + w, x + h + w, y + h - w, x + h, y + h,  x + h - w, y + h - w,  x + h - w, y + w, _col);

  if (_num == 2)
    drawHex(x + h, y + h, x + h + w, y + w + h, x + h + w, y + h - w + h,  x + h, y + h + h,  x + h - w, y + h - w + h,  x + h - w, y + w + h, _col);

  if (_num == 3)
    drawHex(x, y + 2 * h, x + w, y - w + 2 * h, x + h - w, y - w + 2 * h, x + h, y + 2 * h,  x + h - w, y + w + 2 * h,  x + w, y + w + 2 * h,  _col);

  if (_num == 5)
    drawHex(x, y, x + w, y + w, x + w, y + h - w, x, y + h,  x  - w, y + h - w,  x  - w, y + w, _col);

  if (_num == 4)
    drawHex(x, y + h, x + w, y + w + h, x + w, y + h - w + h,  x, y + h + h,  x  - w, y + h - w + h,  x  - w, y + w + h, _col);

  if (_num == 6)
    drawHex(x, y + h, x + w, y - w + h, x + h - w, y - w + h, x + h, y + h,  x + h - w, y + w + h,  x + w, y + w + h,  _col);
}

void drawSegmentNumber(uint8 _num, uint8 _x, uint8 _y,  uint16_t _col)
{
  _num = _num  % 100;

  uint8 _num1 = floor(_num / 10);
  uint8 _num2 = _num %  10;

  if (_num < 10)
  {
    for (uint8 i = 0; i < 7; i++)
      if (segmentData[0][i])
        drawSegment(i, _x + 3, _y, _col);

    for (uint8 i = 0; i < 7; i++)
      if (segmentData[_num][i])
        drawSegment(i, _x + 3 + segmentWidth + segmentStroke * 2 + 4, _y, _col);
  }
  else
  {
    for (uint8 i = 0; i < 7; i++)
      if (segmentData[_num1][i])
        drawSegment(i, _x + 3, _y, _col);

    for (uint8 i = 0; i < 7; i++)
      if (segmentData[_num2][i])
        drawSegment(i, _x + 3 + segmentWidth + segmentStroke * 2 + 4, _y, _col);
  }
}

void drawSegmentWatch(uint16_t _col)
{
  segmentColor = _col;

  if (isHourChanged)
  {
    //FIRST: Clear the previous Hour text
    drawSegmentNumber(88, 64 - segmentWidth / 3 - segmentWidth * 2 - segmentStroke * 4 - 4 , 45, c_gray);

    //SECOND: Draw new Hour text
    drawSegmentNumber(hour, 64 - segmentWidth / 3 - segmentWidth * 2 - segmentStroke * 4 - 4 , 45, segmentColor);

    isHourChanged = false; //Clear the flag
  }


  if (isMinuteChanged)
  {
    //FIRST: Clear the previous Minute text
    drawSegmentNumber(88, 64 + segmentWidth / 3, 45, c_gray);

    //SECOND: Draw new Minute text
    drawSegmentNumber(minute, 64 + segmentWidth / 3, 45, segmentColor);

    isMinuteChanged = false; //Clear the flag
  }

  if (isSecondChanged)
  {
    if (second % 2 == 0)
    {
      //FIRST: Clear the previous Second image
      drawRect(65 - 2, 45 + segmentWidth - 6,  4, 4, c_gray);
      drawRect(65 - 2, 45 + segmentWidth + 2,  4, 4, c_gray);
    }
    else
    {
      //SECOND: Draw new Second image
      drawRect(65 - 2, 45 + segmentWidth - 6,  4, 4, segmentColor);
      drawRect(65 - 2, 45 + segmentWidth + 2,  4, 4, segmentColor);
    }

    isSecondChanged = false; //Clear the flag
  }

}
