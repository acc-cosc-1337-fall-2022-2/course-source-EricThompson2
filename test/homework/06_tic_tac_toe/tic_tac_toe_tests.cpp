#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"

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

	game.mark_board(1);
	game.mark_board(5);
	game.mark_board(2);
	game.mark_board(3);
	game.mark_board(7);
	game.mark_board(4);
	game.mark_board(6);
	game.mark_board(9);
	game.mark_board(8);

	game.game_over();

	REQUIRE(game.get_winner() == "C");

	//Test win by first column
	game.start_game("X");

	game.mark_board(1);
	game.mark_board(2);
	game.mark_board(4);
	game.mark_board(5);
	game.mark_board(7);

	game.game_over();

	REQUIRE(game.get_winner() == "X");

	//Test win by second column
	game.start_game("X");

	game.mark_board(2);
	game.mark_board(1);
	game.mark_board(5);
	game.mark_board(4);
	game.mark_board(8);

	game.game_over();

	REQUIRE(game.get_winner() == "X");

	//Test win by third column 
	game.start_game("X");

	game.mark_board(3);
	game.mark_board(1);
	game.mark_board(6);
	game.mark_board(4);
	game.mark_board(9);

	game.game_over();

	REQUIRE(game.get_winner() == "X");

	//Test win by first row 
	game.start_game("X");

	game.mark_board(1);
	game.mark_board(4);
	game.mark_board(2);
	game.mark_board(5);
	game.mark_board(3);

	game.game_over();

	REQUIRE(game.get_winner() == "X");

	//Test win by second row 
	game.start_game("X");

	game.mark_board(4);
	game.mark_board(1);
	game.mark_board(5);
	game.mark_board(2);
	game.mark_board(6);

	game.game_over();

	REQUIRE(game.get_winner() == "X");

	//Test win by third row 
	game.start_game("X");

	game.mark_board(7);
	game.mark_board(1);
	game.mark_board(8);
	game.mark_board(2);
	game.mark_board(9);

	game.game_over();

	REQUIRE(game.get_winner() == "X");

	//Test win diagonally from top left 
	game.start_game("X");

	game.mark_board(1);
	game.mark_board(2);
	game.mark_board(5);
	game.mark_board(4);
	game.mark_board(9);

	game.game_over();

	REQUIRE(game.get_winner() == "X");

		//Test win diagonally from top right
	game.start_game("X");

	game.mark_board(3);
	game.mark_board(2);
	game.mark_board(5);
	game.mark_board(4);
	game.mark_board(7);

	game.game_over();

	REQUIRE(game.get_winner() == "X");



}
