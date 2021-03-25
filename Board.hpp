#include <string>
// #include <vector>
#include <map>
#include "Direction.hpp"
/*
    Board.hpp.
    Author: Tal Schreiber.
*/
using namespace std;

struct defChar{
    char v='_'; // this is the default value of each character types in our board
};

namespace ariel {
    class Board {
        map<uint,map<uint,defChar>> board;
        bool flag;
        uint min_col;
        uint min_row; 
        uint max_col;
        uint max_row;
    public:
        Board() {
            flag=true;// Created due to issues with INT16_MAX value that is 127 insted of MaxInt that should be.
            min_col=0;//INT16_MAX;
            min_row=0;//INT16_MAX; 
            max_col=0;
            max_row=0;
        }
        ~Board(){}; // class's destructor
        void post(uint row, uint col, Direction direction, std::string message);
        std::string read(uint row, uint col, Direction direction, uint length);
        void show();
    };

}
