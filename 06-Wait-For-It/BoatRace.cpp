#include "BoatRace.h"

BoatRace::BoatRace(int t, int d) {
  time = t;
  distanceToBeat = d;
}

int BoatRace::numWinningCombinations() {
  int numWins = 0;
  for (int speed = 0; speed < time; speed++) {
    int travelTime = time - speed;
    int distance = speed * travelTime;
    if (distance > distanceToBeat) {
      numWins++;
    }
  }
  return numWins;
}