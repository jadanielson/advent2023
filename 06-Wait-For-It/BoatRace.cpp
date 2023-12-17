#include "BoatRace.h"

BoatRace::BoatRace(long int t, long int d) {
  time = t;
  distanceToBeat = d;
}

long int BoatRace::numWinningCombinations() {
  long int numWins = 0;
  for (long int speed = 0; speed < time; speed++) {
    long int travelTime = time - speed;
    long int distance = speed * travelTime;
    if (distance > distanceToBeat) {
      numWins++;
    }
  }
  return numWins;
}