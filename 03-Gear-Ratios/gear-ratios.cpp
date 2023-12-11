#include <iostream>

using namespace std;

int main () {
    char schematic[140][140];
    bool validPartNumber[140][140];
    int lineNum = 0;
    int partNumberSum = 0;

    //fill schematic with characters from input and fill validPartNumber with false in every position
    for(string line;getline(cin, line);) {
        for(int i=139; i>=0; i--) {
            schematic[lineNum][i] = line.back();
            line.pop_back();
            validPartNumber[lineNum][i] = false;
        }
        lineNum++;
    }

    //find every symbol in schematic and change corresponding places in validPartNumber to true
    for (int row = 0; row < 140; row++) {
        for (int col = 0; col < 140; col++) {
            if (schematic[row][col] >= 48 && schematic[row][col] <= 57){ //ignore if 0-9
                continue;
            } else if (schematic[row][col] == 46) { //ignore if .
                continue;
            } else {
                for(int i = row - 1; i <= row +1; i++) {
                    for(int j = col - 1; j <= col +1; j++) {
                        validPartNumber[i][j] = true;
                    }
                }
            }

        }
    }

    //find numbers in schematic and check if they correspond to a validPartNumber
    for (int row = 0; row < 140; row++) {
        cout << "Row " << row + 1 << endl;
        int number = 0;
        bool numberIsPartNumber = false;
        for (int col = 0; col < 140; col++) {
            if (schematic[row][col] >= 48 && schematic[row][col] <= 57){ // if 0-9
                number = 10 * number + schematic[row][col] - 48;
                if (validPartNumber[row][col]) {
                    numberIsPartNumber = true;
                }
            } else {
                if (number == 0 ) {
                    continue;
                } else if (numberIsPartNumber) {
                    cout << "Number " << number << " is a part number.";
                    partNumberSum += number;
                } else {
                    cout << "Number " << number << " is not a part number.";
                }
                cout << "          Running Total: " << partNumberSum << endl;
                number = 0;
                numberIsPartNumber = false;
            }

        }
        if (number == 0 ) {
            continue;
        } else if (numberIsPartNumber) {
            cout << "Number " << number << " is a part number.";
            partNumberSum += number;
        } else {
            cout << "Number " << number << " is not a part number.";
        }
        cout << "          Running Total: " << partNumberSum << endl;
        number = 0;
        numberIsPartNumber = false;
    }

    cout << "Sum of Part numbers is: " << partNumberSum << endl;
}