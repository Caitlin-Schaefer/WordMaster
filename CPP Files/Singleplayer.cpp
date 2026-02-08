#include <stdlib.h>

#include <ctime>
#include <iostream>
#include <string>

#include "../Header Files/Player.h"

using namespace std;
// function to get difficulty level from user
string Singleplayer::getDifficulty() {
  // ask user what difficulty level they want to play
  cout << "Enter difficulty level (Easy, Hard): ";
  cin >> difficulty;
  // use while loop to keep asking the user easy or hard difficulty
  while (difficulty != "Easy" && difficulty != "Hard") {
    cout << "Enter difficulty level (Easy, Hard): ";
    cin >> difficulty;
  }
  cout << endl;
  return difficulty;
}
