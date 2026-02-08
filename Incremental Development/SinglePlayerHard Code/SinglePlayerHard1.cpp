#include "../Header Files/SingleplayerHard.h"

#include <stdlib.h>
#include <time.h>

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string SinglePlayerHard::setWord() {
  // if else statement for hard difficulty
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

    // first category(Sports hard)
    if (WordCategory == "1") {
      srand(time(0));
      ifstream file("Sports-Hard.txt");  // read file
      while (getline(file, line)) {
        total_lines++;
        lines.push_back(line);
      }
      random_number = rand();
      Word = lines[random_number];
    }
    // second category(Space hard)
    else if (WordCategory == "2") {
      srand(time(0));
      ifstream file("Space-Hard.txt");  // read file
      while (getline(file, line)) {
        total_lines++;
        lines.push_back(line);
      }
      random_number = rand();
      Word = lines[random_number];
    }
    // third category(Nature hard)
    if (WordCategory == "3") {
      srand(time(0));
      ifstream file("Nature-Hard.txt");  // read file
      while (getline(file, line)) {
        total_lines++;
        lines.push_back(line);
      }
      random_number = rand();
      Word = lines[random_number];
    }
    // fourth category(Random Subjects hard)
    else if (WordCategory == "4") {
      srand(time(0));
      ifstream file("Aussie-Hard.txt");  // read file
      while (getline(file, line)) {
        total_lines++;
        lines.push_back(line);
      }
      random_number = rand();
      Word = lines[random_number];
    }
    // Invalid input print
    else {
      flag3 = 0;
      cout << "Invalid Input. Retry." << endl;
    }
  }
  return Word;
}