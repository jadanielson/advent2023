#include "scratchcard.h"
#include <string>
#include <cmath>

using namespace std;

scratchcard::scratchcard(string line){
    string winningNumberString = line.substr(0,line.find_first_of('|'));
    winningNumberString = winningNumberString.substr(winningNumberString.find_first_not_of(' ',1));
    string yourNumbersString = line.substr(line.find_first_of('|'));
    yourNumbersString = yourNumbersString.substr(yourNumbersString.find_first_not_of(' ',1));

    size_t nextNumber;
    for (int i = 0; i < 10; i++) {
        winningNumbers[i] = stoi(winningNumberString, &nextNumber);
        if ( i < 9 ) {
            winningNumberString = winningNumberString.substr(winningNumberString.find_first_not_of(' ', nextNumber));
        }
    }
    for (int i = 0; i < 25; i++) {
        yourNumbers[i] = stoi(yourNumbersString, &nextNumber);
        if ( i < 24 ) {
            yourNumbersString = yourNumbersString.substr(yourNumbersString.find_first_not_of(' ', nextNumber));
        }
    }
    
}

int scratchcard::points(){
    int numMatches = 0;

    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 10; j++) {
            if (yourNumbers[i] == winningNumbers[j]) {
                numMatches++;
                break;
            }
        }
    }
    

    if (numMatches > 0) {
        return pow(2, numMatches - 1);
    } else {
        return 0;
    }
}