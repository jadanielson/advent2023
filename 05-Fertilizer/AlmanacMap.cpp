#include "AlmanacMap.h"

AlmanacMap::AlmanacMap(long int destStart, long int sourceStart, long int size) {
  sourceRangeStart = sourceStart;
  sourceRangeEnd = sourceStart + size;
  destRangeStart = destStart;
  offset = destStart - sourceStart;
}

bool AlmanacMap::isInSourceRange(long int source) {
  if (source >= sourceRangeStart && source <= sourceRangeEnd) {
    return true;
  }
  return false;
}

long int AlmanacMap::destination(long int source) {
  return source + offset;
}