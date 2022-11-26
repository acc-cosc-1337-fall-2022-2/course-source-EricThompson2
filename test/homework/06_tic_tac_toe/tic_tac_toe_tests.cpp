#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include "tic_tac_toe_manager.h"
#include <iostream>
#include <vector>
#include <string>

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Verify tic_tac_toe on size 3 class") {
	std::unique_ptr<tic_tac_toe> game;
	std::vector<std::string> board(9, " ");
	game = std::make_unique <tic_tac_toe3>(board, "");

	//Test first player set to X
	game->start_game("X");

	REQUIRE(game->get_player() == "X");

	//Test first player set to O
	game->start_game("O");

	REQUIRE(game->get_player() == "O");
	//Test game over if 9 slots are selected

	REQUIRE (game->game_over() == 0);
	game->mark_board(1);
	REQUIRE (game->game_over() == 0);
	game->mark_board(5);
	REQUIRE (game->game_over() == 0);
	game->mark_board(2);
	REQUIRE (game->game_over() == 0);
	game->mark_board(3);
	REQUIRE (game->game_over() == 0);
	game->mark_board(7);
	REQUIRE (game->game_over() == 0);
	game->mark_board(4);
	REQUIRE (game->game_over() == 0);
	game->mark_board(6);
	REQUIRE (game->game_over() == 0);
	game->mark_board(9);
	REQUIRE (game->game_over() == 0);
	game->mark_board(8);

	REQUIRE (game->game_over() == 1);

	REQUIRE(game->get_winner() == "C");

	//Test win by first column
	game->start_game("O");

	REQUIRE (game->game_over() == 0);
	game->mark_board(1);
	REQUIRE (game->game_over() == 0);
	game->mark_board(2);
	REQUIRE (game->game_over() == 0);
	game->mark_board(4);
	REQUIRE (game->game_over() == 0);
	game->mark_board(5);
	REQUIRE (game->game_over() == 0);
	game->mark_board(7);
	REQUIRE (game->game_over() == 1);

	REQUIRE(game->get_winner() == "O");

	//Test win by second column
	game->start_game("X");

	REQUIRE (game->game_over() == 0);
	game->mark_board(2);
	REQUIRE (game->game_over() == 0);
	game->mark_board(1);
	REQUIRE (game->game_over() == 0);
	game->mark_board(5);
	REQUIRE (game->game_over() == 0);
	game->mark_board(4);
	REQUIRE (game->game_over() == 0);
	game->mark_board(8);
	REQUIRE (game->game_over() == 1);


	REQUIRE(game->get_winner() == "X");

	//Test win by third column 
	game->start_game("O");

	REQUIRE (game->game_over() == 0);
	game->mark_board(3);
	REQUIRE (game->game_over() == 0);
	game->mark_board(1);
	REQUIRE (game->game_over() == 0);
	game->mark_board(6);
	REQUIRE (game->game_over() == 0);
	game->mark_board(4);
	REQUIRE (game->game_over() == 0);
	game->mark_board(9);
	REQUIRE (game->game_over() == 1);


	REQUIRE(game->get_winner() == "O");

	//Test win by first row 
	game->start_game("X");

	REQUIRE (game->game_over() == 0);
	game->mark_board(1);
	REQUIRE (game->game_over() == 0);
	game->mark_board(4);
	REQUIRE (game->game_over() == 0);
	game->mark_board(2);
	REQUIRE (game->game_over() == 0);
	game->mark_board(5);
	REQUIRE (game->game_over() == 0);
	game->mark_board(3);
	REQUIRE (game->game_over() == 1);

	REQUIRE(game->get_winner() == "X");

	//Test win by second row 
	game->start_game("X");

	REQUIRE (game->game_over() == 0);
	game->mark_board(4);
	REQUIRE (game->game_over() == 0);
	game->mark_board(1);
	REQUIRE (game->game_over() == 0);
	game->mark_board(5);
	REQUIRE (game->game_over() == 0);
	game->mark_board(2);
	REQUIRE (game->game_over() == 0);
	game->mark_board(6);
	REQUIRE (game->game_over() == 1);

	REQUIRE(game->get_winner() == "X");

	//Test win by third row 
	game->start_game("X");

	REQUIRE (game->game_over() == 0);
	game->mark_board(7);
	REQUIRE (game->game_over() == 0);
	game->mark_board(1);
	REQUIRE (game->game_over() == 0);
	game->mark_board(8);
	REQUIRE (game->game_over() == 0);
	game->mark_board(2);
	REQUIRE (game->game_over() == 0);
	game->mark_board(9);
	REQUIRE (game->game_over() == 1);

	REQUIRE(game->get_winner() == "X");

	//Test win diagonally from top left 
	game->start_game("X");

	REQUIRE (game->game_over() == 0);
	game->mark_board(1);
	REQUIRE (game->game_over() == 0);
	game->mark_board(2);
	REQUIRE (game->game_over() == 0);
	game->mark_board(5);
	REQUIRE (game->game_over() == 0);
	game->mark_board(4);
	REQUIRE (game->game_over() == 0);
	game->mark_board(9);
	REQUIRE (game->game_over() == 1);

	REQUIRE(game->get_winner() == "X");

		//Test win diagonally from top right
	game->start_game("X");

	REQUIRE (game->game_over() == 0);
	game->mark_board(3);
	REQUIRE (game->game_over() == 0);
	game->mark_board(2);
	REQUIRE (game->game_over() == 0);
	game->mark_board(5);
	REQUIRE (game->game_over() == 0);
	game->mark_board(4);
	REQUIRE (game->game_over() == 0);
	game->mark_board(7);
	REQUIRE (game->game_over() == 1);

	REQUIRE(game->get_winner() == "X");

} 
/*
TEST_CASE("Verify tic_tac_toe_manager on size 3 class") {
	std::unique_ptr<tic_tac_toe> game;
	std::vector<std::string> board(9, " ");
	game = std::make_unique <tic_tac_toe3>(board, "");
	tic_tac_toe_manager manager;
	int x_wins = 0;
	int o_wins = 0;
	int ties = 0;

	game->start_game("X");

	game->mark_board(3);
	game->mark_board(2);
	game->mark_board(5);
	game->mark_board(4);
	game->mark_board(7);

	game->game_over();
	manager.save_game(game);

	game = std::make_unique <tic_tac_toe3>();
	game->start_game("O");

	game->mark_board(3);
	game->mark_board(2);
	game->mark_board(5);
	game->mark_board(4);
	game->mark_board(7);

	game->game_over();
	manager.save_game(game);

	game = std::make_unique <tic_tac_toe3>();
	game->start_game("X");

	game->mark_board(3);
	game->mark_board(2);
	game->mark_board(5);
	game->mark_board(4);
	game->mark_board(7);

	game->game_over();
	manager.save_game(game);

	manager.get_winner_total(o_wins, x_wins, ties);

	REQUIRE(o_wins == 1);
	REQUIRE(x_wins == 2);
	REQUIRE(ties == 0);

}
*/
TEST_CASE("Verify tic_tac_toe on size 4 class") {
	std::unique_ptr<tic_tac_toe> game;
	std::vector<std::string> board(16, " ");
	game = std::make_unique <tic_tac_toe4>(board, "");

	//Test first player set to X
	game->start_game("X");

	REQUIRE(game->get_player() == "X");

	//Test first player set to O
	game->start_game("O");

	REQUIRE(game->get_player() == "O");
	//Test game over if 16 slots are selected

	REQUIRE (game->game_over() == 0);
	game->mark_board(1);
	REQUIRE (game->game_over() == 0);
	game->mark_board(2);
	REQUIRE (game->game_over() == 0);
	game->mark_board(3);
	REQUIRE (game->game_over() == 0);
	game->mark_board(4);
	REQUIRE (game->game_over() == 0);
	game->mark_board(5);
	REQUIRE (game->game_over() == 0);
	game->mark_board(6);
	REQUIRE (game->game_over() == 0);
	game->mark_board(7);
	REQUIRE (game->game_over() == 0);
	game->mark_board(8);
	REQUIRE (game->game_over() == 0);
	game->mark_board(9);
	REQUIRE (game->game_over() == 0);
	game->mark_board(10);
	REQUIRE (game->game_over() == 0);
	game->mark_board(11);
	REQUIRE (game->game_over() == 0);
	game->mark_board(12);
	REQUIRE (game->game_over() == 0);
	game->mark_board(14);
	REQUIRE (game->game_over() == 0);
	game->mark_board(13);
	REQUIRE (game->game_over() == 0);
	game->mark_board(16);
	REQUIRE (game->game_over() == 0);
	game->mark_board(15);


	REQUIRE (game->game_over() == 1);

	REQUIRE(game->get_winner() == "C");

	//Test win by first column
	game->start_game("O");

	REQUIRE (game->game_over() == 0);
	game->mark_board(1);
	REQUIRE (game->game_over() == 0);
	game->mark_board(4);
	REQUIRE (game->game_over() == 0);
	game->mark_board(5);
	REQUIRE (game->game_over() == 0);
	game->mark_board(8);
	REQUIRE (game->game_over() == 0);
	game->mark_board(9);
	REQUIRE (game->game_over() == 0);
	game->mark_board(12);
	REQUIRE (game->game_over() == 0);
	game->mark_board(13);

	REQUIRE (game->game_over() == 1);
	

	REQUIRE(game->get_winner() == "O");

	//Test win by second column
	game->start_game("X");

	REQUIRE (game->game_over() == 0);
	game->mark_board(2);
	REQUIRE (game->game_over() == 0);
	game->mark_board(4);
	REQUIRE (game->game_over() == 0);
	game->mark_board(6);
	REQUIRE (game->game_over() == 0);
	game->mark_board(8);
	REQUIRE (game->game_over() == 0);
	game->mark_board(10);
	REQUIRE (game->game_over() == 0);
	game->mark_board(12);
	REQUIRE (game->game_over() == 0);
	game->mark_board(14);
	REQUIRE (game->game_over() == 1);


	REQUIRE(game->get_winner() == "X");

	//Test win by third column 
	game->start_game("O");

	REQUIRE (game->game_over() == 0);
	game->mark_board(3);
	REQUIRE (game->game_over() == 0);
	game->mark_board(4);
	REQUIRE (game->game_over() == 0);
	game->mark_board(7);
	REQUIRE (game->game_over() == 0);
	game->mark_board(8);
	REQUIRE (game->game_over() == 0);
	game->mark_board(11);
	REQUIRE (game->game_over() == 0);
	game->mark_board(12);
	REQUIRE (game->game_over() == 0);
	game->mark_board(15);
	REQUIRE (game->game_over() == 1);


	REQUIRE(game->get_winner() == "O");

	//Test win by fourth column 
	game->start_game("X");

	REQUIRE (game->game_over() == 0);
	game->mark_board(4);
	REQUIRE (game->game_over() == 0);
	game->mark_board(1);
	REQUIRE (game->game_over() == 0);
	game->mark_board(8);
	REQUIRE (game->game_over() == 0);
	game->mark_board(2);
	REQUIRE (game->game_over() == 0);
	game->mark_board(12);
	REQUIRE (game->game_over() == 0);
	game->mark_board(3);
	REQUIRE (game->game_over() == 0);
	game->mark_board(16);
	REQUIRE (game->game_over() == 1);

	REQUIRE(game->get_winner() == "X");

	//Test win by first row 
	game->start_game("X");

	REQUIRE (game->game_over() == 0);
	game->mark_board(1);
	REQUIRE (game->game_over() == 0);
	game->mark_board(13);
	REQUIRE (game->game_over() == 0);
	game->mark_board(2);
	REQUIRE (game->game_over() == 0);
	game->mark_board(14);
	REQUIRE (game->game_over() == 0);
	game->mark_board(3);
	REQUIRE (game->game_over() == 0);
	game->mark_board(15);
	REQUIRE (game->game_over() == 0);
	game->mark_board(4);
	REQUIRE (game->game_over() == 1);

	REQUIRE(game->get_winner() == "X");

	//Test win by second row 
	game->start_game("X");

	REQUIRE (game->game_over() == 0);
	game->mark_board(5);
	REQUIRE (game->game_over() == 0);
	game->mark_board(13);
	REQUIRE (game->game_over() == 0);
	game->mark_board(6);
	REQUIRE (game->game_over() == 0);
	game->mark_board(14);
	REQUIRE (game->game_over() == 0);
	game->mark_board(7);
	REQUIRE (game->game_over() == 0);
	game->mark_board(15);
	REQUIRE (game->game_over() == 0);
	game->mark_board(8);
	REQUIRE (game->game_over() == 1);

	REQUIRE(game->get_winner() == "X");

	//Test win by third row 
	game->start_game("X");

	REQUIRE (game->game_over() == 0);
	game->mark_board(9);
	REQUIRE (game->game_over() == 0);
	game->mark_board(13);
	REQUIRE (game->game_over() == 0);
	game->mark_board(10);
	REQUIRE (game->game_over() == 0);
	game->mark_board(14);
	REQUIRE (game->game_over() == 0);
	game->mark_board(11);
	REQUIRE (game->game_over() == 0);
	game->mark_board(15);
	REQUIRE (game->game_over() == 0);
	game->mark_board(12);
	REQUIRE (game->game_over() == 1);

	REQUIRE(game->get_winner() == "X");

	//Test win by fourth row 
	game->start_game("X");

	REQUIRE (game->game_over() == 0);
	game->mark_board(13);
	REQUIRE (game->game_over() == 0);
	game->mark_board(1);
	REQUIRE (game->game_over() == 0);
	game->mark_board(14);
	REQUIRE (game->game_over() == 0);
	game->mark_board(2);
	REQUIRE (game->game_over() == 0);
	game->mark_board(15);
	REQUIRE (game->game_over() == 0);
	game->mark_board(3);
	REQUIRE (game->game_over() == 0);
	game->mark_board(16);
	REQUIRE (game->game_over() == 1);

	REQUIRE(game->get_winner() == "X");

	//Test win diagonally from top left 
	game->start_game("X");

	REQUIRE (game->game_over() == 0);
	game->mark_board(1);
	REQUIRE (game->game_over() == 0);
	game->mark_board(4);
	REQUIRE (game->game_over() == 0);
	game->mark_board(6);
	REQUIRE (game->game_over() == 0);
	game->mark_board(8);
	REQUIRE (game->game_over() == 0);
	game->mark_board(11);
	REQUIRE (game->game_over() == 0);
	game->mark_board(12);
	REQUIRE (game->game_over() == 0);
	game->mark_board(16);
	REQUIRE (game->game_over() == 1);

	REQUIRE(game->get_winner() == "X");

		//Test win diagonally from top right
	game->start_game("X");

	REQUIRE (game->game_over() == 0);
	game->mark_board(4);
	REQUIRE (game->game_over() == 0);
	game->mark_board(1);
	REQUIRE (game->game_over() == 0);
	game->mark_board(7);
	REQUIRE (game->game_over() == 0);
	game->mark_board(2);
	REQUIRE (game->game_over() == 0);
	game->mark_board(10);
	REQUIRE (game->game_over() == 0);
	game->mark_board(3);
	REQUIRE (game->game_over() == 0);
	game->mark_board(13);
	REQUIRE (game->game_over() == 1);

	REQUIRE(game->get_winner() == "X");

} 
/*
TEST_CASE("Verify tic_tac_toe_manager on size 4 class") {
	std::unique_ptr<tic_tac_toe> game;
	std::vector<std::string> board(16, " ");
	game = std::make_unique <tic_tac_toe4>(board, "");
	tic_tac_toe_manager manager;
	int x_wins = 0;
	int o_wins = 0;
	int ties = 0;

	game->start_game("X");

	game->mark_board(1);
	game->mark_board(5);
	game->mark_board(2);
	game->mark_board(6);
	game->mark_board(3);
	game->mark_board(7);
	game->mark_board(4);

	game->game_over();
	manager.save_game(game);

	game = std::make_unique <tic_tac_toe3>();
	game->start_game("O");

	game->mark_board(1);
	game->mark_board(5);
	game->mark_board(2);
	game->mark_board(6);
	game->mark_board(3);
	game->mark_board(7);
	game->mark_board(4);
	game->game_over();
	manager.save_game(game);

	game = std::make_unique <tic_tac_toe3>();
	game->start_game("X");

	game->mark_board(1);
	game->mark_board(5);
	game->mark_board(2);
	game->mark_board(6);
	game->mark_board(3);
	game->mark_board(7);
	game->mark_board(4);

	game->game_over();
	manager.save_game(game);

	manager.get_winner_total(o_wins, x_wins, ties);

	REQUIRE(o_wins == 1);
	REQUIRE(x_wins == 2);
	REQUIRE(ties == 0);

}
*/
