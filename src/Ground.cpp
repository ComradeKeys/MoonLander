#include "Ground.hpp"

/*F***********************************************************
 * drawCircle(int x0, int y0, int radius, int height);
 * 
 * PURPOSE : draws a round circle in the terrain
 *
 * RETURN :  void
 *
 * NOTES :   Uses the midpoint circle algorith to create
 *           a round base for the landscape
 *F*/

void Ground::drawCircle(int x0, int y0,
			int radius, int height) {
  int x = radius;
  int y = 0;

   // Decision criterion divided by 2 evaluated at x=r, y=0
  int decisionOver2 = 1 - x;

  while(y <= x) {
    elev[ x + x0][ y + y0] = height;
    elev[ y + x0][ x + y0] = height;
    elev[-x + x0][ y + y0] = height;
    elev[-y + x0][ x + y0] = height;
    elev[-x + x0][-y + y0] = height;
    elev[-y + x0][-x + y0] = height;
    elev[ x + x0][-y + y0] = height;
    elev[ y + x0][-x + y0] = height;
    y++;
    if(decisionOver2<=0) {
      decisionOver2 += 2 * y + 1;   // Change in decision criterion for y -> y+1
    } else {
      x--;
      decisionOver2 += 2 * (y - x) + 1;   // Change for y -> y+1, x -> x-1
    }
  }
}

void Ground::createMountain(int x, int y, int width = rand() % 10) {
  for(int i = 0; i < width; ++i) {
    drawCircle(x, y, width - (i), i);
  }
}

/*F***********************************************************
 * 
 * 
 * PURPOSE : Randomly generates a terrain
 *
 * RETURN :  
 *
 * NOTES :   function should be renamed to createTerrain
 *F*/
void Ground::createTerrain() {

  for(int i = 20; i < elev.size() - 20; ++i) {
    for(int j = 20; j < elev.size() - 20; ++j) {
      if(!(rand() % 10)) {
	createMountain(i, j);
      }
      if(rand() % 2) {
	elev[i][j] = .2;
      }
    }
  }
}

/*F***********************************************************
 * draw(void)
 * 
 * PURPOSE : draws the ground onto the screen
 *
 * RETURN :  void
 *
 * NOTES :   
 *F*/
void Ground::draw(void) {

  for(int i = 0; i < floor.size(); ++i) {
    for(int j = 0; j < floor.size(); ++j) {
      floor[i][j].draw();
    }
  }
  platform->draw();
  //  glRotatef(5, 1.0, 0.0, 0.0);
}

/*F***********************************************************
 * draw(void)
 * 
 * PURPOSE : draws the ground onto the screen
 *
 * RETURN :  void
 *
 * NOTES :   
 *F*/
void Ground::update(std::vector <bool> controls) {

  for(int i = 0; i < floor.size(); ++i) {
    for(int j = 0; j < floor.size(); ++j) {
      floor[i][j].update(controls);
    }
  }
  platform->update(controls);
}

/*F***********************************************************
 * DEFAULT CONSTRUCTOR
 * 
 * NOTES :   has performance issues on larger maps
 *F*/
Ground::Ground() {

  dim = 25;
  platform = new Platform(rand() % dim, rand () % dim);

  for(int i =  -(dim/2); i < (dim/2); ++i) {
    std::vector <float> row (dim);
    elev.push_back(row);
  }

  createTerrain();

  for(int i =  -(dim/2); i < (dim/2); ++i) {
    std::vector <Tile> row;
    for(int j =  -(dim/2); j < (dim/2); ++j) {
      Tile t(i + x, elev[i + (dim/2)][j + (dim/2)] - 14 + y, j + z);
      row.push_back(t);
     }
    floor.push_back(row);
  }
}

/*F***********************************************************
 * DEFAULT DESTRUCTOR
 * 
 * NOTES :   
 *F*/
Ground::~Ground() {}
