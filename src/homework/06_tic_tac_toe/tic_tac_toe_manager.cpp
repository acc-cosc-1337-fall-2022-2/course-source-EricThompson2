//cpp
#include "tic_tac_toe_manager.h"

using std::string;
using std::unique_ptr;
using std::move;


void tic_tac_toe_manager::update_winner_count(string winner) {

    if (winner == "X") {
        x_win++;
    } else if (winner == "O") {
        o_win++;
    } else if (winner == "C") {
        ties++;
    }
}

void tic_tac_toe_manager::save_game(unique_ptr<tic_tac_toe>& game) {
    string winner = game->get_winner();
    update_winner_count(winner);
    games.push_back(move(game));

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
        out << *manager.games.at(count);

        count++;
    }
    return out;
}

tic_tac_toe_manager::tic_tac_toe_manager(tic_tac_toe_data& d):data(d) {
    games = move(data.get_games());    
}

tic_tac_toe_manager::~tic_tac_toe_manager() {
    data.save_games(games);
}