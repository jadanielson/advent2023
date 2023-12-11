#include <iostream>

using namespace std;

const int ROWS = 140;
const int COLS = 140;

int main () {
    char schematic[ROWS][COLS];
    int schematicNumbers[ROWS][COLS];
    bool validPartNumber[ROWS][COLS];
    int lineNum = 0;
    int partNumberSum = 0;
    int gearRatioSum = 0;

    //fill schematic with characters from input and fill validPartNumber with false in every position and fill schematicNumbers with 0s
    for(string line;getline(cin, line);) {
        for(int i=COLS - 1; i>=0; i--) {
            schematic[lineNum][i] = line.back();
            line.pop_back();
            validPartNumber[lineNum][i] = false;
            schematicNumbers[lineNum][i] = 0;
        }
        lineNum++;
    }

    //find every symbol in schematic and change corresponding places in validPartNumber to true
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
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
    for (int row = 0; row < ROWS; row++) {
        cout << "Row " << row + 1 << endl;
        int number = 0;
        bool numberIsPartNumber = false;
        int numberFirstCol = 0;
        for (int col = 0; col < COLS; col++) {
            if (schematic[row][col] >= 48 && schematic[row][col] <= 57){ // if 0-9
                if (number == 0) {
                    numberFirstCol = col;
                }
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
                for (int i = numberFirstCol; i < col; i++){
                    schematicNumbers[row][i] = number;
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
        for (int i = numberFirstCol; i <= COLS-1; i++){
            schematicNumbers[row][i] = number;
        }
        cout << "          Running Total: " << partNumberSum << endl;
        number = 0;
        numberIsPartNumber = false;
    }

    //Find each * and check if it is next to exactly two numbers
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if (schematic[row][col] == 42){ //char is *
                int adjacentNumbers = 0;
                int currentNumber = 0;
                int gearRatio = 1;
                for(int i = row - 1; i <= row +1; i++) {
                    for(int j = col - 1; j <= col +1; j++) {
                        if (schematicNumbers[i][j] != 0 && schematicNumbers[i][j] != currentNumber){
                            adjacentNumbers++;
                            currentNumber = schematicNumbers[i][j];
                            gearRatio = gearRatio * currentNumber;
                        }
                    }
                    currentNumber = 0;
                }
                if (adjacentNumbers == 2) { // if * is a gear
                    gearRatioSum += gearRatio;
                }
            }

        }
    }

    cout << "Sum of Part numbers is: " << partNumberSum << endl;
    cout << "Sum of Gear Ratios is: " << gearRatioSum << endl;
    return 0;
}