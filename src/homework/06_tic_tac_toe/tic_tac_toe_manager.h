//h

#include "tic_tac_toe.h"
#include <vector>
#include <iostream>
#include <string>

#ifndef TIC_TAC_TOE_MANAGER_H
#define TIC_TAC_TOE_MANAGER_H


class tic_tac_toe_manager {

    friend std::ostream& operator<<(std::ostream& out, const tic_tac_toe_manager& manager);
    public:
        void save_game(std::unique_ptr<tic_tac_toe>& game);
        
        void get_winner_total(int& o, int& w, int&t);
        std::vector<std::unique_ptr<tic_tac_toe>> games;

    private:
        
        int x_win = 0;
        int o_win = 0;
        int ties = 0;

        void update_winner_count(std::string winner);

};


#endif