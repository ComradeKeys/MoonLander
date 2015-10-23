#pragma once
/*H***********************************************************
 * FILENAME :        Ground.hpp
 *
 * DESCRIPTION :
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

#include <stdlib.h>
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <vector>
#include "Platform.hpp"
#include "Vector3d.hpp"
#include "Tile.hpp"

class Ground : public Vector3d {

 public:
  Ground();
  virtual ~Ground();
  void draw(void);
  void update(std::vector<bool> controls);
  std::vector <std::vector<Tile> > floor;
  Platform *platform;

 private:
  int dim;
  std::vector <std::vector<float> > elev;
  void drawCircle(int x0, int y0, int radius, int height);
  void createMountain(int x, int y, int width);
  void createTerrain(void);
};
