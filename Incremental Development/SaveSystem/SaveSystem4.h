#ifndef SAVESYSTEM_H
#define SAVESYSTEM_H
#include <stdlib.h>

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "GameCode.h"
#include "ScoreSystem.h"
#include "progress.txt"
using namespace std;

class SaveSystem : public ScoreSystem, protected GuessWord {
 private:
 int playerScore = 10;
  string *guessedWords = new string[20];

 public:
 SaveSystem() = default;
  void clear();
  void loadProgress();
  int getScore();
  string addGuessedWords();
  void saveProgress();
  };
#endif