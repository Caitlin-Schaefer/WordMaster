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
    // give information to the user what are the available categories
    cout << "Please select a category from one of the following: " << endl
         << "Sports (1): Basketball, Football, Cricket, Tennis" << endl
         << "Space (2): Planets, Stars, Gravity" << endl
         << "Nature (3): Animals, trees, plants, climate" << endl
         << "Other (4): Unknown..." << endl;
    cout << "Category (1,2,3,4): ";
    cin >> WordCategory;

    // use while loop to ask user easy or hard difficulty
    while (difficulty != tolower(Easy) || difficulty != tolower(Hard) ||
           difficulty != toupper(Easy) || difficulty != toupper(Hard)) {
      cout << "Enter difficulty level : " << endl;
      cin >> difficulty;
    }
    if (difficulty == Easy || difficulty == toupper(Easy)) {
      // first category(Sports)
      if (WordCategory == "1") {
        srand(time(0));
        ifstream file("Sports-Easy.txt");  // read file
        while (getline(file, line)) {
          total_lines++;
          lines.push_back(line);
        }
        random_number = rand();
        Word = lines[random_number];

        // second category(Space)
      } else if (WordCategory == "2") {
        srand(time(0));
        ifstream file("Space-Easy.txt");  // read file
        while (getline(file, line)) {
          total_lines++;
          lines.push_back(line);
        }
        random_number = rand();
        Word = lines[random_number];
        // third category(Nature)
      } else if (WordCategory == "3") {
        srand(time(0));
        ifstream file("Nature-Easy.txt");  // read file
        while (getline(file, line)) {
          total_lines++;
          lines.push_back(line);
        }
        random_number = rand();
        Word = lines[random_number];

        // fourth category(Random Subjects)
      } else if (WordCategory == "4") {
        srand(time(0));
        ifstream file("Aussie-Easy.txt");  // read file
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
  if (difficulty == tolower(Hard) || difficulty == toupper(Hard)) {
    // first category(Sports)
    if (WordCategory == "1") {
      srand(time(0));
      ifstream file("Sports-Hard.txt");  // read file
      while (getline(file, line)) {
        total_lines++;
        lines.push_back(line);
      }
      random_number = rand();
      Word = lines[random_number];

      // second category(Space)
    } else if (WordCategory == "2") {
      srand(time(0));
      ifstream file("Space-Hard.txt");  // read file
      while (getline(file, line)) {
        total_lines++;
        lines.push_back(line);
      }
      random_number = rand();
      Word = lines[random_number];
      // third category(Nature)
    } else if (WordCategory == "3") {
      srand(time(0));
      ifstream file("Nature-Hard.txt");  // read file
      while (getline(file, line)) {
        total_lines++;
        lines.push_back(line);
      }
      random_number = rand();
      Word = lines[random_number];

      // fourth category(Random Subjects)
    } else if (WordCategory == "4") {
      srand(time(0));
      ifstream file("Aussie-Hard.txt");  // read file
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