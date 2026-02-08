#include "../Header Files/Singleplayer.h"

#include <stdlib.h>
#include <time.h>

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string Singleplayer::getDifficulty() {
  // ask user what difficulty level they want to play
  cout << "Enter difficulty level (Easy, Hard): ";
  cin >> difficulty;
  // use while loop to keep asking the user easy or hard difficulty
  while (difficulty != "Easy" && difficulty != "Hard") {
    // I will fix the the code so that it would take both uppercase and
    // lowercase words
    cout << "Enter difficulty level (Easy, Hard): ";
    cin >> difficulty;
  }
  return difficulty;
}
