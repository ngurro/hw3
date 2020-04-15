
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
