#include "Tile.hpp"

/*F***********************************************************
 * 
 * 
 * PURPOSE : 
 *
 * RETURN :  
 *
 * NOTES :   
 *F*/

/*F***********************************************************
 * regulateVelocity()
 * 
 * PURPOSE : makes sure we are not moving too fast in any
 *           given direction
 *
 * RETURN :  void
 *
 * NOTES :   function name is rather verbos
 *F*/
inline void regulateVelocity(float &vel) {
  if(vel > .2) {
    vel = .2;
  }
}

/*F***********************************************************
 * update(Dir d)
 * 
 * PURPOSE : Updates the location of the tile
 *
 * RETURN :  void
 *
 * NOTES :   default values are not used when the player won
 *           the game.
 *           
 *F*/
void Tile::update(std::vector <bool> controls,
		  float x0, float y0, float z0) {

  //we are setting the ground
  //when the user won the game
  if(x0 || y0 || z0) {
    x = x0;
    y = y0;
    z = z0;
  }


  if(controls[0]) {
    yv += .02;
  }

  if(controls[1]) {
    zv -= .01;
  }

  if(controls[2]) {
    zv += .01;
  }

  if(controls[3]) {
    xv -= .01;
  }


  if(controls[4]) {
    xv += .01;
  }

  regulateVelocity(xv);
  regulateVelocity(yv);
  regulateVelocity(zv);

  //gravity
  yv -= .005;

  x += xv;
  y -= yv;
  z += zv;
}

/*F***********************************************************
 * draw(void)
 * 
 * PURPOSE : Generic draw function
 *
 * RETURN :  void
 *
 * NOTES :   
 *F*/
void Tile::draw(void) {
  glPushMatrix();
  glColor3ub(100, 100, 100);
  glTranslatef((x), (z), (y));
  glutSolidCube(1);
  glPopMatrix();
}

/*F***********************************************************
 * DEFAULT CONSTRUCTOR
 * 
 * NOTES :   
 *F*/
Tile::Tile() {
  xv = 0;
  yv = 0;
  zv = 0;
}

/*F***********************************************************
 * DEFAULT CONSTRUCTOR
 * 
 * NOTES :   
 *F*/
Tile::Tile(float xl, float yl, float zl) {
  x = xl;
  y = yl;
  z = zl;
}
