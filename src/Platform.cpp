#include "Platform.hpp"

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
 * DEFAULT CONSTRUCTOR
 * 
 * NOTES :   
 *F*/
Platform::Platform(float x0, float z0) {
  x = -x0 + 10;
  y = 10;
  z = -z0 + 10;
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
void Platform::draw(void) {
  glPushMatrix();
  glColor3ub(255, 255, 0);
  glTranslatef((x), (z), (y) - 15);
  glutSolidCube(4);
  glTranslatef(0, 0, - 9);
  glScalef(1, 1, 5);
  glutWireCube(4);

  glPopMatrix();
}
