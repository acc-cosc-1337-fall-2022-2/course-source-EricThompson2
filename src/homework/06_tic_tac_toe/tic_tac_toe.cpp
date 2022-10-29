//cpp
#include "tic_tac_toe.h"

#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;
using std::cout;
using std::cin;

void tic_tac_toe::clear_board() {
    pegs = {" ", " ", " ",
            " ", " ", " ",
            " ", " ", " ",};
}

void tic_tac_toe::display_board() const {
    string output = "";

        output =("\033[4m" + pegs.at(0) + "|" + pegs.at(1) + "|" + pegs.at(2) + "\n" +
                             pegs.at(3) + "|" + pegs.at(4) + "|" + pegs.at(5) + "\033[0m" + "\n" + 
                             pegs.at(6) + "|" + pegs.at(7) + "|" + pegs.at(8) + "\n");

    cout << output;

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
    clear_board();
}

bool tic_tac_toe::game_over() {

    return check_board_full();
}