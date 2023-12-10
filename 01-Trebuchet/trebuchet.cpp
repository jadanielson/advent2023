#include <iostream>
#include <string>

using namespace std;

int main (){
    int calibrationNumber = 0;
    for (string line; getline(cin, line);) {
        size_t firstPos = line.find_first_of("0123456789");
        size_t lastPos = line.find_last_of("0123456789");
        //int lineValue = 10 * line[firstPos] + 1 * line[lastPos];
        char firstChar = line[firstPos];
        char lastChar = line[lastPos];
        int  firstDigit = firstChar - '0';
        int lastDigit = lastChar - '0';
        int lineValue = 10 * firstDigit + lastDigit;
        calibrationNumber += lineValue;
    }
    cout << "Sum of Calibration Values is: " << calibrationNumber << endl;
    
    return 0;
}