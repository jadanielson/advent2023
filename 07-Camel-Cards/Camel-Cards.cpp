#include <algorithm>
#include <iostream>
#include <vector>

#include "Hand.h"

using namespace std;

int main() {
  vector<Hand> hands;
  for (string line; getline(cin, line);) {
    hands.push_back(Hand(line));
  }

  sort(hands.begin(), hands.end());

  int winningsSum = 0;
  for (int i = 0; i < hands.size(); i++) {
    winningsSum += hands[i].bid() * (1 + i);
  }

  cout << "Total winnings: " << winningsSum << endl;
}