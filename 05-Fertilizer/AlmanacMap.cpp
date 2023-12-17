#include "AlmanacMap.h"

AlmanacMap::AlmanacMap(long int destStart, long int sourceStart, long int size) {
  sourceRangeStart = sourceStart;
  sourceRangeEnd = sourceStart + size - 1;
  destRangeStart = destStart;
  destRangeEnd = destStart + size - 1;
  offset = destStart - sourceStart;
}

bool AlmanacMap::isInSourceRange(long int source) {
  if (source >= sourceRangeStart && source <= sourceRangeEnd) {
    return true;
  }
  return false;
}

bool AlmanacMap::isInDestinationRange(long int destination) {
  if (destination >= destRangeStart && destination <= destRangeEnd) {
    return true;
  }
  return false;
}

long int AlmanacMap::destinationFromSource(long int source) {
  return source + offset;
}

long int AlmanacMap::sourceFromDestination(long int destination) {
  return destination - offset;
}