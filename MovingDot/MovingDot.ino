/*
  MovingDot.ino
  Fisher Bricker

*/
#include <MeggyJrSimple.h> 

int x;
int y;
int color;
int enemyX;
int enemyY;




void setup() {
  MeggyJrSimpleSetup();
  x=0;
  y=0;
  color=1;
  enemyX = random (8);
  enemyY = random (8);
}

void loop() {
 Obstacle();
 DrawPx(x,y,color);
 DrawPx(enemyX,enemyY,Green);
 delay(100);
 DisplaySlate();
 CheckButtonsDown();
 MovementPlayer();
 MovementEnemy();
 Check();
// CheckDeath();
 ColorRules();
 Color();
 ClearSlate();
}

void Color() {
  if (Button_A)
  {
    color++;
  }
  if (Button_B)
  {
    color--;
  }
}
void ColorRules() {
  if (color == 17)
  {
    color=1;
  }
  if (color == 0)
  {
    color=16;
  }
}

void MovementPlayer() {
  if (Button_Up)
  {
    if (ReadPx(x,y+1) != 1)
    {
      y++;
    }
  }
  if (Button_Down)
  {
    if (ReadPx(x,y-1) != 1)
    {
      y--;
    }
  }
  if (Button_Left)
  {
    if (ReadPx(x-1,y) != 1)
    {
      x--;
    }
  }
  if (Button_Right)
  {
    if (ReadPx(x+1,y) != 1)
    {
      x++;
    }
  }
}

void Check() {
 if (x==8)
    {
      x=0;
    }
    if (x == -1)
    {
      x=7;
    }
    if (y==8)
    {
      y=0;
    }
    if (y == -1)
    {
      y=7;
    }
}

void Obstacle() {
  for (int i=2; i<6; i++)
  {
    DrawPx(i,6,Red);
    DrawPx(i,5,Red);
  }
}

void MovementEnemy() {
  delay(200);
  if (x>enemyX)
  {
    enemyX++;
  }
  if (x<enemyX)
  {
    enemyX--;
  }
  if (y>enemyY)
  {
    enemyY++;
  }
  if (y<enemyY)
  {
    enemyY--;
  }
}

void CheckDeath() {
  if (enemyX=x)
  {
    if(enemyY=y)
    {
      Tone_Start(18150,1000);
      delay(5000);
    }
  }
}
