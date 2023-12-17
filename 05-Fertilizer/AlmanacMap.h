#pragma once

class AlmanacMap {
 private:
  long int sourceRangeStart;
  long int sourceRangeEnd;
  long int destRangeStart;
  long int destRangeEnd;
  long int offset;

 public:
  AlmanacMap(long int destStart, long int sourceStart, long int size);
  bool isInSourceRange(long int source);
  bool isInDestinationRange(long int destination);
  long int destinationFromSource(long int source);
  long int sourceFromDestination(long int destination);
};