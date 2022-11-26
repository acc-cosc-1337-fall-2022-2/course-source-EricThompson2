#include "tic_tac_toe_4.h"
#include <string>

using std::string;

/*
class function check_column_win
Win by column if and return true if (each column index)
0, 1,  2,  3 
4, 5,  6,  7 
8, 9, 10, 11 
12,13,14, 15 
else
false
*/

bool tic_tac_toe4::check_column_win() {
    bool win = 0; 
    string previous_player;

    if (player == "X"){
        previous_player = "O";
    } else if (player == "O") {
        previous_player = "X";
    }

    for (int coulmn = 0; coulmn < 4 && win == 0; coulmn++) {
        win = 1;
        for (int row = 0; row < 4; row++) {

            if (pegs.at(coulmn + (row * 4 )) != previous_player){
                win = 0;
            }
        }
    }
    return win;
}


/*
class function check_row_win
Win by row if
0, 1,  2,  3 are equal
4, 5,  6,  7 are equal
8, 9, 10, 11 are equal 
12,13,14, 15 are equal
*/

bool tic_tac_toe4::check_row_win() {
    bool win = 0;
    string previous_player;

    if (player == "X"){
        previous_player = "O";
    } else if (player == "O") {
        previous_player = "X";
    }

    for (int row = 0; row < 4 && win == 0; row++) {
        win = 1;
        for (int coulmn = 0; coulmn < 4; coulmn++) {

            if (pegs.at(coulmn + (row * 4 )) != previous_player ){
                win = 0;
            }
        }
    }
    return win;
}

/*
class function check_diagonal_win
Win diagonally
0, 1,  2,  3
4, 5,  6,  7
8, 9, 10, 11
12,13,14, 15

*/

bool tic_tac_toe4::check_diagonal_win() {
    bool win = 0;
    string previous_player;

    if (player == "X"){
        previous_player = "O";
    } else if (player == "O") {
        previous_player = "X";
    }
   
    if (pegs.at(0) == previous_player && pegs.at(5) == previous_player && pegs.at(10) == previous_player && pegs.at(15) == previous_player) {
        win = 1;
    } else if (pegs.at(3) == previous_player && pegs.at(6) == previous_player && pegs.at(9) == previous_player && pegs.at(12) == previous_player) {
        win = 1;
    } else {
        win = 0;
    }

    return win;
}
