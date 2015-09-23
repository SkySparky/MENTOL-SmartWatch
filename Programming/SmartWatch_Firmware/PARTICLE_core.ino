void particleStar_init(uint8 _numParts)
{
  numParticle = max(_numParts, MAX_NUMBER_OF_PARTICLES);

  for (uint8 i = 0; i < numParticle; i++)
  {
    particleArray[i].x = random(128);
    particleArray[i].y = random(128);
    particleArray[i].xSpeed = 0;
    particleArray[i].ySpeed = 0;
    particleArray[i].color = random(150);
    particleArray[i].colorSpeed = floor(2.0 + random(30) / 10);
    particleArray[i].size = 2;
  }
}

void particleStar_draw(boolean _ok)
{
  for (uint8 i = 0; i < numParticle; i++)
  {
    particleArray[i].color += particleArray[i].colorSpeed;

    if (particleArray[i].color > 512 && _ok)
    {
      particleArray[i].x = random(128);
      particleArray[i].y = random(128);
      particleArray[i].color = random(20);
      particleArray[i].colorSpeed = floor(4);
      particleArray[i].size = 1+random(3);
    }

    if (particleArray[i].color < 256)
      fillRect( particleArray[i].x, particleArray[i].y, particleArray[i].size, particleArray[i].size, colorGray(floor(particleArray[i].color)));
    else
      fillRect( particleArray[i].x, particleArray[i].y, particleArray[i].size, particleArray[i].size, colorGray(floor(512 - particleArray[i].color)));
  }
}


void particleStar_clear()
{
  for (uint8 i = 0; i < numParticle; i++)
  {
      fillRect( particleArray[i].x, particleArray[i].y, particleArray[i].size, particleArray[i].size, colorBack);
  }
}



void particleSnow_init(uint8 _numParts)
{
  numParticle = max(_numParts, MAX_NUMBER_OF_PARTICLES);

  for (uint8 i = 0; i < numParticle; i++)
  {
      particleArray[i].x = random(128);
      particleArray[i].y = 0;
      particleArray[i].ySpeed = 2+random(4);
      particleArray[i].xSpeed = 0;
      particleArray[i].color = random(255);
      particleArray[i].colorSpeed = 0;
      particleArray[i].size = 1+random(5);
  }
}

void particleSnow_draw(boolean _ok)
{
  for (uint8 i = 0; i < numParticle; i++)
  {
    particleArray[i].y += particleArray[i].ySpeed;
    particleArray[i].x += particleArray[i].xSpeed;
    
    if (particleArray[i].y > 126 && _ok)
    {
      //fillRect( particleArray[i].x-particleArray[i].xSpeed, particleArray[i].y-particleArray[i].ySpeed, particleArray[i].size, particleArray[i].size, colorBack); 
 
      particleArray[i].xSpeed = random(3)-random(3);
      particleArray[i].size = 1+random(5);
      particleArray[i].x = random(128);
      particleArray[i].y = 0;
      particleArray[i].ySpeed = 2+random(4);
      particleArray[i].color = 205+random(50);
    }

    fillRect( particleArray[i].x-particleArray[i].xSpeed, particleArray[i].y-particleArray[i].ySpeed, particleArray[i].size, particleArray[i].size, colorBack);
    fillRect( particleArray[i].x, particleArray[i].y, particleArray[i].size, particleArray[i].size, color(255, 255, particleArray[i].color));
  }
}

void particleSnow_clear()
{
  for (uint8 i = 0; i < numParticle; i++)
  {
    fillRect( particleArray[i].x, particleArray[i].y, particleArray[i].size, particleArray[i].size, colorBack);
  }
  
  fillRect(0,120,127,127,colorBack);
}



void particleEmpty_init(uint8 _numParts)
{
  numParticle = MAX_NUMBER_OF_PARTICLES;

  for (uint8 i = 0; i < numParticle; i++)
  {
      particleArray[i].x          = 0;
      particleArray[i].y          = 0;
      particleArray[i].ySpeed     = 0;
      particleArray[i].xSpeed     = 0;
      particleArray[i].color      = 0;
      particleArray[i].colorSpeed = 0;
      particleArray[i].size       = 0;
  }
}

void particleEmpty_draw(boolean _ok)
{

}

void particleEmpty_clear()
{

}




