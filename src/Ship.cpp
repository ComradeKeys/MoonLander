#include "Ship.hpp"

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
 * 
 * 
 * PURPOSE : 
 *
 * RETURN :  
 *
 * NOTES :   
 *F*/
void Ship::animate(std::vector <bool> controls) {

  if(controls[0]) {
    glPushMatrix();
    glColor3ub(255, 0, 0);
    glTranslatef(x, z + .5, y - 2);
    glRotatef(25, 0.0, 1.0, 0.0);
    glRotatef(angle, 0.0, 1.0, 0.0);
    glutSolidTetrahedron();
    glTranslatef(0.0, 0.0, -.8);
    glPopMatrix();
  }

  if(controls[1]) {
    glPushMatrix();
    glColor3ub(255, 0, 0);
    glTranslatef(x, z - 2, y -1);
    glRotatef(25, 0.0, 1.0, 0.0);
    glRotatef(angle, 0.0, 1.0, 0.0);
    glutSolidTetrahedron();
    glTranslatef(0.0, 0.0, -.8);
    glPopMatrix();
  }

  if(controls[3]) {
    glPushMatrix();
    glColor3ub(255, 0, 0);
    glTranslatef(x - 2, z, y -1);
    glRotatef(25, 0.0, 1.0, 0.0);
    glRotatef(angle, 0.0, 1.0, 0.0);
    glutSolidTetrahedron();
    glTranslatef(0.0, 0.0, -.8);
    glPopMatrix();
  }


  if(controls[4]) {
    glPushMatrix();
    glColor3ub(255, 0, 0);
    glTranslatef(x + 2, z, y -1);
    glRotatef(25, 0.0, 1.0, 0.0);
    glRotatef(angle, 0.0, 1.0, 0.0);
    glutSolidTetrahedron();
    glTranslatef(0.0, 0.0, -.8);
    glPopMatrix();
  }

}

/*F***********************************************************
 * DEFAULT CONSTRUCTOR
 * 
 * NOTES :   
 *F*/
Ship::Ship() {
  x = 10;
  y = 5;
  z = 0;
}

/*F***********************************************************
 * draw(void)
 * 
 * PURPOSE : draws the ship onto the screen
 *
 * RETURN :  void
 *
 * NOTES :   Looks pretty awesome to me
 *F*/
void Ship::draw(std::vector <bool> controls) {

  angle += 5;
  glPushMatrix();
  glColor4f(.1, .2, .3, .8);
  glTranslatef(x, z, y);
  glutSolidSphere(1, 20, 20);
  glTranslatef(0.0, 0.0, -.8);
  glColor3ub(96, 96, 96);
  glutSolidTorus(.7, 1, 9, 9);
  glPopMatrix();

  animate(controls);
  //  glRotatef(.5, 1.0, 0.0, 0.0);
}
