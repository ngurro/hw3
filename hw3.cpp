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
        showMenu();
        cin >> user;
        user = tolower(user);
        if (user == 'a'){
            add();
        }
        else if (user == 's'){
            subtract();
        }
        else{
            break;
        }
    }
    return 0;
}
