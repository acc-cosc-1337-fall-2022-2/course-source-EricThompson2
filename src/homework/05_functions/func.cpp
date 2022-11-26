//add include statements
#include <string>
using std::string;
//add function code here

string reverse_string(string dna) {
    string reversed_dna;
    int count = 0;
    int length = dna.length();

    while(count < length) {
        reversed_dna.push_back(dna.at((length-count)-1));
        count++;
    }
    return reversed_dna;
}

double get_gc_content(const string& dna) {
    double gc_content;
    double amount_of_gc = 0;
    int dna_length = dna.length();
    int count = 0;
    char dna_slice;

    while(count < dna_length) {
        dna_slice = dna.at(count);
        if ( dna_slice == 'G' || dna_slice == 'C') {
            amount_of_gc++;
        }
        count++;
    }
    gc_content = (amount_of_gc / dna_length);
    return gc_content;
}

string get_dna_complement(string dna) {
    string reversed_dna = reverse_string(dna);
    string new_dna = "";
    int dna_length = dna.length();
    int count = 0;
    char dna_slice;

    while (count < dna_length) {
        dna_slice = (reversed_dna.at(count));
        if (dna_slice == 'A') {
            new_dna.push_back('T');
        } else if (dna_slice == 'T') {
            new_dna.push_back('A');
        } else if (dna_slice == 'C') {
            new_dna.push_back('G');
        } else if (dna_slice == 'G') {
            new_dna.push_back('C');
        }
        count++;
    }
    return new_dna;
}