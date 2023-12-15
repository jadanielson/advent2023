#pragma once
#include <string>
#include <vector>



class scratchcard{
    public:
        scratchcard(std::string line);
        int points();
        int matches();
    private:
        std::vector<int> winningNumbers;
        std::vector<int> yourNumbers;
};