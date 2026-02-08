#ifndef SAVESYSTEM_H
#define SAVESYSTEM_H
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "GameCode.h"
#include "ScoreSystem.h"
using namespace std;

class SaveSystem : public ScoreSystem, protected GuessWord {
 private:
 int playerScore = 0;

 public:
  SaveSystem() = default;
  void clear();
  void loadProgress();
  int getScore();
void saveProgress();
};

#endif