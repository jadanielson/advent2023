#include <iostream>

#include "scratchcard.h"

using namespace std;

int main() {
    int pointSum = 0;
    for (string line; getline(cin, line);) {
        scratchcard card(line.substr(line.find_first_of(':')));
        pointSum += card.points();
    }
    cout << "Total Points: " << pointSum << endl;
}