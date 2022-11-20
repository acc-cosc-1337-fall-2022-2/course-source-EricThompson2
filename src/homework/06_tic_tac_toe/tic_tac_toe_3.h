//h
#ifndef TIC_TAC_TOE_3_H
#define TIC_TAC_TOE_3_H

#include "tic_tac_toe.h"

class tic_tac_toe3: public tic_tac_toe {
    
    public:
        tic_tac_toe3() : tic_tac_toe(3){}

    private:
        bool check_column_win();
        virtual bool check_row_win();
        virtual bool check_diagonal_win();

};

#endif