#include "scratchcard.h"
#include <string>
#include <cmath>
#include <vector>
#include <sstream>

using namespace std;

scratchcard::scratchcard(string line){
    //Winning numbers are before the '|' character in the line and are separated by one or more spaces. 
    stringstream wnstream(line.substr(0,line.find_first_of('|')));
    for (string number; getline(wnstream, number,' ');) {
        if ( number != "" ) {
            winningNumbers.push_back(stoi(number));
        }
    }

    //Your numbers are after the '|' character in the line and are separated by one or more spaces.
    stringstream ynstream(line.substr(line.find_first_of('|')+1));
    for (string number; getline(ynstream, number,' ');) {
        if (number != "") {
            yourNumbers.push_back(stoi(number));
        }
    }
    
}

int scratchcard::points(){
    int numMatches = 0;

    //Check each of yourNumbers to see if it matches any of winningNumbers. Increment numMatches if so.
    for (int i = 0; i < yourNumbers.size(); i++) {
        for (int j = 0; j < winningNumbers.size(); j++) {
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

int scratchcard::matches(){
    int numMatches = 0;

    //Check each of yourNumbers to see if it matches any of winningNumbers. Increment numMatches if so.
    for (int i = 0; i < yourNumbers.size(); i++) {
        for (int j = 0; j < winningNumbers.size(); j++) {
            if (yourNumbers[i] == winningNumbers[j]) {
                numMatches++;
                break;
            }
        }
    }
    
    
    return numMatches;
}