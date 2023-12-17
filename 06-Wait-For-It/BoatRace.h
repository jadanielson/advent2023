#pragma once

class BoatRace {
 private:
  int time;
  int distanceToBeat;

 public:
  BoatRace(int t, int d);
  int numWinningCombinations();
};