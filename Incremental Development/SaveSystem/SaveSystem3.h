#ifndef SAVESYSTEM_H
#define SAVESYSTEM_H
#include <stdlib.h>
#include "ScoreSystem.h"
#include "GuessWord.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class SaveSystem: public ScoreSystem, protected GuessWord{
 private:
    int playerScore;
    string *guessedWords = new string[20];
 public:
    bool checkProgress();
    int getScore();
    string addGuessedWords();
    void saveProgress();
};
#endif