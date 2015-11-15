#pragma once
/*H***********************************************************
 * FILENAME :        ship.hpp
 *
 * DESCRIPTION : ship that the user controls and has to land
 *       
 *       
 *
 * PUBLIC FUNCTIONS :
 *       
 *
 * AUTHOR     :    Brigham Keys, Esq
 * START DATE :    07/23/2015
 *
 *H*/

#ifdef __MINGW32__
#include <windows.h>
#endif

#ifdef WIN32
#include <windows.h>
#endif
#include <vector>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <GL/freeglut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include "Vector3d.hpp"

class Ship : public Vector3d {

 public:
  Ship(void);
  void draw(std::vector <bool> controls);

 private:
  void animate(std::vector <bool> controls);
  float angle;

};
