#ifdef __MINGW32__
#include <windows.h>
#endif

#ifdef WIN32
#include <windows.h>
#endif
#include "MoonGame.hpp"

/*F***********************************************************
 * main(int argc, char **argv)
 * 
 * PURPOSE : entry into the program
 *
 * RETURN :  int
 *
 * NOTES :   Best viewed with emacs
 *F*/
int main(int argc, char *argv[]) {

  MoonGame *f = new MoonGame();
  f->run();
  return 0;
}
