void drawLineSegment(uint8 num, uint8 x, uint8 y)
{
  uint8 w = 4;
  uint8 h = 24;
  uint16_t col = c_blue;
  
  if (num != 1 && num != 4)
  {
    drawLine(x,y,x+h,y,col);
    drawLine(x+h-w,y+w,x+h,y,col);
    drawLine(x+h-w,y+w,x+w,y+w,col);
    drawLine(x,y,x+w,y+w,col);
  }

}

void drawNumber(uint8 num, uint8 x, uint8 y)
{

}
