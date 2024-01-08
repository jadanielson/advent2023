#include "Map.h"

#include <iostream>
#include <string>

#include "MapNode.h"

Map::Map() {
  currentNode = 0;
  currentNodeString = "";
  directionNumber = 0;
  directions = "";
}

void Map::setDirections(std::string directionString) {
  directions = directionString;
  directionNumber = 0;
}

void Map::addNode(std::string mapNodeString) {
  int nodeNumber = stoi(mapNodeString, nullptr, 36);
  mapNodes[nodeNumber] = MapNode(mapNodeString);
}

std::string Map::node() {
  return currentNodeString;
}

std::string Map::nextNode() {
  char dirChar = nextDirection();
  std::string nextNodeString;
  if (dirChar == 'R') {
    nextNodeString = mapNodes[currentNode].right();
  } else if (dirChar == 'L') {
    nextNodeString = mapNodes[currentNode].left();
  } else {
    nextNodeString = "";
  }
  // std::cout << currentNodeString << " -> " << nextNodeString << std::endl;
  currentNodeString = nextNodeString;
  currentNode = stoi(nextNodeString, nullptr, 36);
  return nextNodeString;
}

std::string Map::setStart(std::string startString) {
  currentNodeString = startString;
  currentNode = stoi(startString, nullptr, 36);
  return startString;
}

char Map::nextDirection() {
  if (directionNumber < directions.length()) {
    directionNumber++;

  } else {
    directionNumber = 1;
  }
  return directions[directionNumber - 1];
}