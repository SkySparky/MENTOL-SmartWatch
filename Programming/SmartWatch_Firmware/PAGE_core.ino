void page_init()
{
  setPage(0);
}

void pageMoveNext()
{
  page += 1;
  setPage(page);
}

void pageMovePrevious()
{
  page -= 1;
  setPage(page);
}

void setPage(uint8 _p)
{
  page = _p;  

  if (page < 0)
    page = 0;
  else if (page == 0)
  {
    ssaverEnable(false);                           // ScreenSaver animation is disabled
    setSegmentWatchMode(SEG_WATCH_DISABLE);        // Disabled the Segment Watch 
  }
  else if (page == 1)
  {
    ssaverEnable(false);                           // ScreenSaver animation is disabled
    setSegmentWatchMode(SEG_WATCH_ENABLE);         // Activate the Segment Watch
    setSegmentWatchMode(SEG_WATCH_TEXT);           // Time is displayed as text with a Font 
    
    setSegmentWatchMode(SEG_WATCH_DRAW_ON_UPDATE); // Drawing segments only when time is changed
  }
  else if (page == 2)
  {
    ssaverEnable(false);                           // ScreenSaver animation is disabled
    
    setSegmentWatchMode(SEG_WATCH_DRAW_ALWAYS);    // Drawing segments only when time is changed   
  }
  else if (page == 3)
  {
    ssaverEnable(false);
    setSegmentWatchMode(SEG_WATCH_VECTOR);         // Time is displayed as Segments formed by lines 
    
    setSegmentWatchMode(SEG_WATCH_ANIM_FAST);      // Drawing time without animation
    setSegmentWatchMode(SEG_WATCH_SHOW_LINES);     // Drawing just lines of segments
    setSegmentWatchMode(SEG_WATCH_DRAW_ON_UPDATE); // Drawing segments only when time is changed
  }
  else if (page == 4)
  {
    ssaverEnable(false);

    setSegmentWatchMode(SEG_WATCH_ANIM_FAST);
    setSegmentWatchMode(SEG_WATCH_SHOW_FILLED);   //Drawing segments just filled
    setSegmentWatchMode(SEG_WATCH_DRAW_ON_UPDATE);
  }
  else if (page == 5)
  {
    ssaverEnable(false);

    setSegmentWatchMode(SEG_WATCH_ANIM_FAST);
    setSegmentWatchMode(SEG_WATCH_SHOW_LINES_AND_FILLED);  //Drawing lines of segments filled
    setSegmentWatchMode(SEG_WATCH_DRAW_ON_UPDATE);
  }
  else if (page == 6)
  {
    ssaverEnable(false);

    setSegmentWatchMode(SEG_WATCH_ANIM_FAST);
    setSegmentWatchMode(SEG_WATCH_SHOW_LINES_AND_FILLED);
    setSegmentWatchMode(SEG_WATCH_DRAW_ALWAYS);  // Drawing segments continously in each step
  }
  else if (page == 7)
  {
    ssaverEnable(false);

    setSegmentWatchMode(SEG_WATCH_ANIM_SMOOTH);    // Smooth fade in/out animation is activated!
    setSegmentWatchMode(SEG_WATCH_SHOW_LINES);     // Drawing just lines of segments
    setSegmentWatchMode(SEG_WATCH_DRAW_ON_UPDATE); // Drawing segments only when time is changed
  }
  else if (page == 8)
  {
    ssaverEnable(false);

    setSegmentWatchMode(SEG_WATCH_ANIM_SMOOTH);
    setSegmentWatchMode(SEG_WATCH_SHOW_FILLED);     // Drawing segments just filled
    setSegmentWatchMode(SEG_WATCH_DRAW_ON_UPDATE);
  }
  else if (page == 9)
  {
    ssaverEnable(false);

    setSegmentWatchMode(SEG_WATCH_ANIM_SMOOTH);
    setSegmentWatchMode(SEG_WATCH_SHOW_LINES_AND_FILLED); //Drawing lines of segments filled
    setSegmentWatchMode(SEG_WATCH_DRAW_ON_UPDATE);
  }
  else if (page == 10)
  {
    ssaverEnable(false);

    setSegmentWatchMode(SEG_WATCH_ANIM_SMOOTH);
    setSegmentWatchMode(SEG_WATCH_SHOW_LINES_AND_FILLED);
    setSegmentWatchMode(SEG_WATCH_DRAW_ALWAYS);  // Drawing segments continously in each step
  }
  else if (page == 11)
  {
    ssaverSetAnimation(SSAVER_SNOW);  // SNOW SCREENSAVER is activated!  
    ssaverSetParticleNumber(30);      // Particle number is 30  
    
    
    setSegmentWatchMode(SEG_WATCH_ANIM_SMOOTH);
    setSegmentWatchMode(SEG_WATCH_SHOW_LINES_AND_FILLED);
    setSegmentWatchMode(SEG_WATCH_DRAW_ALWAYS);
  }
  else if (page == 12)
  {
    ssaverSetAnimation(SSAVER_SNOW);   
    ssaverSetParticleNumber(255);      // Particle number is 255
    
    
    setSegmentWatchMode(SEG_WATCH_ANIM_SMOOTH);
    setSegmentWatchMode(SEG_WATCH_SHOW_LINES_AND_FILLED);
    setSegmentWatchMode(SEG_WATCH_DRAW_ALWAYS);
  } else if (page == 13)
  {
    ssaverSetAnimation(SSAVER_STAR);   
    ssaverSetParticleNumber(50);      // Particle number is 50
    
    setSegmentWatchMode(SEG_WATCH_ANIM_SMOOTH);
    setSegmentWatchMode(SEG_WATCH_SHOW_LINES_AND_FILLED);
    setSegmentWatchMode(SEG_WATCH_DRAW_ALWAYS);
  }else if (page == 14)
  {
    ssaverSetAnimation(SSAVER_STAR);   
    ssaverSetParticleNumber(255);      // Particle number is 255
    
    setSegmentWatchMode(SEG_WATCH_ANIM_SMOOTH);
    setSegmentWatchMode(SEG_WATCH_SHOW_LINES_AND_FILLED);
    setSegmentWatchMode(SEG_WATCH_DRAW_ALWAYS);
  }
  else
    page = 1;

}


