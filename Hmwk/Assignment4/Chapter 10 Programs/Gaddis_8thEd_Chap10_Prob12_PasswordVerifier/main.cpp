/* 
 * File:   main.cpp
 * Author: Colleen Carleton
 * Created on April 3, 2017, 11:22 AM
 * Purpose:  Program that checks potential passwords to see if they meet the
 * criteria of: being at least 6 characters long, containing at least one 
 * uppercase and one lowercase letter, and having at least one digit.
 */

//System Libraries Here
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
int leng(char []);
int upper(char []);
int lower(char []);
int digit(char []);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare and initialize variables
    int length=0; //Is he length greater than 6?
    int up=0;  //Is there at least 1 uppercase letter?
    int low=0; //Is there at least 1 lowercase letter?
    int digits=0; //Is there at least 1 digit?
    
    //Create array to store string
    const int SIZE=51; //Size of array
    char passwrd[SIZE]; //Array to hold string
    
    //Get user's input (password)
    cout<<"Enter a password of at least 6 characters, but no more than 50."<<endl;
    cin.getline(passwrd, SIZE);
    
    //Call functions length, upper, lower, and digit to check requirements
    length=leng(passwrd);
    up=upper(passwrd);
    low=lower(passwrd);
    digits=digit(passwrd);
    
    //Output results
    if (length>=6 && up>=1 && low>=1 && digits>=1) {
        cout<<"This password is suitable."<<endl; //If password meets criteria
    } else if (length<6) {
        //If password is not long enough
        cout<<"This password is not long enough. It must be at least 6 characters."<<endl;
    } else if (up<1 || low<1) {
        //If password does not contain at least 1 uppercase and lowercase letter
        cout<<"Password must contain at least 1 uppercase and 1 lowercase letter."<<endl;
    } else if (digits<1) {
        //If password does not contain a digit
        cout<<"Password must contain at least 1 digit."<<endl;
    }
    

    //Exit
    return 0;
}

int leng(char passwrd[]) {
    //Declare variable
    int len=0;
    
    //Get length
    len=strlen(passwrd);
    
    //Return length
    return len;
}

int upper(char passwrd[]) {
    //Declare variable
    int up=0;
    
    for (int count=0; count<strlen(passwrd); count++) {
        if (isupper(passwrd[count])) {
            up++;
        }
    }
    
    //Return amount of uppercase letters
    return up;
}

int lower(char passwrd[]) {
    //Declare variable
    int low=0;
    
    for (int count=0; count<strlen(passwrd); count++) {
        if (islower(passwrd[count])) {
            low++;
        }
    }
    
    //Return amount of uppercase letters
    return low;
}

int digit(char passwrd[]) {
    //Declare variable
    int digit=0;
    
    for (int count=0; count<strlen(passwrd); count++) {
        if (isdigit(passwrd[count])) {
            digit++;
        }
    }
    
    //Return amount of uppercase letters
    return digit;
}