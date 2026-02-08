#include "SaveSystem.h"
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// Checks for progress
bool ::SaveSystem::checkProgress() {
  ifstream read("progress.txt");
  if (!read) {
    return 0;
    return false;
  } else {
    return true;
  }
}
// Gets Player's score
int ::SaveSystem:: getScore() {
  playerScore = NumPoints;
  return playerScore;
}

// Saves to progress
void ::SaveSystem:: saveProgress() {
  std::ofstream out("progress.txt");

};