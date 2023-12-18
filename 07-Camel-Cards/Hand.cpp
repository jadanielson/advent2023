#include "Hand.h"

#include <algorithm>
#include <string>
#include <vector>

Hand::Hand(std::string line) {
  for (int i = 0; i < 5; i++) {
    cards[i] = Card(line[i]);
  }
  type = findHandType();
  handBid = stoi(line.substr(line.find_first_of(' ') + 1));
}

Hand::handType Hand::findHandType() {
  std::vector<int> cardCounts(15, 0);
  for (int i = 0; i < 5; i++) {
    int cardValue = cards[i].value();
    cardCounts[cardValue]++;
  }
  cardCounts.erase(std::remove(cardCounts.begin(), cardCounts.end(), 0), cardCounts.end());
  std::sort(cardCounts.rbegin(), cardCounts.rend());

  if (cardCounts[0] == 5) {
    return fiveOfAKind;
  } else if (cardCounts[0] == 4) {
    return fourOfAKind;
  } else if (cardCounts[0] == 3 && cardCounts[1] == 2) {
    return fullHouse;
  } else if (cardCounts[0] == 3) {
    return threeOfAKind;
  } else if (cardCounts[0] == 2 && cardCounts[1] == 2) {
    return twoPair;
  } else if (cardCounts[0] == 2) {
    return onePair;
  } else {
    return highCard;
  }
}

int Hand::bid() {
  return handBid;
}

bool operator>(const Hand& hand1, const Hand& hand2) {
  if (hand1.type > hand2.type) {
    return true;
  } else if (hand1.type < hand2.type) {
    return false;
  } else {
    for (int i = 0; i < 5; i++) {
      if (hand1.cards[i] > hand2.cards[i]) {
        return true;
      } else if (hand1.cards[i] < hand2.cards[i]) {
        return false;
      }
    }
  }
  return false;
}

bool operator<(const Hand& hand1, const Hand& hand2) {
  if (hand1.type < hand2.type) {
    return true;
  } else if (hand1.type > hand2.type) {
    return false;
  } else {
    for (int i = 0; i < 5; i++) {
      if (hand1.cards[i] < hand2.cards[i]) {
        return true;
      } else if (hand1.cards[i] > hand2.cards[i]) {
        return false;
      }
    }
  }
  return false;
}

bool operator==(const Hand& hand1, const Hand& hand2) {
  if (hand1.type == hand2.type) {
    for (int i = 0; i < 5; i++) {
      if (hand1.cards[i] != hand2.cards[i]) {
        return false;
      }
    }
    return true;
  }
  return false;
}