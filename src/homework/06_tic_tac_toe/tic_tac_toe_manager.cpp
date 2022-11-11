//cpp
#include "tic_tac_toe_manager.h"

#include <string>

using std::string;

void tic_tac_toe_manager::update_winner_count(string winner) {

    if (winner == "X") {
        x_win++;
    } else if (winner == "O") {
        o_win++;
    } else if (winner == "C") {
        ties++;
    }
}

void tic_tac_toe_manager::save_game(tic_tac_toe b) {
    string winner = b.get_winner();
    games.push_back(b);

    update_winner_count(winner);
}

void tic_tac_toe_manager::get_winner_total(int& o, int& w, int& t) {
    o = o_win;
    w = x_win;
    t = ties;
}

std::ostream& operator<<(std::ostream& out, const tic_tac_toe_manager& manager) {

    int length = manager.games.size();
    int count = 0;

    while (count < length){
        out << manager.games.at(count);

        count++;
    }
    return out;
}