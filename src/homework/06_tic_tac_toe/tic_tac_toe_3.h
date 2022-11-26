//h
#ifndef TIC_TAC_TOE_3_H
#define TIC_TAC_TOE_3_H

#include "tic_tac_toe.h"
#include <vector>
#include <string>
#include <iostream>

class tic_tac_toe3: public tic_tac_toe {
    
    public:
        tic_tac_toe3(std::vector<std::string> p, std::string winner) : tic_tac_toe(3, p, winner){}
        tic_tac_toe3();
    private:
        
        bool check_column_win();
        virtual bool check_row_win();
        virtual bool check_diagonal_win();

};

#endif