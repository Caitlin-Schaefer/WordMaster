#include "GameCode.h"
#include "GuessWord.cpp"
#include "Multiplayer.cpp"
#include "Singleplayer.cpp"

using namespace std;
#include <iostream>

int main() {

  int mode;

  cin >> mode;

  Multiplayer* game;

  if(mode == 1) {
    // game = new SinglePlayer();
  } else {
    game = new Multiplayer();
  }

  game->setWord();