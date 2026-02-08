#ifndef PLAYER_H
#define PLAYER_H

using namespace std;
#include <string>

class Player {
 public:
  virtual string setWord() = 0;
};

class Multiplayer : public Player {
  // initialize variables used in class multiplayer
 private:
  int flag = 0;
  string Empty = "";
  string Word;

 public:
  string setWord();
};

class Singleplayer {
  // initialize variables used in class singleplayer
 protected:
  string difficulty;
  int flag3 = 0;
  string WordCategory;
  string Word;

 public:
  // function for the cpp files
  string getDifficulty();
};

class SinglePlayerEasy : public Singleplayer, public Player {
 protected:
  // Array of words to guess
  string AussieEasy[7] = {"bloke",   "mate",    "mozzie", "kangaroo",
                          "crickey", "sunnies", "koala"};
  string NatureEasy[7] = {"cave",    "environment", "meadow", "rainforest",
                          "volcano", "desert",      "valley"};
  string SpaceEasy[7] = {"martian", "jupiter",       "mercury", "interstellar",
                         "solar",   "intergalactic", "wormhole"};
  string SportEasy[7] = {"soccer",     "fitness", "skiing",  "coaching",
                         "gymnastics", "esports", "baseball"};

 private:
  int flag = 0;
  string WordCategory;

 public:
  // function for the cpp files
  string setWord();
};

class SinglePlayerHard : public Singleplayer, public Player {
 protected:
  // array of words to guess
  string AussieHard[7] = {"brekkie", "bathers", "heaps",  "battler",
                          "servo",   "yakka",   "outback"};
  string NatureHard[7] = {"photosynthesis", "pangaea", "stalacites",
                          "archipelago",    "glacier", "biosphere",
                          "continent"};
  string SpaceHard[7] = {"nucleosynthesis", "andromeda", "geoheliocentrism",
                         "heliosphere",     "titan",     "centauri",
                         "extraterrestrial"};
  string SportHard[7] = {"triathlons",  "lacrosse", "motocross", "paddlesport",
                         "racquetball", "sledding", "boxing"};

 public:
  // function for the cpp files
  string setWord();
};

#endif /* PLAYER_H */
