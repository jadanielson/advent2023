#include <iostream>
#include <vector>

#include "scratchcard.h"

using namespace std;

int main() {
    int pointSum = 0;

    int cardCount = 0;
    int currentCard = 0;
    //Assume one copy of each card.
    vector<int> cardCopies(512);
    fill(cardCopies.begin(), cardCopies.end(), 1);

    //For each card
    for (string line; getline(cin, line); currentCard++) {
        scratchcard card(line.substr(line.find_first_of(':')+1));

        //Add points from current card to pointSum
        pointSum += card.points();

        //Add copies of current card to cardCount
        cardCount += cardCopies[currentCard];

        //Add newly won copies to cardCopies
        for (int i = card.matches(); i > 0; i--) {
            cardCopies[currentCard + i] += cardCopies[currentCard];
        }
    }

    //Print results
    cout << "Part 1:" << endl;
    cout << "Total Points: " << pointSum << endl;
    cout << "Part 2:" << endl;
    cout << "Total Cards: " << cardCount << endl;

}