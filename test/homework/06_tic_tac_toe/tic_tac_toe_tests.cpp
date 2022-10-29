#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Verify tic_tac_toe class's") {
	tic_tac_toe game;
	int counter = 1;

	game.start_game("X");

	while (counter < 10) {
		//game.display_board();

		REQUIRE(game.game_over() == false);
		game.mark_board(counter);
		counter++;
	}
	//game.display_board();
	REQUIRE(game.game_over() == true);
}
