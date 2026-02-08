
#include "ScoreSystem.h"
#include <string>

using namespace std;
#include <iostream>

// point reward system
int ScoreSystem::PointSystem(int Num_Guesses, string GuessedLetters) {
  // give points based on the difficulty
  if (Num_Guesses == 6) {
    NumPoints += GuessedLetters.length();
  }
  if (difficulty == "Easy") {
    if (Num_Guesses > 0) {
      NumPoints += 5;
      cout << "5 Points Awared! Congratulations!" << endl;
    }
  }
  if (difficulty == "Hard") {
    if (Num_Guesses > 0) {
      NumPoints += 10;
      cout << "10 Points Awared! Congratulations!" << endl;
    }
  }
  return NumPoints;
}