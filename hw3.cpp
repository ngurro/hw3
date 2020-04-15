
#include <iostream>
#include "hw3functions.h"
using namespace std;

int main(){
char option;
    do{
    showMenu();
    cin >> option;
    option = tolower(option);
    
    switch (option)
    {
        case 'a':
            add();
            break;
        case 's':
            subtract();
            break;
        default:
            break;
    }
    }
    while (option != 'q');
    return 0;
}
