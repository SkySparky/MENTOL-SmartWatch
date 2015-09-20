void rtc_init()
{
  /*
  rtc_init(RTCSEL_LSI);
  rtc_set_prescaler_load(0x7fff);
  rtc_set_count(0);

  rtc_attach_interrupt(RTC_SECONDS_INTERRUPT, rtc_function);
  */

  rtc.attachSecondsInterrupt(rtc_function);
}

void rtc_loop()
{



}

void rtc_function()
{
  seconds+=1;// = rtc.getTime();
  printNumber(seconds, 4, 50  , 2 , '-');
  
  //timeh = (time >> 16) & 0xffff;
  //timel = time & 0xffff;

}
