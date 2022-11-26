#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "func.h"
#include <string>

using std::string;
TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Verify reverse_string Function") {
	REQUIRE(reverse_string("AGCTATAG") == "GATATCGA" );
	REQUIRE(reverse_string("CGCTATAG") == "GATATCGC" );
}

TEST_CASE("Verify get_gc_content Function") {
	REQUIRE (get_gc_content("AGCTATAG") == 0.375);
	REQUIRE	(get_gc_content("CGCTATAG") == 0.50);

}

TEST_CASE("Verify get_dna_complement Function") {
	REQUIRE (get_dna_complement("AAAACCCGGT") == "ACCGGGTTTT" );
	REQUIRE (get_dna_complement("CCCGGAAAAT") == "ATTTTCCGGG" );
}