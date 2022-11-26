//write include statements
#include <iostream>
#include "dna.h"
//write using statements
using std::cin;
using std::cout;

/*
Write code that prompts user to enter 1 for Get GC Content, 
or 2 for Get DNA Complement.  The program will prompt user for a 
DNA string and call either get gc content or get dna complement
function and display the result. Program runs as long as 
user enters a y or Y.
*/
int main() 
{
	int num1;
	int num2;
	int option_num;
	do {
		cout<<"1-Factorial" << "\n" <<
		"2-Greatest Common Divisor" << "\n" <<
		"3-Exit" << "\n" <<
		"Please select a option: ";
		cin >> option_num;

		switch(option_num) {

		case 1:
			cout<< "Please enter a number to find the Factorial of ";
			cin >> num1;

			cout << "The Factorial of " << num1 <<" is " << factorial(num1) << "\n" << "\n" ;
			break;

		case 2:
			cout<< "Please enter the first number to find the Greatest Common Divisor of ";
			cin >> num1;

			cout<< "Please enter the second number to find the Greatest Common Divisor of " ;
			cin >> num2;

			cout << "The Greatest Common Divisor of " << num1 << " and "<< num2 <<" is " << gcd(num1, num2) << "\n" << "\n";
			break;
		
		case 3:

			cout << "Are you sure want to exit(0 for no / 1 for yes)";
			cin >> num1;
			if (num1 == 0) {
				option_num = 0;
			}

		}



	} while(option_num != 3);


	return 0;
}