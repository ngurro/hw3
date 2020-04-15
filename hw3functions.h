#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <cmath>
using namespace std;

void showMenu(){
    system ("cls");
    cout << "Rational numbers calculator" << endl;
    cout << endl;
    cout << "(A)ddition" << endl;
    cout << "(S)ubtraction" << endl;
    cout << "(Q)uit" << endl;
    cout << endl;
    cout << "Enter your option: ";        
}

void getRational(int *num, int *den){
    string str, numstr, denstr;
    cout << "Please enter fraction (n/d): "; 
    cin >> str;
    stringstream s_stream1(str);
    getline(s_stream1, numstr, '/');
    getline(s_stream1, denstr, '/');
    *num = stoi(numstr);
    *den = stoi(denstr);
}
