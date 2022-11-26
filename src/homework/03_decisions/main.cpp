//write include statements
#include <iostream>
#include <string>
#include  "decisions.h"
using std::cin;
using std::cout;
using std::string;
int main() 
{
	string letter_grade;
	int option_num;
	int grade;

	cout<<"1-Letter grade using if" << "\n" <<
	"2-Letter grade using switch" << "\n" <<
	"3-Exit" << "\n" <<
	"Please select a option: ";
	cin>>option_num;

	switch(option_num){

	case 1:
	cout << "Enter a grade: ";
	cin >> grade;
	letter_grade = get_letter_grade_using_if(grade);

	if (grade > 0 && grade <= 100) {
		letter_grade = get_letter_grade_using_switch(grade);
		cout <<  letter_grade << "\n";
	}
	else {
		cout << "Number out of range" << "\n";
	}
	
	break;

	case 2:
	cout << "Enter a grade: ";
	cin >> grade;
	
	if (grade > 0 && grade <= 100) {
		letter_grade = get_letter_grade_using_switch(grade);
		cout <<  letter_grade << "\n";
	}
	else {
		cout << "Number out of range" << "\n";
	}

	break;

	}

	return 0;
}