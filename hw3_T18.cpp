//*******************************************************************************
// Team 18         CSCI/CMPE 1370            Spring 2020            Homework # 3
// Nayeli Gurrola
// Johnathan Lira
// This program provides the user with two arithmetic operations to operate on 
// two rational numbers given by the user. It then outputs a result in its 
// reduced form. The user chooses whether they want to perform more operations or
// not.
//*******************************************************************************
#include <iostream>
#include "hw3functions.h"
using namespace std;

int main(){
char user;
    while (true){
        // print showMenu() to the screen
        showMenu();
        // stores user input in var user
        cin >> user;
        // converts input from user to lower to accept both lowercase and UPPERCASE input
        user = tolower(user);
        // if user chooses additon, add() function is called
        if (user == 'a'){
            add();
        }
        // if user choosed subtraction, subtract() function is called
        else if (user == 's'){
            subtract();
        }
        // if neither options are chosen, program stops
        else{
            break;
        }
    }
    return 0;
}
