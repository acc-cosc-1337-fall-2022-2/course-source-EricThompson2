#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;

int main() 
{	
	tic_tac_toe game;
	string starting_player;
	bool loop_again;
	tic_tac_toe_manager manager;
	int x_wins;
	int o_wins;
	int ties;

	do {

		cout << "Enter X or O: ";
		cin >> starting_player;

		while (starting_player != "X" && starting_player != "O") {
			cout << "Invalid input try again" << "\n";
			cout << "Enter X or O: ";
			cin >> starting_player;
		}

		game.start_game(starting_player);

		do {
			cout << game;
			cin >> game;

		} while(game.game_over() == false);
		cout << game;
		manager.save_game(game);
		manager.get_winner_total(o_wins, x_wins, ties);

		cout << "The winner is " << game.get_winner() << "\n";
		cout << "X has won " << x_wins << " times O has won " << o_wins << " times and there has been " << ties << " ties" << "\n";

		cout << "Do you want to play again (1 for yes 0 for no): ";
		cin >> loop_again;

	} while (loop_again);

	cout << "\n" << "Here are all played games" << "\n";
	cout << manager;

	return 0;
}