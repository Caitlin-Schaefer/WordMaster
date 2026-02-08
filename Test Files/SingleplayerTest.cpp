#include "../CPP Files/Singleplayer.cpp"
using namespace std;

int main() {
  Singleplayer single;
    // test the singleplayer class
  if (single.getDifficulty() != "Easy" || single.getDifficulty() != "Hard") {
    cout << "Test failed";
  }
}