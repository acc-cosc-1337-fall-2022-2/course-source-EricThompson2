//cpp
#include "tic_tac_toe.h"

#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cout;
using std::cin;

void tic_tac_toe::clear_board() {
    pegs = {" ", " ", " ",
            " ", " ", " ",
            " ", " ", " ",};
}

void tic_tac_toe::mark_board(int position) {
    pegs.at(position-1) = player;
    set_next_player();
}

void tic_tac_toe::set_next_player() {
    if (player == "X") {
        player = "O";
    } else {
        player = "X";
    }
}

bool tic_tac_toe::check_board_full() {
    int couter = 0;
    bool output = 1;

    while (couter < 9) {
        if (pegs.at(couter) == " ") {
            output = 0;
        }
        couter++;
    }
    return output;
}

string tic_tac_toe::get_player() const {
    return player;
}

void tic_tac_toe::start_game(string first_player) {
    player = first_player;
    winner = " ";
    clear_board();
}

bool tic_tac_toe::game_over() {
    bool output;


    if (check_column_win() || check_row_win() || check_diagonal_win()) {

        set_winner();
        output = 1;
    } else if (check_board_full()) {
        output = 1;
        winner = "C";    
    } else {
        output = 0;
    }
    
    return output;
}

void tic_tac_toe::set_winner() {
    if (player == "X"){
        winner = "O";
    } else if (player == "O") {
    winner = "X";
    }
}

bool tic_tac_toe::check_column_win() {
    bool win = 0; 
    string previous_player;

    if (player == "X"){
        previous_player = "O";
    } else if (player == "O") {
        previous_player = "X";
    }

    for (int coulmn = 0; coulmn < 3 && win == 0; coulmn++) {
        win = 1;
        for (int row = 0; row < 3; row++) {

            if (pegs.at(coulmn + (row * 3 )) != previous_player){
                win = 0;
            }
        }
    }
    return win;
}

bool tic_tac_toe::check_row_win() {
    bool win = 0;
    string previous_player;

    if (player == "X"){
        previous_player = "O";
    } else if (player == "O") {
        previous_player = "X";
    }

    for (int row = 0; row < 3 && win == 0; row++) {
        win = 1;
        for (int coulmn = 0; coulmn < 3; coulmn++) {

            if (pegs.at(coulmn + (row * 3 )) != previous_player ){
                win = 0;
            }
        }
    }
    return win;
}

bool tic_tac_toe::check_diagonal_win() {
    bool win = 0;
    string previous_player;

    if (player == "X"){
        previous_player = "O";
    } else if (player == "O") {
        previous_player = "X";
    }
   
    if (pegs.at(0) == previous_player && pegs.at(4) == previous_player && pegs.at(8) == previous_player) {
        win = 1;
    } else if (pegs.at(2) == previous_player && pegs.at(4) == previous_player && pegs.at(6) == previous_player) {
        win = 1;
    } else {
        win = 0;
    }

    return win;
}

string tic_tac_toe::get_winner() {
    return winner;
}

std::ostream& operator<<(std::ostream& out, const tic_tac_toe& game) {

    string output = "";

    output =("\033[4m" + game.pegs.at(0) + "|" + game.pegs.at(1) + "|" + game.pegs.at(2) + "\n" +
                         game.pegs.at(3) + "|" + game.pegs.at(4) + "|" + game.pegs.at(5) + "\033[0m" + "\n" + 
                         game.pegs.at(6) + "|" + game.pegs.at(7) + "|" + game.pegs.at(8) + "\n");

    out << output;

    return out;
}

std::istream& operator>>(std::istream& in, tic_tac_toe& game) {
    int position;

    cout << "Enter a number from 1 to 9: ";
	cin >> position;

	game.mark_board(position);

    return in;
}