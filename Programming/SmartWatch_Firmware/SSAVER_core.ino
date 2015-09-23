void ssaver_init()
{
  ssaverSetAnimation(0);
}

boolean ssaverSetAnimation(int _id)
{
  if (_id > 2)
    return false;
  else
  {
    ssaverClear();
    screensaver = _id;
  }

  if (screensaver == SSAVER_EMPTY)
    particleEmpty_init(0);
  else if (screensaver == SSAVER_STAR)
    particleStar_init(30);
  else if (screensaver == SSAVER_SNOW)
    particleSnow_init(40);

  ssaverEnable(true);

  return true;
}


boolean ssaverClear()
{
  if (screensaver == SSAVER_EMPTY)
    particleEmpty_clear();
  else if (screensaver == SSAVER_STAR)
    particleStar_clear();
  else if (screensaver == SSAVER_SNOW)
    particleSnow_clear();

  return true;
}

void ssaver_loop()
{
  if (ssaverEnabled == false)
    return;

  if (screensaver == SSAVER_EMPTY)
    particleEmpty_draw(true);
  else if (screensaver == SSAVER_STAR)
    particleStar_draw(true);
  else if (screensaver == SSAVER_SNOW)
    particleSnow_draw(true);
}


void ssaverEnable(boolean _en)
{
  ssaverEnabled = _en;
}


