#include <stdlib.h>

#include <ctime>
#include <iostream>
#include <string>

#include "../Header Files/Player.h"

using namespace std;
// function to get the puzzle from difficulty easy
string SinglePlayerEasy::setWord() {
  while (flag3 == 0) {
    flag3 = 1;
    // give information to the user what are the available categories
    cout << "Please select a category from one of the following: " << endl
         << "Sports (1): Basketball, Football, Cricket, Tennis" << endl
         << "Space (2): Planets, Stars, Gravity" << endl
         << "Nature (3): Animals, trees, plants, climate" << endl
         << "Other (4): Unknown..." << endl;
    cout << "Category (1,2,3,4): ";
    cin >> WordCategory;

    // first category(Sports easy)
    if (WordCategory == "1") {
      // get random words from the array
      srand(time(0));
      int random = rand() % 7;
      Word = SportEasy[random];
      break;
    } else if (WordCategory == "2") {
      // get random words from the array
      srand(time(0));
      int random = rand() % 7;
      Word = SpaceEasy[random];
      break;
    } else if (WordCategory == "3") {
      // get random words from the array
      srand(time(0));
      int random = rand() % 7;
      Word = NatureEasy[random];
      break;
    } else if (WordCategory == "4") {
      // get random words from the array
      srand(time(0));
      int random = rand() % 7;
      Word = AussieEasy[random];
      break;
    } else {
      flag3 = 0;
      cout << "Invalid Input. Retry." << endl;
    }
  }
  system("clear");
  return Word;
}
