#include <iostream>
#include "Board.hpp"
/*
    Board.cpp.
    Author: Tell Schreiber.
*/
using namespace std;

namespace ariel {

    void Board::boardResize(uint r, uint c){        
        this->rows = r;
        this->cols = c;
        this->board.resize(r);
        for (ulong i = 0; i < r ; i++){
            this->board[i].resize(c, '_');
        }
    }

    void Board::post(uint row, uint col, Direction direction, string message) {
        uint len = message.size();
        bool f = true;
        //Firstly checking the side and if board's resize necessary.
        if(direction == Direction::Horizontal)
        {
            boardResize(std::max(this->rows, row+1), std::max(this->cols, col + len +1));
        }
        else
        {
            boardResize(std::max(this->rows, row + len + 1), std::max(this->cols, col + 1));
            f=false;
        }
        // Secondly post the board.
        for(ulong i=0; i<len; i++)
        {
            this->board[row][col] = message[i];
            if(f)
            {
                col++;
            }
            else
            {
                row++;
            }
        }    
    }

    string Board::read(uint row, uint col, Direction direction, uint length) 
    {
        string msgBoard;
        // if(row>this->rows || col >this->cols) 
        if(direction == Direction::Horizontal)
        {
            boardResize(std::max(this->rows, row+1), std::max(this->cols, col + length +1));
        }
        else
        {
            boardResize(std::max(this->rows, row + length + 1), std::max(this->cols, col + 1));
        }
        
        for(ulong i=0; i<length; i++)
        {
            msgBoard += this->board.at(row).at(col);
            if(direction == Direction::Horizontal)
            {
                col++;
            }
            else{
                row++;
            }
        }
        return msgBoard;
    }

    void Board::show() 
    { 
        for (ulong i = 0; i < this->rows; i++) {
            for (ulong j = 0; j < this->cols; j++) 
            {
                cout << this->board.at(i).at(j) << " ";
            }
            cout << "\n\n";
        }
        cout << "\n";
    }
}
