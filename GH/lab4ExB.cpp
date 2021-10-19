//  ENSF 614  Lab4 - exercise B
// lab4ExB.cpp

#include<vector>
#include<string>
#include <iostream>
using std::cout;
using std::cerr;
using std::endl;
using std::vector;
using std::string;

typedef vector<string> String_Vector;

String_Vector transpose(const String_Vector& sv);
// REQUIRES:
//    sv.size() >= 1
//    All the strings in sv are the same length, and that length is >= 1.
// PROMISES:
//    Return value is the "transpose" of sv, as defined in the Exercise B
//    instructions.

int main() {
    
    const int ROWS = 5;
    const int COLS = 4;
    
    char c = 'A';
    String_Vector sv;
    sv.resize(ROWS);
    
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++) {
            sv.at(i).push_back(c);
            c++;
            if(c == 'Z' + 1)
                c = 'a';
            else if (c == 'z' + 1)
                c = 'A';
        }
    }
    

    for(int i = 0; i < ROWS; i++) {
        cout<< sv.at(i);
        cout << endl;
    }

    cout << "\nTransposed vector: \n";
    
    String_Vector vs = transpose(sv);
    for(int i = 0; i < (int)vs.size(); i++)
        cout << vs.at(i) << endl;
    
    return 0;
}


/* File Name: Lab4ExB.cpp
* Lab # and Assignment #: Lab #4 Exercise B
* Lab section: 1
* Completed by: Graydon Hall and Jared Kraus
* Submission Date: 2021-10-19
*/
String_Vector transpose (const String_Vector& sv) {

    int sv_rows = sv.size();
    int sv_cols = sv.at(0).size();

    int vs_rows = sv_cols;
    int vs_cols = sv_rows;
    
    String_Vector vs;
    vs.resize(vs_rows);

    for(int i=0; i<vs_rows; i++){
        for(int j=0; j<vs_cols; j++){
            vs.at(i).push_back(sv.at(j).at(i));
        }
    }
    
    return vs;
    
}
