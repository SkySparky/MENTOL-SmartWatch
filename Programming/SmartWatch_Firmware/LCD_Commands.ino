void writeCommand(uint8 c) {
  *dcport &=  ~dcpinmask;
  *csport &=  ~cspinmask;
  
  SPI.write(c);
  
  *csport |= cspinmask;
}

void writeData(uint8 c) {
  *dcport |=  dcpinmask;
  *csport &= ~cspinmask;
  
  SPI.write(c);
  
  *csport |= cspinmask;
}

void writeData(uint32 size, uint8* buf) {
  *dcport |=  dcpinmask;
  *csport &= ~cspinmask;
  
  SPI.write(buf, size);
  
  *csport |= cspinmask;
}

void writeCommand(uint8 cmd, uint8 param) {
  writeCommandAndParms(cmd, 1, &param);
}

void writeCommand(uint8 cmd, uint8 param1, uint8 param2) {
  uint8 params[] = {param1, param2};
  
  writeCommandAndParms(cmd, 2, params);
}

void writeCommand(uint8 cmd, uint8 param1, uint8 param2, uint8 param3) {
  uint8 params[] = {param1, param2, param3};
  writeCommandAndParms(cmd, 3, params);
}

void writeCommandAndParms(uint8 c, uint32 numparms, uint8* params) {
  writeCommand(c);
  writeData(numparms, params);
}

