#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Verify tic_tac_toe class") {
	tic_tac_toe game;

	//Test first player set to X
	game.start_game("X");

	REQUIRE(game.get_player() == "X");

	//Test first player set to O
	game.start_game("O");

	REQUIRE(game.get_player() == "O");
	//Test game over if 9 slots are selected

	REQUIRE (game.game_over() == 0);
	game.mark_board(1);
	REQUIRE (game.game_over() == 0);
	game.mark_board(5);
	REQUIRE (game.game_over() == 0);
	game.mark_board(2);
	REQUIRE (game.game_over() == 0);
	game.mark_board(3);
	REQUIRE (game.game_over() == 0);
	game.mark_board(7);
	REQUIRE (game.game_over() == 0);
	game.mark_board(4);
	REQUIRE (game.game_over() == 0);
	game.mark_board(6);
	REQUIRE (game.game_over() == 0);
	game.mark_board(9);
	REQUIRE (game.game_over() == 0);
	game.mark_board(8);

	REQUIRE (game.game_over() == 1);

	REQUIRE(game.get_winner() == "C");

	//Test win by first column
	game.start_game("O");

	REQUIRE (game.game_over() == 0);
	game.mark_board(1);
	REQUIRE (game.game_over() == 0);
	game.mark_board(2);
	REQUIRE (game.game_over() == 0);
	game.mark_board(4);
	REQUIRE (game.game_over() == 0);
	game.mark_board(5);
	REQUIRE (game.game_over() == 0);
	game.mark_board(7);
	REQUIRE (game.game_over() == 1);

	REQUIRE(game.get_winner() == "O");

	//Test win by second column
	game.start_game("X");

	REQUIRE (game.game_over() == 0);
	game.mark_board(2);
	REQUIRE (game.game_over() == 0);
	game.mark_board(1);
	REQUIRE (game.game_over() == 0);
	game.mark_board(5);
	REQUIRE (game.game_over() == 0);
	game.mark_board(4);
	REQUIRE (game.game_over() == 0);
	game.mark_board(8);
	REQUIRE (game.game_over() == 1);


	REQUIRE(game.get_winner() == "X");

	//Test win by third column 
	game.start_game("O");

	REQUIRE (game.game_over() == 0);
	game.mark_board(3);
	REQUIRE (game.game_over() == 0);
	game.mark_board(1);
	REQUIRE (game.game_over() == 0);
	game.mark_board(6);
	REQUIRE (game.game_over() == 0);
	game.mark_board(4);
	REQUIRE (game.game_over() == 0);
	game.mark_board(9);
	REQUIRE (game.game_over() == 1);


	REQUIRE(game.get_winner() == "O");

	//Test win by first row 
	game.start_game("X");

	REQUIRE (game.game_over() == 0);
	game.mark_board(1);
	REQUIRE (game.game_over() == 0);
	game.mark_board(4);
	REQUIRE (game.game_over() == 0);
	game.mark_board(2);
	REQUIRE (game.game_over() == 0);
	game.mark_board(5);
	REQUIRE (game.game_over() == 0);
	game.mark_board(3);
	REQUIRE (game.game_over() == 1);

	REQUIRE(game.get_winner() == "X");

	//Test win by second row 
	game.start_game("X");

	REQUIRE (game.game_over() == 0);
	game.mark_board(4);
	REQUIRE (game.game_over() == 0);
	game.mark_board(1);
	REQUIRE (game.game_over() == 0);
	game.mark_board(5);
	REQUIRE (game.game_over() == 0);
	game.mark_board(2);
	REQUIRE (game.game_over() == 0);
	game.mark_board(6);
	REQUIRE (game.game_over() == 1);

	REQUIRE(game.get_winner() == "X");

	//Test win by third row 
	game.start_game("X");

	REQUIRE (game.game_over() == 0);
	game.mark_board(7);
	REQUIRE (game.game_over() == 0);
	game.mark_board(1);
	REQUIRE (game.game_over() == 0);
	game.mark_board(8);
	REQUIRE (game.game_over() == 0);
	game.mark_board(2);
	REQUIRE (game.game_over() == 0);
	game.mark_board(9);
	REQUIRE (game.game_over() == 1);

	REQUIRE(game.get_winner() == "X");

	//Test win diagonally from top left 
	game.start_game("X");

	REQUIRE (game.game_over() == 0);
	game.mark_board(1);
	REQUIRE (game.game_over() == 0);
	game.mark_board(2);
	REQUIRE (game.game_over() == 0);
	game.mark_board(5);
	REQUIRE (game.game_over() == 0);
	game.mark_board(4);
	REQUIRE (game.game_over() == 0);
	game.mark_board(9);
	REQUIRE (game.game_over() == 1);

	REQUIRE(game.get_winner() == "X");

		//Test win diagonally from top right
	game.start_game("X");

	REQUIRE (game.game_over() == 0);
	game.mark_board(3);
	REQUIRE (game.game_over() == 0);
	game.mark_board(2);
	REQUIRE (game.game_over() == 0);
	game.mark_board(5);
	REQUIRE (game.game_over() == 0);
	game.mark_board(4);
	REQUIRE (game.game_over() == 0);
	game.mark_board(7);
	REQUIRE (game.game_over() == 1);

	REQUIRE(game.get_winner() == "X");

}

TEST_CASE("Verify tic_tac_toe_manager class") {
	tic_tac_toe game;
	tic_tac_toe_manager manager;
	int x_wins = 0;
	int o_wins = 0;
	int ties = 0;

	game.start_game("X");


	game.mark_board(3);

	game.mark_board(2);

	game.mark_board(5);

	game.mark_board(4);

	game.mark_board(7);

	game.game_over();
	manager.save_game(game);

	game.start_game("O");


	game.mark_board(3);

	game.mark_board(2);

	game.mark_board(5);

	game.mark_board(4);

	game.mark_board(7);

	game.game_over();
	manager.save_game(game);

	game.start_game("X");


	game.mark_board(3);

	game.mark_board(2);

	game.mark_board(5);

	game.mark_board(4);

	game.mark_board(7);

	game.game_over();
	manager.save_game(game);

	manager.get_winner_total(o_wins, x_wins, ties);

	REQUIRE(o_wins == 1);
	REQUIRE(x_wins == 2);
	REQUIRE(ties == 0);

}
