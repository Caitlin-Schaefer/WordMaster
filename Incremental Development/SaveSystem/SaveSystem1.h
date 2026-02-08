#ifndef SAVESYSTEM_H
#define SAVESYSTEM_H
#include <stdlib.h>

#include "ScoreSystem.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class SaveSystem {
class SaveSystem: public ScoreSystem {
 private:
    int playerScore;
 public:
  bool checkProgress();
  int getScore();
  void saveProgress();
    bool checkProgress();
    int getScore();
    void saveProgress();
};

#endif