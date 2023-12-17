#pragma once

#include <string>
#include <vector>

#include "AlmanacMap.h"

class AlmanacSection {
 private:
  std::vector<AlmanacMap> almanacMaps;
  int mapCount;

 public:
  AlmanacSection();
  void addSeedMap(std::string);
  void addMap(std::string);
  long int findDestination(long int source);
  long int findSource(long int destination);
};