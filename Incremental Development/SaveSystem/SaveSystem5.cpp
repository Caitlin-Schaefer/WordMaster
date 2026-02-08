#include "SaveSystem.h"
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Checks for progress
void SaveSystem::loadProgress()
  {
  string strPoints;
  ifstream load("/Users/kj/Documents/PR03-PROJECT/progress.txt");
  while (getline (load,strPoints)) {
    playerScore = stoi(strPoints);
  }
  cout << playerScore;
  load.close();
}

//clears data
void ::SaveSystem::clear() {
  ofstream clear;
  clear.open("/Users/kj/Documents/PR03-PROJECT/progress.txt");
  clear<<"";
}


// Gets Player's score
int ::SaveSystem::getScore() {
  playerScore = NumPoints;
  return playerScore;
}

// Saves to progress
void ::SaveSystem::saveProgress() {
  ofstream save;
  save.open("/Users/kj/Documents/PR03-PROJECT/progress.txt");
    if(save.is_open())
    {
      //store contents to text file
      save << playerScore << "\n";
      save.close();
    }
    else{
      cout << "Problem with opening file";
    } 
}