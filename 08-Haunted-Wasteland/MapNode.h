#pragma once
#include <string>

class MapNode {
 private:
  std::string thisNode;
  std::string leftNode;
  std::string rightNode;

 public:
  MapNode(std::string);
  MapNode();
  std::string left();
  std::string right();
};