#include <iostream>
#include <sstream>

using namespace std;

int main(){
    //Total Cubes
    int totalRed = 12;
    int totalGreen = 13;
    int totalBlue = 14;

    int gameSum = 0;
    int gamePowerSum = 0;

    for (string line; getline(cin, line);) {
        bool gamePossible = true;
        int gamePower = 0;
        int minRed = 0;
        int minGreen = 0;
        int minBlue = 0;
        string gameId;
        stringstream input(line);
        getline(input, gameId, ':');
        int gameNum = stoi(gameId.substr(5,string::npos));

        cout << "Game " << gameNum;

        //Remove Game ID from line
        line = line.substr(line.find_first_of(':')+2);
        //Split line by ; for pulls
        stringstream pullStream(line);
        for(string pull; getline(pullStream, pull, ';');){
            //Split pull by , for colors
            stringstream colorStream(pull);
            for(string color; getline(colorStream, color, ',');){
                string colorNumStr = color.substr(0,color.find_first_of(' ',1));
                int colorNum = stoi(colorNumStr);
                string colorName = color.substr(color.find_first_of(' ',1)+1);
                if (colorName == "red") {
                    if (colorNum > minRed) {
                        minRed = colorNum;
                    }
                } else if (colorName == "green") {
                    if (colorNum > minGreen) {
                        minGreen = colorNum;
                    }
                } else if (colorName == "blue") {
                    if (colorNum > minBlue) {
                        minBlue = colorNum;
                    }
                } else {
                    cout << "UNKNOWN COLOR: " << colorName <<  " in Game " << gameNum << "!" << endl;
                }
            }

        }
        if (minRed > totalRed) {
            gamePossible = false;
        } else if (minGreen > totalGreen) {
            gamePossible = false;
        } else if (minBlue > totalBlue) {
            gamePossible = false;
        }
        if (gamePossible) {
            cout << " Possible";
            gameSum += gameNum;
        } else {
            cout << " Impossible";
        }

        //Calculate game power
        gamePower = minRed * minGreen * minBlue;
        cout << "   Game Power: " << gamePower << endl;
        gamePowerSum += gamePower;

    }
    
    cout << "Sum of Ids of possible games is: " << gameSum << endl;
    cout << "Summ of game power is: " << gamePowerSum << endl;



}