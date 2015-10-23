#include "MoonGame.hpp"

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
MoonGame::MoonGame() {

  font = new Font();
  fuelUsed = 0;
  for(int i = 0; i < 5; ++i) {
    controls.push_back(false);
  }
  moon = new Moon();
  glRotated(90, -1.0, 0.0, 0.0);
}

/*F***********************************************************
 * DESTRUCTOR
 * 
 * NOTES :   
 *F*/
MoonGame::~MoonGame() {}

/*F***********************************************************
 * 
 * 
 * PURPOSE : 
 *
 * RETURN :  
 *
 * NOTES :   
 *F*/
void MoonGame::run(void) {

  SDL_Event event;
  Uint32 start;
  const int FPS = 60;

  while(isRunning) {
    start = SDL_GetTicks();
    if(glGetError() != GL_NO_ERROR) {
      exit(1);
    }

    while(SDL_PollEvent(&event) != 0) {

      switch(event.type){

      case SDL_KEYDOWN:
	keyboard(event, true);
	break;

      case SDL_KEYUP:
	keyboard(event, false);
	break;

      case SDL_QUIT:
	isRunning = false;
	break;
      }
    }

    if(!paused) {
      while(moon->update(controls)) {
	while(true) {
	  //we won
	  moon->draw(controls);
	  keyboard(event, true);
	}
      }
    }
    moon->draw(controls);
    SDL_RenderPresent(displayRenderer);
    if(1000/FPS > SDL_GetTicks() - start) {
      SDL_Delay(1000/FPS - (SDL_GetTicks() - start));
    }
  }
}

/*F***********************************************************
 * keyboard(const SDL_Event &event)
 * 
 * PURPOSE : handles keyboard input for controlling the snake
 *
 * RETURN :  void
 *
 * NOTES :   pause functionality needs work
 *F*/
void MoonGame::keyboard(const SDL_Event &event, bool set) {

  switch(event.key.keysym.scancode) {

  case SDL_SCANCODE_P:
    if(!paused) {
      paused = true;
    } else {
      paused = false;
    }
    return;

  case SDL_SCANCODE_Q:
    isRunning = false;
    break;
    //back
  case SDL_SCANCODE_W:
    controls[2] = set;
    break;

    //forward
  case SDL_SCANCODE_S:
    controls[1] = set;
    break;

    //right
  case SDL_SCANCODE_A:
    controls[3] = set;
    break;

    //left
  case SDL_SCANCODE_D:
    controls[4] = set;
    break;

    //up
  case SDL_SCANCODE_SPACE:
    fuelUsed++;
    controls[0] = set;
    break;
  }
  glFlush();
  glFinish();
}
