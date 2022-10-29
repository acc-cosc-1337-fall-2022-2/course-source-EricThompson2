#include "tic_tac_toe.h"
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;

int main() 
{	
	tic_tac_toe game;
	string starting_player;
	int position;
	bool loop_again;

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
			
			game.display_board();
			cout << "Enter a number from 1 to 9: ";
			cin >> position;

			game.mark_board(position);


		} while(game.game_over() == false);
		game.display_board();

		cout << "\n" << "Do you want to play again (1 for yes 0 for no): ";
		cin >> loop_again;

	} while (loop_again);

	return 0;
}