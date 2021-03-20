#include <string>
#include <vector>
#include "Direction.hpp"
/*
    Board.hpp.
    Author: Tell Schreiber.
*/
using namespace std;

namespace ariel {
    class Board {
        uint rows;
        uint cols;
        vector<vector<char>> board; 
    public:
        Board() {
            board = vector<vector<char>>(5 , vector<char> (5, '_')); // initializing the broad by 5X5
            rows = 5;
            cols = 5;
        }
        void post(uint row, uint col, Direction direction, std::string message);
        std::string read(uint row, uint col, Direction direction, uint length);
        void show();
        void boardResize(uint r, uint c);
    };
}