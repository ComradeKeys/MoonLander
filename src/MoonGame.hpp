#pragma once
/*H***********************************************************
 * FILENAME :        MoonGame.h
 *
 * DESCRIPTION :
 *       Contains the entire game.
 *
 * PUBLIC FUNCTIONS :
 *       void run(); //main game loop
 *
 * AUTHOR     :    Brigham Keys, Esq
 * START DATE :    07/31/2015
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
#include <GL/glu.h>
#include <GL/gl.h>
#include "Game.hpp"
#include "Moon.hpp"
#include "Font.hpp"

class MoonGame : public Game {

 public:
  MoonGame();
  virtual ~MoonGame();
  void run();

 private:
  Font *font;
  void keyboard(const SDL_Event &event, bool set);
  unsigned int fuelUsed;
  std::vector<bool> controls;
  Moon *moon;
};
