#pragma once

class BoatRace {
 private:
  long int time;
  long int distanceToBeat;

 public:
  BoatRace(long int t, long int d);
  long int numWinningCombinations();
};