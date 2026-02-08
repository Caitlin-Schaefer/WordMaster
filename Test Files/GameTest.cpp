#include "../CPP Files/Game.cpp"
using namespace std;

int main() {
  {
    // test the functionality of play again
    Game check;

    if (check.PlayAgain() != "Y" || check.PlayAgain() != "N") {
      cout << "Test 1 failed" << endl;
    }
  }
  {
    // test the functionality of gameWL version 1
    Game check;
    check.GameWL(0, "Lion");
    cout << endl;
  }
  {
    // test the functionality of gameWL version 2
    Game check;
    check.GameWL(5, "Lion");
    cout << endl;
  }
  {
    // test the functionality of printing unknown word
    Game check;
    check.PrintUnknownWord("Word");
    cout << endl;
  }
  {
    // test the functionality of asking number of players
    Game check;

    if (check.Number_of_Players() != "1" || check.Number_of_Players() != "2") {
      cout << "Test 2 failed" << endl;
    }
  }

  {
    // test the menu
    Game check;
    check.is_player_ready();
  }
}