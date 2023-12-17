#include "AlmanacSection.h"

#include <string>
#include <vector>

#include "AlmanacMap.h"

AlmanacSection::AlmanacSection() {
  mapCount = 0;
}

void AlmanacSection::addMap(std::string line) {
  long int destStart, sourceStart, size;
  destStart = std::stol(line.substr(0, line.find_first_of(' ')));
  sourceStart = std::stol(line.substr(line.find_first_of(' ') + 1, line.find_last_of(' ') - line.find_first_of(' ')));
  size = std::stol(line.substr(line.find_last_of(' ') + 1));
  almanacMaps.push_back(AlmanacMap(destStart, sourceStart, size));
  mapCount++;
}

long int AlmanacSection::findDestination(long int source) {
  // Check if source is in any Source Range of the maps
  for (int i = 0; i < mapCount; i++) {
    if (almanacMaps[i].isInSourceRange(source)) {
      return almanacMaps[i].destination(source);
    }
  }

  // If not destination is equal to source
  return source;
}