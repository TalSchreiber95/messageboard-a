#include <string>
#include <vector>
#include "Direction.hpp"
/*
    Board.hpp.
    Author: Tal Schreiber.
*/
using namespace std;

namespace ariel {
    class Board {
        vector<vector<char>> board;
        uint rows;
        uint cols;
        uint min_col;
        uint min_row; 
        uint max_col;
        uint max_row;
        
    public:
        Board() {
            board = vector<vector<char>>(1 , vector<char> (1, '_')); // initializing the broad by 5X5
            rows = 1;
            cols = 1;
            min_col=INT8_MAX;
            min_row=INT8_MAX; 
            max_col=0;
            max_row=0;
        }
        void post(uint row, uint col, Direction direction, std::string message);
        std::string read(uint row, uint col, Direction direction, uint length);
        void show();
        void boardResize(uint r, uint c);
    private:
        void update_min_col();
        void update_max_col();
        void update_min_row();
        void update_max_row();
        void edgeRefresher();
    };
}
