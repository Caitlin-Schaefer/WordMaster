// include header file
#include "GuessWord.h"
#include "Mode.h"
#include "Multiplayer.cpp"
#include "Singleplayer.cpp"

using namespace std;
#include <iostream>

int main() {
  Mode UserMode;
  Multiplayer UserMultiplayer;
  SinglePlayer UserSinglePlayer;
  GuessWord UserWord;

  UserMode.is_player_ready();

  string Players;
  Players = UserMode.Number_of_Players();

  string Word;
  if (Players == "2") {
    Word = UserMultiplayer.user_input_word_to_guess();
    UserWord.setWord(Word);
    UserWord.setUnknown(Word);
  } else {
    Word = UserSinglePlayer.Word_Category();
    UserWord.setWord(Word);
    UserWord.setUnknown(Word);
  }
}