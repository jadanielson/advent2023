#include <iostream>
#include <vector>

#include "Map.h"

using namespace std;

int main() {
  Map wastelandMap;
  string directions, mapLine;
  getline(cin, directions);
  wastelandMap.setDirections(directions);
  getline(cin, mapLine);
  while (getline(cin, mapLine)) {
    wastelandMap.addNode(mapLine);
  }

  wastelandMap.setStart("AAA");
  int numSteps = 0;
  string nextNode;
  while (wastelandMap.node() != "ZZZ") {
    nextNode = wastelandMap.nextNode();
    numSteps++;
  }

  cout << numSteps << " steps from AAA to ZZZ" << endl;
}