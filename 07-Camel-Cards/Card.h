#pragma once

class Card {
 private:
  int cardValue;

 public:
  Card(char);
  Card();
  int value();
  bool friend operator==(const Card& card1, const Card& card2);
  bool friend operator>(const Card& card1, const Card& card2);
  bool friend operator<(const Card& card1, const Card& card2);
  bool friend operator!=(const Card& card1, const Card& card2);
};