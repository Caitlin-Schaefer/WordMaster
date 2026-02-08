#include "../Header Files/Game.h"

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// Determines whether the player is ready to commence the game.
void Game::is_player_ready() {
  while (isPlayerReady != "Y") {
    cout << "Are your ready to commence the game (Y): ";
    cin >> isPlayerReady;
  }
}

// Determines if user wishes to begin a new game, or load a previous game
string Game::new_or_load() {
  while ((newOrLoad != "N") && (newOrLoad != "L")) {
    cout << "New or load game? (N or L): ";
    cin >> newOrLoad;
  }
  return newOrLoad;
}

// Adds Save objects to dynamic array
bool Game::addSave(Save newSave) {
  if ((newSave.getScore() > 0) && (numSaves < 3)) {
    saveSlots[numSaves] = newSave;
    numSaves++;
    return true;
  } else {
    return false;
  }
}

// Selects save slot to save in when user chooses new game
string Game::newGame() {
  if (numSaves == 0) {
    newGameSave = "1";
  } else {
    newGameSave = to_string(numSaves + 1);
  }
  if (newGameSave == "4") {
    cout << "Too many save slots, load a game instead: " << endl;
    return "-200";
  }
  cout << "Using save slot"
       << " " << newGameSave << endl;
  return newGameSave;
}

// Selects save slot to use when user wishes to load
string Game::loadGame() {
  if (numSaves == 0) {
    cout << "Cannot load, no saved data." << endl
         << "Creating new game" << endl;
    ;
    return "-100";
  }
  while ((loadGameSave != to_string(numSaves)) &&
         (loadGameSave != to_string(numSaves - 1)) &&
         (loadGameSave != to_string(numSaves - 2))) {
    cout << "Which game would you like to load? (input slot number) :" << endl;
    for (int i = 0; i < numSaves; i++) {
      cout << "Slot"
           << " " << i + 1 << " "
           << "(Points: " << saveSlots[i].getScore() << ")" << endl;
    }
    cin >> loadGameSave;
    while ((loadGameSave == "0") || (loadGameSave == "-1")) {
      cout << "Enter a valid input : " << endl;
      cin >> loadGameSave;
    }
  }
  return loadGameSave;
}

// Clear saves
void Game::clearProgress() {
  numSaves = 0;
  delete[] saveSlots;
}

// loads points to a slot
int Game::loadPoints(Save slot) {
  NumPoints = slot.getScore();
  return NumPoints;
}

// Asks user for number of Players
string Game::Number_of_Players() {
  while ((NumPlayers != "1") && (NumPlayers != "2")) {
    cout << "How many Players (1 or 2): ";
    cin >> NumPlayers;
  }
  return NumPlayers;
}

// Defines and prints the unknown word
void Game::defineUnknownWord(string Word) {
  for (int i = 0; i < Word.length(); i++) {
    UnknownWord[i] = 95;
  }
}
void Game::PrintUnknownWord(string Word) {
  for (int i = 0; i < Word.length(); i++) {
    cout << UnknownWord[i];
  }
  cout << endl;
}

// Attain a guess from the user
int Game::get_guess(string Word) {
  cout << "Enter a letter: ";
  cin >> UserGuess;
  // while loop to keep asking guess from the user
  flag = 0;
  while (flag != 1) {
    flag = 1;

    while (isdigit(UserGuess[0]) != 0 || (UserGuess.size() != 1)) {
      cout << "Invalid Input. Retry" << endl;
      cout << "Enter a letter: ";
      cin >> UserGuess;
      flag = 0;
    }
    for (int i = 0; i < k; i++) {
      if (UserGuess[0] == AllGuesses[i]) {
        cout << "Already Guessed. Retry" << endl;
        cout << "Enter a letter: ";
        cin >> UserGuess;
        flag = 0;
        break;
      }
    }
  }
  // convert all guesses into lower case letter
  UserGuess = ::tolower(UserGuess[0]);
  AllGuesses[k] = UserGuess[0];
  k++;

  CorrectGuess = 0;
  // for loop to check if the guess letter is a correct guess
  for (int i = 0; i < Word.length(); i++) {
    if (UserGuess[0] == Word[i]) {
      UnknownWord[i] = Word[i];
      CorrectGuess++;
    }
  }

  return CorrectGuess;
}
// function to return the number of lives the user has
int Game::LoseLife() {
  NumLives++;
  return NumLives;
}

// Determines whether the user won or lost the game
int Game::GameWL(int NumLives, string Word) {
  cout << endl;
  if (NumLives < 6) {
    cout << "Game Won! Congratulations! The word was: " << Word << endl;
    // award the user with points
    if (Word.length() < 5) {
      NumPoints += 5;
      cout << "5 points awarded; The Total so far is: " << NumPoints << endl;
    } else {
      NumPoints += 10;
      cout << "10 points awarded; The Total so far is: " << NumPoints << endl;
    }
    // give penalty if user lost the game
  } else {
    cout << "Game Lost! The word was: " << Word << endl;
    NumPoints -= 5;
    cout << "5 points lost; The Total so far is: " << NumPoints << endl;
  }
  return NumPoints;
}

// asks user if they wish to play again
string Game::PlayAgain() {
  UserPlayAgain = "";
  while (UserPlayAgain != "Y" && UserPlayAgain != "N") {
    cout << "Would you like to play again(Y/N)? ";
    cin >> UserPlayAgain;
  }
  system("clear");
  return UserPlayAgain;
}

// resets lives
void ::Game::resetLives() { NumLives = 0; }
void Game::resetGuesses() {
  AllGuesses.clear();
  k = 0;
}