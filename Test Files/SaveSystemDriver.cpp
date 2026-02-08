#include <stdlib.h>

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "../Header Files/Game.h"
using namespace std;
int main() {
  Game *save;
  // int theScore = save->getScore(10);
  save->saveProgress(10);
  save->loadProgress();
  save->clear();
}