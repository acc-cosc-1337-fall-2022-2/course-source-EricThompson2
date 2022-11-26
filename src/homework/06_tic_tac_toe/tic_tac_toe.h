//h

#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#include <string>
#include <vector>
#include <memory>

class tic_tac_toe {

    friend std::ostream& operator<<(std::ostream& out, const tic_tac_toe& game);
    friend std::istream& operator>>(std::istream& in, tic_tac_toe& game);
    public:
        tic_tac_toe (int board_size, std::vector<std::string> b, std::string win):pegs(b) {
        winner = win;
        }
        bool game_over();
        void start_game(std::string first_player);
        void mark_board(int position);
        std::string get_player() const;
        std::string get_winner();
        std::vector<std::string> get_pegs() const;

    protected:
        std::vector<std::string> pegs;
        virtual bool check_column_win();
        virtual bool check_row_win();
        virtual bool check_diagonal_win();
        std::string player;
        std::string winner;

    private:
        void set_next_player();
        bool check_board_full();
        void clear_board();
        void set_winner();
        

};

#endif