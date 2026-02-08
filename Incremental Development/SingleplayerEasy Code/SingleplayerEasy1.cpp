#include <stdlib.h>
#include <time.h>

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "../Header Files/SingleplayerEasy.h"

using namespace std;

string SinglePlayerEasy::setWord() {
  while (flag == 0) {
    flag = 1;
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
      srand(time(0));
      ifstream file("Sports-Easy.txt");  // read file
      while (getline(file, line)) {
        total_lines++;
        lines.push_back(line);
      }
      random_number = rand();
      Word = lines[random_number];
    }
    // second category(Space easy)
    else if (WordCategory == "2") {
      srand(time(0));
      ifstream file("Space-Easy.txt");  // read file
      while (getline(file, line)) {
        total_lines++;
        lines.push_back(line);
      }
      random_number = rand();
      Word = lines[random_number];
    }
    // third category(Nature easy)
    else if (WordCategory == "3") {
      srand(time(0));
      ifstream file("Nature-Easy.txt");  // read file
      while (getline(file, line)) {
        total_lines++;
        lines.push_back(line);
      }
      random_number = rand();
      Word = lines[random_number];
    }

    // fourth category(Random Subjects easy)
    else if (WordCategory == "4") {
      srand(time(0));
      ifstream file("Aussie-Easy.txt");  // read file
      while (getline(file, line)) {
        total_lines++;
        lines.push_back(line);
      }
      random_number = rand();
      Word = lines[random_number];
    } else {
      flag = 0;
      cout << "Invalid Input. Retry." << endl;
    }
  }
  return Word;
}
