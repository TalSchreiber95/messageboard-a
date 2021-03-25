#include <iostream>
#include "doctest.h"
#include "Board.hpp"
#include <string>
#include <vector>
#include <time.h>
#include <cstdlib>
using namespace ariel;
using namespace std;
/*
    Test.
    Author: Tal Schreiber.
*/

Board board;

//1
TEST_CASE("test read before post")
{
    CHECK(board.read(0, 0, Direction::Horizontal, 1) == string("_"));
    CHECK(board.read(0, 0, Direction::Horizontal, 2) == string("__"));
    CHECK(board.read(0, 0, Direction::Vertical, 1) == string("_"));
    CHECK(board.read(0, 0, Direction::Vertical, 2) == string("__"));
    CHECK(board.read(34, 100, Direction::Vertical, 5) == string("_____"));
    CHECK(board.read(23, 54, Direction::Horizontal, 4) == string("____"));

    
    unsigned int random_row = rand() % 100;
    unsigned int random_col = rand() % 100;
    unsigned int random_len = rand() % 10;
    string ans;
    for (int i = 0; i < random_len; i++)
    {
        ans += "_";
    }
    CHECK(board.read(random_row, random_col, Direction::Vertical, random_len) == string(ans));
    CHECK(board.read(random_row, random_col, Direction::Horizontal, random_len) == string(ans));
}

//2
TEST_CASE("test post")
{
    CHECK_NOTHROW(board.post(0, 0, Direction::Horizontal, "Tal"));
    CHECK_NOTHROW(board.post(0, 0, Direction::Vertical, "Tal"));
    CHECK_NOTHROW(board.post(0, 3, Direction::Vertical, "love"));
    CHECK_NOTHROW(board.post(5, 2, Direction::Horizontal, "Schreiber"));
    CHECK_NOTHROW(board.post(5, 2, Direction::Vertical, "messagebox"));
}

//3
TEST_CASE("test read after post")
{
    CHECK(board.read(0, 0, Direction::Vertical, 3) == string("Tal"));
    CHECK(board.read(0, 0, Direction::Vertical, 4) == string("Tal_"));
    CHECK(board.read(0, 0, Direction::Vertical, 6) == string("Tal___"));
    CHECK(board.read(5, 2, Direction::Horizontal, 9) == string("mchreiber"));
    CHECK(board.read(5, 2, Direction::Vertical, 11) == string("messagebox_"));
}
/*
//4
TEST_CASE("random")
{
    ariel::Board bo;
    std::cout << "random test might stuck sometimes do to random number that incorrect for this loop..." << endl;
    std::cout << "if this test got stuck please retest..." << endl;
    std::cout << "checking a random test..." << endl;
    srand(time(0)); // this srand function is called to make sure our random number is create eche run
    unsigned int random_row = rand() % 100;
    unsigned int random_col = rand() % 100;
    unsigned int random_len = rand() % 10;

    cout << "len= "<<random_len<<endl;
    CHECK_NOTHROW(bo.post(random_row, random_col, Direction::Horizontal, "r"));
    // string ans = "randTal";
    string ans = "r";
    
    for (int i = 0; i < random_len - 1; i++)
    {
        ans += "_";
    }
    CHECK(bo.read(random_row, random_col, Direction::Horizontal, random_len) == string(ans));
    CHECK_NOTHROW(bo.post(random_row, random_col, Direction::Vertical, "r"));
    CHECK(bo.read(random_row, random_col, Direction::Vertical, random_len) == string(ans));
     std::cout << "Done." << endl<<endl;
}
*/
//5
TEST_CASE("test read- length 0")
{
    //at the start of the board
    CHECK(board.read(0, 0, Direction::Horizontal, 0) == "");
    CHECK(board.read(0, 0, Direction::Vertical, 0) == "");
    //somewhere at the board
    CHECK(board.read(9, 2, Direction::Horizontal, 0) == "");
    CHECK(board.read(2, 9, Direction::Vertical, 0) == "");
    //corners check
    CHECK(board.read(7, 1, Direction::Horizontal, 0) == "");
    CHECK(board.read(7, 1, Direction::Vertical, 0) == "");
    //out of the board check
    CHECK(board.read(11, 44, Direction::Horizontal, 0) == "");
    CHECK(board.read(45, 12, Direction::Vertical, 0) == "");
}

//6
TEST_CASE("Show test")
{
    ariel::Board bMsgBox;
    CHECK_NOTHROW(bMsgBox.post(0, 0, Direction::Horizontal, "_______________________________________"));
    CHECK_NOTHROW(bMsgBox.post(1, 0, Direction::Horizontal, "_~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~__"));
    CHECK_NOTHROW(bMsgBox.post(2, 0, Direction::Horizontal, "_             _______________________ _"));
    CHECK_NOTHROW(bMsgBox.post(3, 0, Direction::Horizontal, "_             |     Message Board     |_"));
    CHECK_NOTHROW(bMsgBox.post(4, 0, Direction::Horizontal, "_   -         |    #                  |_"));
    CHECK_NOTHROW(bMsgBox.post(5, 0, Direction::Horizontal, "_  /_\\        |    #      ###         |_"));
    CHECK_NOTHROW(bMsgBox.post(6, 0, Direction::Horizontal, "_\\(o_O)       |     #      ##*        |_"));
    CHECK_NOTHROW(bMsgBox.post(7, 0, Direction::Horizontal, "_ (]_[)>|####||              *####    |_"));
    CHECK_NOTHROW(bMsgBox.post(8, 0, Direction::Horizontal, "_ () ()       |______###_____#####____|_"));
    CHECK_NOTHROW(bMsgBox.post(9, 0, Direction::Horizontal, "_~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~_"));
    CHECK_NOTHROW(bMsgBox.post(10, 0, Direction::Horizontal, "_______________________________________"));
    //__________________________________________
    //_________ _|     Message Board       |
    //   -         |    #                  | 
    //  /_\\        |    #      ###        |____
    //_\(o_O)       |     #      ##*       |____
    //_(]_[)>|####||              *####    |____
    //_() ()       |______###_____#####____|____
    //__________________________________________
    bMsgBox.show();
    vector<string> sMsgBox;
    sMsgBox.push_back("_______________________________________");
    sMsgBox.push_back("_~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~__");
    sMsgBox.push_back("_             _______________________ _");
    sMsgBox.push_back("_             |     Message Board     |_");
    sMsgBox.push_back("_   -         |    #                  |_");
    sMsgBox.push_back("_  /_\\        |    #      ###         |_");
    sMsgBox.push_back("_\\(o_O)       |     #      ##*        |_");
    sMsgBox.push_back("_ (]_[)>|####||              *####    |_");
    sMsgBox.push_back("_ () ()       |______###_____#####____|_");
    sMsgBox.push_back("_~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~_");
    sMsgBox.push_back("_______________________________________");
    for (unsigned int i = 0; i < 11; i++)
    {
        unsigned int len =sMsgBox.at(i).length();
        CHECK(bMsgBox.read(i, 0, Direction::Horizontal, len) == string(sMsgBox.at(i)));
    }
    std::cout << "Message Box test fully successed" << endl;
}
