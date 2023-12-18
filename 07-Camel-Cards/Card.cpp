#include "Card.h"

Card::Card(char c) {
  if (c == 'A') {
    cardValue = 14;
  } else if (c == 'K') {
    cardValue = 13;
  } else if (c == 'Q') {
    cardValue = 12;
  } else if (c == 'J') {
    cardValue = 11;
  } else if (c == 'T') {
    cardValue = 10;
  } else {
    cardValue = c - 48;
  }
}

Card::Card() {
}

int Card::value() {
  return cardValue;
}

bool operator==(const Card& card1, const Card& card2) {
  return card1.cardValue == card2.cardValue;
}
bool operator>(const Card& card1, const Card& card2) {
  return card1.cardValue > card2.cardValue;
};
bool operator<(const Card& card1, const Card& card2) {
  return card1.cardValue < card2.cardValue;
}
bool operator!=(const Card& card1, const Card& card2) {
  return card1.cardValue != card2.cardValue;
}