#include "MapNode.h"

#include <string>

MapNode::MapNode(std::string inputString) {
  thisNode = inputString.substr(0, 3);
  inputString = inputString.substr(7);
  leftNode = inputString.substr(0, 3);
  inputString = inputString.substr(5);
  rightNode = inputString.substr(0, 3);
}

MapNode::MapNode() {
  thisNode = "";
  leftNode = "";
  rightNode = "";
}

std::string MapNode::left() {
  return leftNode;
}

std::string MapNode::right() {
  return rightNode;
}