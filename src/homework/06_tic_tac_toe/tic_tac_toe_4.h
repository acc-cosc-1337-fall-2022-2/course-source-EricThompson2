//h
#ifndef TIC_TAC_TOE_4_H
#define TIC_TAC_TOE_4_H

#include "tic_tac_toe.h"

class tic_tac_toe4: public tic_tac_toe {
    
    public:
        tic_tac_toe4() : tic_tac_toe(4){}

    private:
        bool check_column_win();
        virtual bool check_row_win();
        virtual bool check_diagonal_win();

};

#endif