//write include statements
#include <iostream>
#include "hwexpressions.h"
//write namespace using statement for cout
using std::cout;
using std::cin;
/*
Call multiply_numbers with 10 and 10 parameter values and display function result
*/
int main()
{
	double meal_amount;
	double tip_rate;
	double tip_amount;
	double tax_amount;
	double total;

	cout<< "Enter the meal amount: ";
	cin>>meal_amount;

	tax_amount = get_sales_tax_amount(meal_amount);

	cout<< "Enter the tip amount in percent don't include the % symbol: ";
	cin>>tip_rate;

	tip_amount = get_tip_amount(meal_amount, tip_rate);

	total = meal_amount + tax_amount + tip_amount;

	cout <<"\n" <<"Meal Amount: " << meal_amount <<"\n"
	<<"Sales Tax:   " << tax_amount <<"\n"
	<<"Tip Amount:  " << tip_amount <<"\n"
	<<"Total:       " << total <<"\n";


	return 0;
}
