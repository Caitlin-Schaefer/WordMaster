#ifndef MODE_H
#define MODE_H

#include <stdlib.h>

#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Mode {
 private:
  string PlayerReady = "\0";

 protected:
  string NumPlayers;
  int flag1 = 0;
  string Word;

 public:
  void is_player_ready();
  string Number_of_Players();
  virtual void setWord() = 0;
};

class Multiplayer : public Mode {
 private:
  int flag2 = 0;
  string Empty = "";

 protected:
  string Word;

 public:
  void SetWord();
  string GetWord();
};

class SinglePlayer : public Mode {
 private:
  int flag3 = 0;
  string WordCategory;
  string difficulty;
  string line;
  vector<string> lines;
  int total_lines = 0;
  int random_number;

 protected:
  string Word;

 public:
  void SetWord();
};

class GuessWord : public Multiplayer, public SinglePlayer {
 private:
  string Guess;
  int flag = 0, FindGuess, j = 0, k = 0, L = 0, NumNotGuessed = 0;

 protected:
  string Word, AllGuesses, WrongLetters, UnknownWord;
  int NumLife = 0;

 public:
  bool UserGuess(string Word);
};

#endif