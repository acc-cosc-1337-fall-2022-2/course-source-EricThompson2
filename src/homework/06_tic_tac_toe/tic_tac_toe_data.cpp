//cpp
#include "tic_tac_toe_data.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include <vector>
#include <memory>
#include <fstream>
#include <string>

using std::vector;
using std::unique_ptr;
using std::ofstream;
using std::ifstream;
using std::string;

void tic_tac_toe_data::save_games(const vector<unique_ptr<tic_tac_toe>>& games)  {
    ofstream saved_games;
    saved_games.open(file_name);

    //for each instance of tic_tac_toe
    for(auto i = 0; i < games.size(); i++ ) {

        //for each peg on the board
        for(auto j = 0; j < games.at(i)->get_pegs().size(); j++ ) {
            //writes the peg on the board
            saved_games << games.at(i)->get_pegs().at(j); 
        }
        saved_games << games.at(i)->get_winner();
        saved_games << "\n";
    }
    saved_games.close();
}

vector<unique_ptr<tic_tac_toe>> tic_tac_toe_data::get_games() {
    vector<unique_ptr<tic_tac_toe>> boards;
    ifstream file;
    string line;
    string winner;

    file.open(file_name);

    if(file.is_open()) {
        
        while(getline(file, line)) {
            
            vector<string> pegs;

            for (int ch = 0; ch < (line.length()-1); ch++) {
                string peg =  std::string(1,line.at(ch));
                pegs.push_back(peg);
            }

            winner = std::string(1,line.at(line.length()-1));
            unique_ptr<tic_tac_toe> game;
 
            
            if (pegs.size() == 9) {
				game = std::make_unique <tic_tac_toe3>(move(pegs), winner);
			} else if (pegs.size() == 16){
				game = std::make_unique <tic_tac_toe4>(move(pegs), winner);
            }  

            boards.push_back(move(game));
            
        }
        
        
    }
    
    file.close();
    return boards;
}

