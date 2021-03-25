#include <iostream>
#include "Board.hpp"
/*
    Board.cpp.
    Author: Tell Schreiber.
*/
using namespace std;

namespace ariel {
 void Board::post(uint row, uint col, Direction direction, string message) 
 {
        uint len=message.length();
        if(this->flag){
            this->flag=false;
            this->min_col=col;
            this->min_row=row;
        }
        if(direction==Direction::Horizontal){
            this->max_row = max(this->max_row, row);
            this->max_col = max(this->max_col, col+len);
        }
        else{
            this->max_row = max(this->max_row, row+len);
            this->max_col = max(this->max_col, col);
        }

        this->min_row = min(this->min_row, row);
        this->min_col = min(this->min_col, col);
        for(ulong i=0 ;i<len;i++){
            this->board[row][col].v = message[i];
            if(direction == Direction::Horizontal){
                col++;
            }
            else{
                row++;
            } 
        }
    }

    string Board::read(uint row, uint col, Direction direction, uint length){
        string msgBoard;
        for(uint i=0; i<length; i++){
            msgBoard += this->board[row][col].v;
            if(direction == Direction::Horizontal){
                col++;
            }
            else{
                row++;
            } 
        }
        return msgBoard;
    }
    
    void Board::show() {
        for (uint i = this->min_row; i < this->max_row; i++) {
            cout << i<< ": ";
            for (uint j = this->min_col; j < this->max_col; j++) {
                cout << this->board[i][j].v ;
            }
            cout << "\n";
        }
    }
}
