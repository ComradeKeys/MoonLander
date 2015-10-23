#pragma once
/*H***********************************************************
 * FILENAME :        Platform.hpp
 *
 * DESCRIPTION : User lands on this to win the game
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
#include "Tile.hpp"

class Platform : public Tile {

 public:
  Platform(float x0 = 0, float z0 = 0);
  virtual void draw(void);
 private:
};
