void rtc_init() {
  rtc_init(RTCSEL_LSI);
  rtc_set_prescaler_load(0x7fff);
  rtc_set_count(0);


  rtc_attach_interrupt(RTC_SECONDS_INTERRUPT, rtc_interrupt);
}

void rtc_loop() {

}

void rtc_interrupt() {
  if ( rtc_is_second() )
  {
    setTextColor(c_black);
    printNumber(seconds, 4 , 50  , 2 , ' ');

    seconds += 1;

    setTextColor(c_green);
    printNumber(seconds, 4 , 50  , 2 , ' ');
  }
}
