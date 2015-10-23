#pragma once
/*H***********************************************************
 * FILENAME :        Tile.hpp
 *
 * DESCRIPTION : Each individual piece of the ground
 *       
 *
 * PUBLIC FUNCTIONS :
 *       void draw(void);
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

class Tile : public Vector3d {

 public:
  Tile();
  Tile(float xl, float yl, float zl);
  virtual void draw(void);
  void update(std::vector <bool> controls,
	      float x0 = 0, float y0 = 0, float z0 = 0);

 private:
  float xv;
  float yv;
  float zv;

};
