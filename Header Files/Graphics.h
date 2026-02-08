#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "Game.h"

class Graphics: protected Game {

 public:
  // function for printing the hangman graphics
  void setNumLives(int NumLives);
  void PrintHangmanGraphics();
  void resetNumLives();
};

#endif /* GRAPHICS_H */
