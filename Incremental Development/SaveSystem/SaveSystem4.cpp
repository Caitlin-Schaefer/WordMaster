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
  ifstream loading;
  loading.open("/Users/kj/Documents/PR03-PROJECT/progress.txt");
  string strPoints;
  while (getline(loading, strPoints)) {
    cout << strPoints << " ";
    playerScore = stoi(strPoints);
  }
  loading.close();
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
int ::SaveSystem::getScore() {

// Saves to progress
void ::SaveSystem::saveProgress() {
    ofstream save;
  save.open("/Users/kj/Documents/PR03-PROJECT/progress.txt");
    if(save.is_open())
    {
      //store contents to text file
      save << playerScore << "\n";
      save <<"";
      save.close();
    }
    else{
      cout << "Problem with opening file";
    } 
}
