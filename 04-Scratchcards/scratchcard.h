#pragma once
#include <string>


class scratchcard{
    public:
        scratchcard(std::string line);
        int points();
    private:
        int winningNumbers[10];
        int yourNumbers[25];
};