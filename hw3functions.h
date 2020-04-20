#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <cmath>
using namespace std;

void showMenu(){
    // will clear the screen when showMenu() is called
    system ("cls");
    // outputs the menu to the user 
    cout << "Rational Numbers Calculator" << endl;
    cout << endl;
    cout << "(A)ddition" << endl;
    cout << "(S)ubtraction" << endl;
    cout << "(Q)uit" << endl;
    cout << endl;
    // stores user's response in var user 
    cout << "Enter your option: ";        
}

void getRational(int *num, int *den){     
    // declare string objects                         
    string str, numstr, denstr;
    // unconditonal jump statement to re-enter fraction if user inputs den = 0
    start:
    cout << "Please enter a fraction (n/d): "; 
    // stores fraction as one string object in str
    cin >> str;
    // splits the string str into substrings numstr & denstr using / delimiter
    stringstream s_stream1(str);
    getline(s_stream1, numstr, '/');
    getline(s_stream1, denstr, '/');
    // converts strings numstr & denstr into integers 
    *num = stoi(numstr);
    *den = stoi(denstr);
    // jumps back to start: in the function if *den = 0
    if (*den == 0){
        cout << "Invalid fraction, please try again." << endl;
        goto start;
    }
}                                                                       // Pseudocode for Euclid's algorithm
int euclid(int a, int b){                                               // Function euclid with int a and int b as arguments                      
    // gets the absolute value of the greatest common factors           
    a = abs(a);                                                         //     Convert variable a to its absolute value    
    b = abs(b);                                                         //     Convert variable b to its absolute value 
    // var remainder is equal to 
    int remainder = a % b;                                              //     Initialise an integer variable named remainder to a modulus b (the remainder after a is divided by b) 
    // while the remainder is != to 0, the divisor becomes the dividend 
    while (remainder != 0){                                             //     WHILE remainder does not equal zero   
        a = b;                                                          //          a will be equal to b 
        b = remainder;                                                  //          b will be equal to remainder 
        // when the remainder is zero, your divisor becomes your gcf
        // the divisor that gives you a remainder of zero is your gcf
        remainder = a % b;                                              //          remainder will be equal to a modulus b (the remainder after a is divided by b)
    }
    return b;                                                           //     Return the value of b
}
void reduce (int *num, int *den){
    // intitialised gcf var
    int gcf  = 0;
    // applies Euclid's algorithm to *num and *den to find its gcf
    gcf = euclid(*num, *den);
    // once the gcf is found, divide both the numerator and denominator by the gcf
    *num = (*num / gcf);
    *den = (*den / gcf);
}

void DisplayRational(int num, int den){
    //removes the fractional component if its a whole number
    if (den == 1){
        cout << num;
    }
    // if the result is not a whole number, the fractional component is displayed to the user
    else{
        cout << num << "/" << den; 
    }
}
                                                                 // Pseudocode for subtract() algorithm
void subtract(){                                                 // Function subtract() start     
    int anum, aden, num1, den1, num2, den2;                      //     Initialise integer variables anum, aden, num1, den1, num2, and den2     
    while (true){                                                //     WHILE user does not enter 'n' or 'N'
        system ("cls");                                          //        Clear the console 
        cout << "Subtraction of rational numbers" << endl;       //        Print Subtraction of rational numbers  
        getRational(&num1, &den1);                               //        Call function getRational within inputs &num1 and &den1    
        getRational(&num2, &den2);                               //        Call function getRational within inputs &num2 and &den2 
        reduce(&num1, &den1);                                    //        Call function reduce within inputs &num1 and &num2 
        reduce(&num2, &den2);                                    //        Call function reduce within inputs &num2 and &den2 
        anum = ((num1 * den2) - (num2 * den1));                  //        Initialise variable anum to num1 times den2 minus num2 times den1 
        aden = (den1 * den2);                                    //        Initialise variable aden to den1 times den2 
        reduce(&anum, &aden);                                    //        Call function reduce within inputs &anum and &aden
        cout << "The result of ";                                //        Print The result of 
        DisplayRational(num1, den1);                             //        Call function DisplayRational within inputs num1 and den1 
        cout << " - ";                                           //        Print the minus sign (-) 
        DisplayRational(num2, den2);                             //        Call function DisplayRational within inputs num2 and den2 
        cout << " = ";                                           //        Print the equal sign (=) 
        DisplayRational(anum, aden);                             //        Call function DisplayRational within inputs anum and aden 
        char user;                                               //        Initialise a character variable named user 
        cout << endl;                                            //        Print a new line 
        cout << "Do you want to do more subtractions? (Y/N): ";  //        Print Do you want to do more subtractions? (Y/N):  
        cin >> user; cin.ignore();                               //        Store the response in the char variable user; Ignore the newline from the stream
        user = tolower(user);                                    //        Convert the user's input to lowercase 
        if (user == 'n')                                         //        IF user enters 'n' or 'N'
            break;                                               //             END WHILE LOOP
    }
}
                                                                 // Pseudocode for add() algorithm
void add(){                                                      // Function add() start 
    int anum, aden, num1, den1, num2, den2;                      //     Initialise integer variables anum, aden, num1, den1, num2, and den2
    while (true){                                                //     WHILE user does not enter 'n' or 'N'
        system ("cls");                                          //         Clear the console
        cout << "Addition of rational numbers" << endl;          //         Print Addition of rational numbers
        getRational(&num1, &den1);                               //         Call function getRational within inputs &num1 and &den1
        getRational(&num2, &den2);                               //         Call function getRational within inputs &num2 and &den2
        reduce(&num1, &den1);                                    //         Call function reduce within inputs &num1 and &den1
        reduce(&num2, &den2);                                    //         Call function reduce within inputs &num2 and &den2
        anum = ((num1 * den2) + (num2 * den1));                  //         Initialise variable anum to num2 times den2 plus num2 times den1
        aden = (den1 * den2);                                    //         Initialise variable aden to den1 times den2
        reduce(&anum, &aden);                                    //         Call function reduce within inputs &anum and &aden
        cout << "The result of ";                                //         Print The result of
        DisplayRational(num1, den1);                             //         Call function DisplayRational within inputs num1 and den1
        cout << " + ";                                           //         Print the addition sign (+)
        DisplayRational(num2, den2);                             //         Call function DisplayRational within inputs num2 and den2
        cout << " = ";                                           //         Print the equal sign (=)
        DisplayRational(anum, aden);                             //         Call function DisplayRational within inputs anum and aden
        char user;                                               //         Initialise a character variable named user
        cout << endl;                                            //         Print a new line
        cout << "Do you want to do more additions? (Y/N): ";     //         Print Do you want to do more additions? (Y/N): 
        cin >> user; cin.ignore();                               //         Store the response in char variable user; Ignore the newline from the stream
        user = tolower(user);                                    //         Convert the user's input to lowercase
        if (user == 'n')                                         //         IF user enters 'n' or 'N'
            break;                                               //             END WHILE LOOP
    }
}
