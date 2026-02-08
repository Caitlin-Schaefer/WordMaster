#include "ScoreSystem.h"

#include <string>
using namespace std;
#include <iostream>

// point reward system
int ScoreSystem::PointSystem(int Num_Guesses, string GuessedLetters) {
  if (Num_Guesses == 6) {
    NumPoints += GuessedLetters.length();
  } else {
    if (GuessedLetters.length() < 5) {
      NumPoints += 5;
      cout << "5 Points Awared! Congratulations!" << endl;
    } else {
      NumPoints += 10;
      cout << "10 Points Awared! Congratulations!" << endl;
    }
  }
  return NumPoints;
}

