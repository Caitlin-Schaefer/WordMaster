#include "../Header Files/Save.h"

#include <stdlib.h>

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
// function to load game on save slot 1
void Save::loadProgress1() {
  ifstream load("../Save Slots/save1.txt");
  while (getline(load, strPoints)) {
    playerPoints = stoi(strPoints);
  }
  load.close();
}
// function to load game on save slot 2
void Save::loadProgress2() {
  ifstream load("../Save Slots/save2.txt");
  while (getline(load, strPoints)) {
    playerPoints = stoi(strPoints);
  }
  load.close();
}
// function to load game on save slot 3
void Save::loadProgress3() {
  ifstream load("../Save Slots/save3.txt");
  while (getline(load, strPoints)) {
    playerPoints = stoi(strPoints);
  }
  load.close();
}
// function to save game on save slot 1
void Save::saveProgress1() {
  ofstream save;
  save.open("../Save Slots/save1.txt");
  if (save.is_open()) {
    if (playerPoints < 0) {
      playerPoints = 0;
    }
    // store contents to text file
    save << playerPoints << "\n";
    save.close();
  } else {
    cout << "Problem with opening file";
  }
}
// function to save game on save slot 2
void Save::saveProgress2() {
  ofstream save;
  save.open("../Save Slots/save2.txt");
  if (save.is_open()) {
    if (playerPoints < 0) {
      playerPoints = 0;
    }
    // store contents to text file
    save << playerPoints << "\n";
    save.close();
  } else {
    cout << "Problem with opening file";
  }
}
// function to save game on save slot 1
void Save::saveProgress3() {
  ofstream save;
  save.open("../Save Slots/save3.txt");
  if (save.is_open()) {
    if (playerPoints < 0) {
      playerPoints = 0;
    }
    // store contents to text file
    save << playerPoints << "\n";
    save.close();
  } else {
    cout << "Problem with opening file";
  }
}
// save the player score
int Save::getScore() { return playerPoints; }

int Save::setScore(int numPoints) {
  playerPoints = numPoints;
  return playerPoints;
}