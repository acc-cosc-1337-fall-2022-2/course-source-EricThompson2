#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include "tic_tac_toe_manager.h"
#include <memory>
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::cout;
using std::cin;
using std::unique_ptr;
using std::make_unique;
using std::vector;

int main() 
{	
	unique_ptr<tic_tac_toe> game;
	tic_tac_toe_data data;
	string starting_player;
	bool loop_again;
	tic_tac_toe_manager manager(data);
	int size;
	int x_wins;
	int o_wins;
	int ties;

	do {
		do {
			cout << "Do you want to play with a board of size 3 or 4 (enter 3 or 4): ";
			cin >> size;
			
			if (size == 3) {
				vector<string> board(9, " ");
				game = make_unique <tic_tac_toe3>(board, "");
			} else if (size == 4) {
				vector<string> board(16, " ");
				game = make_unique <tic_tac_toe4>(board, "");
			} else {
				cout << "Invalid size" << "\n";
			}

		} while(size != 3 && size != 4);


		cout << "Enter X or O: ";
		cin >> starting_player;

		while (starting_player != "X" && starting_player != "O") {
			cout << "Invalid input try again" << "\n";
			cout << "Enter X or O: ";
			cin >> starting_player;
		}

		game->start_game(starting_player);

		do {
			cout << *game;
			cin >> *game;

		} while(game->game_over() == false);
		cout << *game;

		cout << "The winner is " << game->get_winner() << "\n";
		manager.save_game(game);
		manager.get_winner_total(o_wins, x_wins, ties);
		cout << "X has won " << x_wins << " times O has won " << o_wins << " times and there has been " << ties << " ties" << "\n";

		cout << "Do you want to play again (1 for yes 0 for no): ";
		cin >> loop_again;

	} while (loop_again);

	cout << "\n" << "Here are all played games" << "\n";
	cout << manager;

	return 0;
} 