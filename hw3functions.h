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
    start:
    cout << "Please enter fraction (n/d): "; 
    cin >> str;
    stringstream s_stream1(str);
    getline(s_stream1, numstr, '/');
    getline(s_stream1, denstr, '/');
    *num = stoi(numstr);
    *den = stoi(denstr);
    if (*den == 0){
        cout << "Invalid fraction, please try again." << endl;
        goto start;
    }
}
int euclid(int a, int b){
    a = abs(a);
    b = abs(b);
    int remainder = a % b;
    while (remainder != 0){
        a = b;
        b = remainder;
        remainder = a % b;
    }
    return b;
}
void reduce (int *num, int *den){
    int gcf  = 0;
    gcf = euclid(*num, *den);
    *num = (*num / gcf);
    *den = (*den / gcf);
}

void DisplayRational(int num, int den){
    if (den == 1){
        cout << num;
    }
    else{
        cout << num << "/" << den; 
    }
}

void subtract(){
    int anum, aden, num1, den1, num2, den2;
    while (true){
        system ("cls");
        cout << "Substraction of rational numbers" << endl;
        getRational(&num1, &den1);
        getRational(&num2, &den2);
        reduce(&num1, &den1);
        reduce(&num2, &den2);
        anum = ((num1 * den2) - (num2 * den1));
        aden = (den1 * den2); 
        reduce(&anum, &aden);
        cout << "The result of ";
        DisplayRational(num1, den1);
        cout << " - ";
        DisplayRational(num2, den2);
        cout << " = ";
        DisplayRational(anum, aden);
        char user;
        cout << endl;
        cout << "Do you want to do more substractions? (Y/N): ";
        cin >> user; cin.ignore();
        user = tolower(user);
        if (user == 'n')
            break;  
    }
}
void add(){
    int anum, aden, num1, den1, num2, den2;
    while (true){
        system ("cls");
        cout << "Addition of rational numbers" << endl;
        getRational(&num1, &den1);
        getRational(&num2, &den2);
        reduce(&num1, &den1);
        reduce(&num2, &den2);
        anum = ((num1 * den2) + (num2 * den1));
        aden = (den1 * den2); 
        reduce(&anum, &aden);
        cout << "The result of ";
        DisplayRational(num1, den1);
        cout << " + ";
        DisplayRational(num2, den2);
        cout << " = ";
        DisplayRational(anum, aden);
        char user;
        cout << endl;
        cout << "Do you want to do more additions? (Y/N): ";
        cin >> user; cin.ignore();
        user = tolower(user);
        if (user == 'n')
            break; 
    }
}
