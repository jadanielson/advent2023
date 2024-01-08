#pragma once
#include <string>

#include "MapNode.h"

class Map {
 private:
  MapNode mapNodes[46656];
  int currentNode;
  std::string currentNodeString;
  std::string directions;
  int directionNumber;
  char nextDirection();

 public:
  Map();
  void setDirections(std::string);
  void addNode(std::string);
  std::string setStart(std::string);
  std::string nextNode();
  std::string node();
};