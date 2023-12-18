#pragma once
#include <string>

#include "Card.h"

class Hand {
  enum handType { highCard, onePair, twoPair, threeOfAKind, fullHouse, fourOfAKind, fiveOfAKind };

 private:
  Card cards[5];
  int handBid;
  handType type;
  handType findHandType();

 public:
  Hand(std::string);
  int bid();
  friend bool operator>(const Hand& hand1, const Hand& hand2);
  friend bool operator<(const Hand& hand1, const Hand& hand2);
  friend bool operator==(const Hand& hand1, const Hand& hand2);
};