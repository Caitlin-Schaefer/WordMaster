#include "../CPP Files/Graphics.cpp"
#include "../Header Files/Game.h"
#include "../Header Files/Player.h"
#include "Multiplayer.cpp"
#include "Singleplayer.cpp"
#include "SingleplayerEasy.cpp"
#include "SingleplayerHard.cpp"

using namespace std;
#include <iostream>
#include <string>

int main() {
  // initializing class object
  Game Hangman;
  Graphics HangmanPicture;
  Save s1, s2, s3;
  string NumOfPlayers;
  string newLoad = "\0";
  int currentSlot;
  s1.loadProgress1();
  s2.loadProgress2();
  s3.loadProgress3();
  Save slots[3] = {s1, s2, s3};

  for (int i = 0; i < 3; i++) {
    Hangman.addSave(slots[i]);
  }

  // Determines whether the user wants to load a game or play a new game
  if (newLoad == "\0") {
    newLoad = Hangman.new_or_load();
  }

  if (newLoad == "L") {
    currentSlot = stoi(Hangman.loadGame());
  }

  if (newLoad == "N") {
    currentSlot = stoi(Hangman.newGame());
  }

  if (currentSlot == -200) {
    currentSlot = stoi(Hangman.loadGame());
  }

  if (currentSlot == -100) {
    currentSlot = stoi(Hangman.newGame());
  }
  // load game progress from save file
  switch (currentSlot) {
    case 1:
      Hangman.loadPoints(s1);
      break;
    case 2:
      Hangman.loadPoints(s2);
      break;
    case 3:
      Hangman.loadPoints(s3);
      break;
  }
  string UserPlayAgain = "Y";
  while (UserPlayAgain == "Y") {
    // Resets lives
    HangmanPicture.resetNumLives();
    Hangman.resetLives();
    Hangman.resetGuesses();

    // Determines whether the user is ready to commence the Hangman Game
    Hangman.is_player_ready();

    NumOfPlayers = Hangman.Number_of_Players();

    string Word;

    // Determines the mode the user wishes to play from Number of Players.
    if (NumOfPlayers == "2") {
      Player* TwoPlayer = new Multiplayer();
      Word = TwoPlayer->setWord();
    } else {
      string Difficulty;
      Singleplayer OnePlayer;
      Difficulty = OnePlayer.getDifficulty();
      if (Difficulty == "Hard") {
        Player* OnePlayerHard = new SinglePlayerHard();
        Word = OnePlayerHard->setWord();
      } else {
        Player* OnePlayerEasy = new SinglePlayerEasy();
        Word = OnePlayerEasy->setWord();
      }
    }
    // Defines the "Underscore" word which does not reveal letters that
    // have not been guesses
    Hangman.defineUnknownWord(Word);

    // While the user has not used all lives, and has not yet guessed the
    // word
    // the while loop will continue to execute
    cout << "The Word is " << Word.length() << " characters long." << endl;
    int NumLives = 0, CorrectGuess = 0, Increment, NumCorrect, i = 0;
    while ((NumLives < 6) && (CorrectGuess != Word.length())) {
      Hangman.PrintUnknownWord(Word);
      NumCorrect = Hangman.get_guess(Word);

      // If the incremented value is not equal to the previous Number of
      // correct guesses, it suggests the user has guessed correctly.
      Increment = CorrectGuess;
      CorrectGuess += NumCorrect;

      // Print the users guess logic based on input.
      if (CorrectGuess != Increment) {
        cout << "Correct Guess!" << endl;
      } else {
        cout << "Wrong Guess!" << endl;
        // The number of lives decreases.
        NumLives = Hangman.LoseLife();
        HangmanPicture.setNumLives(NumLives);
      }
      HangmanPicture.PrintHangmanGraphics();
    }
    // Determines whether the user won or lost, and displays the logic
    switch (currentSlot) {
      case 1:
        s1.setScore(Hangman.GameWL(NumLives, Word));
        break;
      case 2:
        s2.setScore(Hangman.GameWL(NumLives, Word));
        break;
      case 3:
        s3.setScore(Hangman.GameWL(NumLives, Word));
        break;
    }
    // save files
    s1.saveProgress1();
    s2.saveProgress2();
    s3.saveProgress3();

    // Determines whether the user wishes to replay the Hangman UserPlayAgain =
    UserPlayAgain = Hangman.PlayAgain();
  }
  // If the user does not want to play again, they are thanked for
  cout << "Thanks for Playing!" << endl;
  Hangman.clearProgress();
}