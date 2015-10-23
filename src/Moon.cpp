#include "Moon.hpp"

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
void Moon::draw(std::vector <bool> controls) {
  
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  ground->draw();
  ship->draw(controls);
}

/*F***********************************************************
 * 
 * 
 * PURPOSE : 
 *
 * RETURN :  
 *
 * NOTES :   
 *F*/
bool Moon::update(std::vector <bool> controls) {
 
  ground->update(controls);

  //collision checking
  for(int i = 0; i < ground->floor.size(); ++i) {
    for(int j = 0; j < ground->floor.size(); ++j) {
      if(ground->floor[i][j].y >= ship->y - 1.7 &&
	 ground->floor[i][j].y <= ship->y + 1.7 &&
	 ground->floor[i][j].x >= ship->x - 1.7 && 
	 ground->floor[i][j].x <= ship->x + 1.7 && 
	 ground->floor[i][j].z >= ship->z - 1.7 &&
	 ground->floor[i][j].z <= ship->z + 1.7) {
         
	delete ground;
	ground = new Ground();
      }
    }
  }

  //collision with platform
  if(ground->platform->y >= 14 &&
     ground->platform->y <= 16 &&
     ground->platform->z >= ship->z - 4 &&
     ground->platform->z <= ship->z + 4 &&
     ground->platform->x >= ship->x - 3.5 &&
     ground->platform->x <= ship->x + 3.5) {

    //we won
    ground->x = ship->x - 1.7;    
    ground->y = ship->y - 1.7;    
    ground->z = ship->z - 1.7;    
    return true;
  }

  //collision with platform
  if(ground->platform->y <= 14 &&
     ground->platform->z <= ship->z - 4 &&
     ground->platform->x <= ship->x - 3.5) {

      delete ground;
      ground = new Ground();
  }

  //we did not win
  return false;
}

/*F***********************************************************
 * 
 * 
 * PURPOSE : 
 *
 * RETURN :  
 *
 * NOTES :   
 *F*/
Moon::Moon() {
  
  glRotatef(20, 1.0, 0.0, 0.0);
  ship = new Ship();
  ground = new Ground();
}
