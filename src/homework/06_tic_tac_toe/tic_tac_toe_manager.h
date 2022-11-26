//h

#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include "tic_tac_toe_data.h"
#include <vector>
#include <iostream>
#include <string>

#ifndef TIC_TAC_TOE_MANAGER_H
#define TIC_TAC_TOE_MANAGER_H


class tic_tac_toe_manager {

    friend std::ostream& operator<<(std::ostream& out, const tic_tac_toe_manager& manager);
    public:
        tic_tac_toe_manager() = default;
        tic_tac_toe_manager(tic_tac_toe_data& d);
        ~tic_tac_toe_manager();

        void save_game(std::unique_ptr<tic_tac_toe>& game);
        
        void get_winner_total(int& o, int& w, int&t);
        std::vector<std::unique_ptr<tic_tac_toe>> games;

    private:
        
        int x_win = 0;
        int o_win = 0;
        int ties = 0;
        tic_tac_toe_data data;
        
        void update_winner_count(std::string winner);
};


#endif