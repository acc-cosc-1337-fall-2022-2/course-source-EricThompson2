/*
use a vector of int with values 8, 4, 20, 88, 66, 99

Prompt user for 1 for Get Max from vector and 2 for Get primes.
Prompt user for a number and return max value or list of primes
and display them to screen.
Program continues until user decides to exit.

*/
#include <iostream>
#include <string>
#include  "func.h"
using std::cin;
using std::cout;
using std::string;


int main() 
{
	double double_result;
	string string_result;
	int option_num;
	string dna;

	cout<<"1-Get GC Content" << "\n" <<
	"2-Get DNA Complement" << "\n" <<
	"3-Exit" << "\n" <<
	"Please select a option: ";
	cin>>option_num;

	switch(option_num){

	case 1:
	cout << "Enter a string of dna: ";
	cin >> dna;

	double_result = get_gc_content(dna);
	cout << "The gc constent of " << dna << " is " << double_result << "\n";
	
	break;

	case 2:
	cout << "Enter a string of dna: ";
	cin >> dna;
	
	string_result = get_dna_complement(dna);
	cout << "The DNA complement of " << dna << " is " << string_result << "\n";

	break;

	}

	return 0;
}