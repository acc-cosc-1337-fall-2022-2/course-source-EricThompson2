//write include statement for decisions header
#include "decisions.h"
#include <string>

using std::string;
//Write code for function(s) code here
string get_letter_grade_using_if(int grade){
    string letter_grade;     

    if (grade >= 90){
        letter_grade = "A";
    } else if (grade >=80){
        letter_grade = "B";
    } else if (grade >=70){
        letter_grade = "C";
    } else if (grade >=60){
        letter_grade = "D";
    } else {
        letter_grade = "F";
    }
    return letter_grade;
}

string get_letter_grade_using_switch(int grade){
    string letter_grade;
    switch(grade){

    case 90 ... 100:
        letter_grade = "A";
        break;
    case 80 ... 89:
        letter_grade = "B";
        break;
    case 70 ... 79:
        letter_grade = "C";
        break;
    case 60 ... 69:
        letter_grade = "D";
        break;
    case 0 ... 59:
        letter_grade = "F";
        break; }
    return letter_grade;
}