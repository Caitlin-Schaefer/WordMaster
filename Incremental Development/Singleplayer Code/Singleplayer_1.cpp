#include <stdlib.h>
#include <time.h>

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "GameCode.h"

using namespace std;

string SinglePlayer::SetWord() {
  while (flag3 == 0) {
    flag3 = 1;

    cout << "Please select a category from one of the following: " << endl
         << "Sports (1): Basketball, Football, Cricket, Tennis" << endl
         << "Space (2): Planets, Stars, Gravity" << endl
         << "Nature (3): Animals, trees, plants, climate" << endl
         << "Other (4): Unknown..." << endl;
    cout << "Category (1,2,3,4): ";
    cin >> WordCategory;

    if (WordCategory == "1") {
      srand(time(0));
      ifstream file("Sports.txt");
      while (getline(file, line)) {
        total_lines++;
        lines.push_back(line);
      }
      random_number = rand();
      Word = lines[random_number];
    } else if (WordCategory == "2") {
      srand(time(0));
      ifstream file("Space.txt");
      while (getline(file, line)) {
        total_lines++;
        lines.push_back(line);
      }
      random_number = rand();
      Word = lines[random_number];
    } else if (WordCategory == "3") {
      srand(time(0));
      ifstream file("Nature.txt");
      while (getline(file, line)) {
        total_lines++;
        lines.push_back(line);
      }
      random_number = rand();
      Word = lines[random_number];
    } else if (WordCategory == "4") {
      srand(time(0));
      ifstream file("Aussie.txt");
      while (getline(file, line)) {
        total_lines++;
        lines.push_back(line);
      }
      random_number = rand();
      Word = lines[random_number];
    } else {
      flag3 = 0;
      cout << "Invalid Input. Retry." << endl;
    }
  }
}