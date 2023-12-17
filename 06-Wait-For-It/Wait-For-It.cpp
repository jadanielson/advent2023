#include <iostream>
#include <vector>

#include "BoatRace.h"

using namespace std;

vector<int> numbersFromLine(string line);

int main() {
  // Get time and distance lines from cin
  string timeLine, distanceLine;
  getline(cin, timeLine);
  getline(cin, distanceLine);

  // Parse into time and distance for each race;
  vector<int> time, distance;

  time = numbersFromLine(timeLine);
  distance = numbersFromLine(distanceLine);

  // Sum winning combinations for each race;
  int prodWins = 1;
  for (int i = 0; i < time.size(); i++) {
    prodWins *= BoatRace(time[i], distance[i]).numWinningCombinations();
  }

  // Output sum
  cout << "Total possible winning moves: " << prodWins << endl;
}

vector<int> numbersFromLine(string line) {
  vector<int> numbers;
  int pos = line.find_first_of(' ');
  while (pos != string::npos) {
    line = line.substr(line.find_first_of("0123456789", pos));
    pos = line.find_first_of(' ');
    numbers.push_back(stoi(line.substr(0, pos)));
  }
  return numbers;
}