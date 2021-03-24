#include <iostream>
#include "Board.hpp"
/*
    Board.cpp.
    Author: Tell Schreiber.
*/
using namespace std;

namespace ariel {
    void Board::update_min_col(){
        uint min=this->min_col;
        uint count=0;
        // cout << "\nmin col="<<min<< endl;
        for(ulong i = 0; i < this->rows; i++) {
            for (ulong j = 0; j < this->cols; j++) 
            {
                if(this->board.at(i).at(j)=='_'){
                    count++;
                }
                else{
                    cout<< "\ncount col="<< count<<endl;
                    break;
                }
            }
            if(count<min){
                min=count;
            }
                count=0;
        }
        this->min_col=min;
    }
    void Board::update_min_row(){
        uint min=this->min_row;
        uint count=0;
        for (ulong i = 0; i < this->cols; i++) {
            // cout << "\nmin row="<<min<< endl;
            for (ulong j = 0; j < this->rows; j++) 
            {
                if(this->board.at(i).at(j)=='_'){
                    count++;
                }
                else{
                    cout<< "\ncount row="<< count<<endl;
                    break;
                }
            }
            if(count<min){
                min=count;
            }
                count=0;
        }
        
        this->min_row=min;
    }
    void Board::update_max_col(){
        uint min=this->max_col;
        uint count=0;
        for (ulong i = this->rows; i <=0 ; i++) {
            for (ulong j =  this->cols; j <=0; j++) 
            {
                if(this->board.at(i).at(j)=='_'){
                    count++;
                }
                else{
                    break;
                }
            }
            if(count<min){
                min=count;
            }
                count=0;
        }
        this->max_col=this->cols-min;
    }
    void Board::update_max_row(){
        uint min=this->max_row;
        uint count=0;
        for (ulong i = this->cols; i <=0 ; i++) {
            for (ulong j =  this->rows; j <=0; j++) 
            {
                if(this->board.at(i).at(j)=='_'){
                    count++;
                }
                else{
                    break;
                }
            }
            if(count<min){
                min=count;
            }
                count=0;
        }
        this->max_row=this->rows-min;
        
    }
    void Board::edgeRefresher(){
        update_min_row();
        update_max_row();
        update_min_col();
        update_max_col();
    }

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
        bool f = direction == Direction::Horizontal;
        // Firstly checking the side and if board's resize necessary.
        try{
        if(f)
        {
            boardResize(std::max(this->rows, row+1), std::max(this->cols, col+ len+1));
            // update_min_col();
        }
        else
        {
            boardResize(std::max(this->rows, row + len+1) , std::max(this->cols, col+1));
            // update_min_row();
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
        catch(const std::out_of_range){
            cout<< "post outofrange\n";
        }    
    }

    string Board::read(uint row, uint col, Direction direction, uint length) 
    {
        string msgBoard;
        ulong start=0;
        
        try{
            // cout<< "\nthis here\n";
        if(direction == Direction::Horizontal)
        {
            boardResize(std::max(this->rows, row+1), std::max(this->cols, col  + length+1));
            cout<< "\nthis here horizontal\n";
            // update_min_col();

            // start=this->min_col;
        }
        else
        {
            boardResize(std::max(this->rows, row+1 ), std::max(this->cols, col+1));
            cout<< "\nthis here vertical\n";
            // update_min_row();
            // start=this->min_row;
        }
        
        for(ulong i=start; i<length; i++)
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
        // cout<<"\nfalid here\n";
        }
        catch(const std::out_of_range){
            cout<<"read outofrange\n";
        }
        return msgBoard;
    }

    void Board::show() 
    { 
        // edgeRefresher();
        cout << "min row= "<< this->min_row <<endl;
        cout << "max row= "<< this->max_row <<endl;
        cout << "min col= "<< this->min_col <<endl;
        cout << "max col= "<< this->max_col <<endl;
        cout << "rows= "<< this->rows <<endl;
        cout << "cols= "<< this->cols <<endl;
        try{
            // for (ulong i = this->min_row; i < this->max_row; i++) {
            // cout << i<< ":";
            // for (ulong j = this->min_col; j < this->max_col; j++) 
         for (ulong i = 0; i < this->rows; i++) {cout << i<< ":";
            for (ulong j = 0; j < this->cols; j++) 
            {
                // cout << "here ";
                cout <<this->board.at(i).at(j) << " ";
            }
            cout << "\n\n";
            // cout << "here out";
        }
        }
        catch(const std::out_of_range){
            cout<<"outofrange";
        }
        cout << " end";
        cout << "\n";
    }
}
