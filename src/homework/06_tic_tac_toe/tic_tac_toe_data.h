//h
#ifndef TIC_TAC_TOE_DATA_H
#define TIC_TAC_TOE_DATA_H

    #include <vector>
    #include <memory>
    #include "tic_tac_toe.h"
    #include <string>

    class tic_tac_toe_data {

        public:
            void save_games(const std::vector<std::unique_ptr<tic_tac_toe>>& games);
            std::vector<std::unique_ptr<tic_tac_toe>> get_games();

        private:
            std::string file_name = "savedgames.dat";

    };

#endif