//cpp
#include "tic_tac_toe.h"
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cout;
using std::cin;

void tic_tac_toe::clear_board() {
    for (auto i = 0; i < pegs.size(); i++) {
    pegs.at(i) = " ";
    
    } 
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

    while (couter < pegs.size()) {
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
    
    return false;
}

bool tic_tac_toe::check_row_win() {
    
    return false;
}

bool tic_tac_toe::check_diagonal_win() {

    return false;
}

string tic_tac_toe::get_winner() {
    return winner;
}

vector<string> tic_tac_toe::get_pegs() const {
    return pegs;
}

std::ostream& operator<<(std::ostream& out, const tic_tac_toe& game) {

    string output = "";

    if (game.pegs.size() == 9) {
        output =("\033[4m" + game.pegs.at(0) + "|" + game.pegs.at(1) + "|" + game.pegs.at(2) + "\n" +
                             game.pegs.at(3) + "|" + game.pegs.at(4) + "|" + game.pegs.at(5) + "\033[0m" + "\n" + 
                             game.pegs.at(6) + "|" + game.pegs.at(7) + "|" + game.pegs.at(8) + "\n");
    } else if (game.pegs.size() == 16) {
        output =("\033[4m" + game.pegs.at(0) + "|" + game.pegs.at(1) + "|" + game.pegs.at(2) + "|"  + game.pegs.at(3) + "\n" +
                             game.pegs.at(4) + "|" + game.pegs.at(5) + "|" + game.pegs.at(6) + "|"  + game.pegs.at(7) + "\n" +
                             game.pegs.at(8) + "|" + game.pegs.at(9) + "|" + game.pegs.at(10) + "|"  + game.pegs.at(11) + "\033[0m" + "\n" + 
                             game.pegs.at(12) + "|" + game.pegs.at(13) + "|" + game.pegs.at(14) + "|"  + game.pegs.at(15) + "\n");
    }
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
/*
tic_tac_toe::tic_tac_toe (int board_size, std::vector<std::string> p, std::string win):pegs(board_size*board_size, " ") {
    winner = win;
}*/