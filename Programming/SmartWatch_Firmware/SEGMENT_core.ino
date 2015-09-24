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

void fillSegment(uint8 _num, uint8 x, uint8 y, uint16_t _col)
{
  uint8 w = segmentStroke;
  uint8 h = segmentWidth;

  if (_num == 0 || _num == 3 || _num == 6)
    for (uint8 i = 0; i < segmentStroke; i++)
    {
      drawLine(x + 1 + i, y - i + 2 * h * (_num == 3) + h * (_num == 6),  x + h - i, y - i + 2 * h * (_num == 3) + h * (_num == 6), _col);
      drawLine(x + 1 + i, y + i + 2 * h * (_num == 3) + h * (_num == 6),  x + h - i, y + i + 2 * h * (_num == 3) + h * (_num == 6), _col);
    }
  else
    for (uint8 i = 0; i < segmentStroke; i++)
    {
      drawLine(x + h * (_num == 2 || _num == 1) + i, y + 1 + i + h * (_num == 2 || _num == 4),  x + h * (_num == 2 || _num == 1) + i, y + h + h * (_num == 2 || _num == 4) - i, _col);
      drawLine(x + h * (_num == 2 || _num == 1) - i, y + 1 + i + h * (_num == 2 || _num == 4),  x + h * (_num == 2 || _num == 1) - i, y + h + h * (_num == 2 || _num == 4) - i, _col);
    }
}

void drawSegment(uint8 _num, uint8 x, uint8 y, uint16_t _col,  uint16_t _col_fill, boolean _isfill)
{
  if (_isfill)
    fillSegment(_num, x, y, _col_fill);

  drawSegment(_num, x, y, _col);
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

void drawSegmentNumber(uint8 _num, uint8 _x, uint8 _y,  uint16_t _col, uint16_t _col_fill, boolean _isfill)
{
  segmentColor = _col;
  segmentFillColor = _col_fill;

  _num = _num  % 100;

  uint8 _num1 = floor(_num / 10);
  uint8 _num2 = _num %  10;

  if (_num < 10)
  {
    for (uint8 i = 0; i < 7; i++)
      if (segmentData[0][i])
        drawSegment(i, _x + 3, _y, _col, _col_fill, _isfill);

    for (uint8 i = 0; i < 7; i++)
      if (segmentData[_num][i])
        drawSegment(i, _x + 3 + segmentWidth + segmentStroke * 2 + 4, _y, _col, _col_fill, _isfill);
  }
  else
  {
    for (uint8 i = 0; i < 7; i++)
      if (segmentData[_num1][i])
        drawSegment(i, _x + 3, _y, _col, _col_fill, _isfill);

    for (uint8 i = 0; i < 7; i++)
      if (segmentData[_num2][i])
        drawSegment(i, _x + 3 + segmentWidth + segmentStroke * 2 + 4, _y, _col, _col_fill, _isfill);
  }
}

///////////SPECIAL CODE FOR DRAWING WATCH WITH SEGMENT MODULE
void drawSegmentWatch(uint16_t _col, uint16_t _colFill, uint16_t _colBack, uint16_t _colBackFill, boolean _always, boolean _isfill)
{
  segmentColor = _col;
  segmentFillColor = _colFill;
  segmentWidth = 18;
  segmentStroke = 2;

  if (isHourChanged)             drawSegmentNumber(88, 64 - segmentWidth / 3 - segmentWidth * 2 - segmentStroke * 4 - 4 , 45, _colBack, _colBackFill, _isfill);
  if (isHourChanged || _always)  drawSegmentNumber(hour, 64 - segmentWidth / 3 - segmentWidth * 2 - segmentStroke * 4 - 4 , 45, _col, _colFill, _isfill);
  if (isHourChanged)             isHourChanged = false;

  if (isMinuteChanged)              drawSegmentNumber(88, 64 + segmentWidth / 3, 45, _colBack, _colBackFill, _isfill);
  if (isMinuteChanged || _always)   drawSegmentNumber(minute, 64 + segmentWidth / 3, 45, _col, _colFill, _isfill);
  if (isMinuteChanged)              isMinuteChanged = false;


  if (isSecondChanged || _always)
  {
    if (second % 2 == 0)
    {
      if (_isfill) //FIRST: Clear the previous Second image
      {
        drawRect(65 - 2, 45 + segmentWidth - 6,  4, 4, _colBack );
        drawRect(65 - 2, 45 + segmentWidth + 2,  4, 4, _colBack );
      }

      fillRect(65 - 2 + 1, 45 + segmentWidth - 6 + 1,  3, 3, _colBackFill);
      fillRect(65 - 2 + 1, 45 + segmentWidth + 2 + 1,  3, 3, _colBackFill);
    }
    else
    {
      if (_isfill)//SECOND: Draw new Second image
      {
        drawRect(65 - 2, 45 + segmentWidth - 6,  4, 4, _col);
        drawRect(65 - 2, 45 + segmentWidth + 2,  4, 4, _col);
      }

      fillRect(65 - 2 + 1, 45 + segmentWidth - 6 + 1,  3, 3, _colFill);
      fillRect(65 - 2 + 1, 45 + segmentWidth + 2 + 1,  3, 3, _colFill);
    }

    isSecondChanged = false; //Clear the flag
  }
}
