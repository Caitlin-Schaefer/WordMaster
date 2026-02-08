#include "Singleplayer.h"

#include <stdlib.h>
#include <time.h>

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void SinglePlayer::SetWord() {
  // ask user what difficulty level they want to play
  cout << "Enter difficulty level : " << endl;
  cin >> difficulty;
  // use while loop to keep asking the user easy or hard difficulty
  while (difficulty != "Easy" || difficulty != "Hard") {
    // I will fix the the code so that it would take both uppercase and
    // lowercase letter
    cout << "Enter difficulty level : " << endl;
    cin >> difficulty;
  }

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

    if (difficulty == "Easy") {
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

        // second category(Space easy)
      } else if (WordCategory == "2") {
        srand(time(0));
        ifstream file("Space-Easy.txt");  // read file
        while (getline(file, line)) {
          total_lines++;
          lines.push_back(line);
        }
        random_number = rand();
        Word = lines[random_number];
        // third category(Nature easy)
      } else if (WordCategory == "3") {
        srand(time(0));
        ifstream file("Nature-Easy.txt");  // read file
        while (getline(file, line)) {
          total_lines++;
          lines.push_back(line);
        }
        random_number = rand();
        Word = lines[random_number];

        // fourth category(Random Subjects easy)
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
  if (difficulty == "Hard") {
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

      // second category(Space hard)
    } else if (WordCategory == "2") {
      srand(time(0));
      ifstream file("Space-Hard.txt");  // read file
      while (getline(file, line)) {
        total_lines++;
        lines.push_back(line);
      }
      random_number = rand();
      Word = lines[random_number];
      // third category(Nature hard)
    } else if (WordCategory == "3") {
      srand(time(0));
      ifstream file("Nature-Hard.txt");  // read file
      while (getline(file, line)) {
        total_lines++;
        lines.push_back(line);
      }
      random_number = rand();
      Word = lines[random_number];

      // fourth category(Random Subjects hard)
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