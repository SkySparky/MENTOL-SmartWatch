void backlight_init() {
  pinMode(TFT_LED, PWM);
  pwmWrite(TFT_LED, 0);
}

void backlight_loop()
{
  ledLevel += (ledLevelHedef - ledLevel) / 24.0;
  pwmWrite(TFT_LED, int(ledLevel));
}

void setBacklight(int a)
{
  a = min(64, max(0, a) );
  ledLevelHedef = 1024 * a - 1 * int(a == 64);
}
