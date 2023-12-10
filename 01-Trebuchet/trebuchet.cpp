#include <iostream>
#include <string>

using namespace std;

int main (){
    int calibrationNumber = 0;
    string spelledNumbers[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    for (string line; getline(cin, line);) {
        //Replace spelled out numbers with digits
        string originalLine = line;
        for (size_t i = 0; i < 10; i++)
        {
            size_t pos = 0;
            pos = line.find(spelledNumbers[i],pos);
            while(pos!=string::npos){
                //line.replace(line.find(spelledNumbers[i]),spelledNumbers[i].length(),to_string(i));
                line.insert(pos+2,to_string(i));
                pos = line.find(spelledNumbers[i]);
            }
        }
        cout << "Original Line was: " << originalLine << " Replaced line is: " << line << " --- ";

        size_t firstPos = line.find_first_of("0123456789");
        size_t lastPos = line.find_last_of("0123456789");
        //int lineValue = 10 * line[firstPos] + 1 * line[lastPos];
        char firstChar = line[firstPos];
        char lastChar = line[lastPos];
        int  firstDigit = firstChar - '0';
        int lastDigit = lastChar - '0';
        int lineValue = 10 * firstDigit + lastDigit;

        cout << "First digit is: " << firstDigit << " Last digit is: " << lastDigit << " Line Value is: " << lineValue << endl;

        calibrationNumber += lineValue;
    }
    cout << "Sum of Calibration Values is: " << calibrationNumber << endl;
    
    return 0;
}