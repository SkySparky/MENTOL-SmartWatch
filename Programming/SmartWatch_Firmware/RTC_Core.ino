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
    second += 1;
    isSecondChanged = true;
    
    digitalWrite(PC13,!digitalRead(PC13));
    
    if (second > 4)
    {
      second = 0;
      minute  += 1;
      isMinuteChanged = true;

      if (minute > 59)
      {     
        minute = 0;
        hour  += 1;
        isHourChanged = true;

        if (hour > 23)
        {
          hour = 0;
          day  += 1;
          isDayChanged = true;

          if (day > DAYS[month])
          {
            day = 0;
            month  += 1;

            if (month > 11)
            {
              month = 0;
              year += 1;
            }
          }

        }
      }
    }
  }
}
