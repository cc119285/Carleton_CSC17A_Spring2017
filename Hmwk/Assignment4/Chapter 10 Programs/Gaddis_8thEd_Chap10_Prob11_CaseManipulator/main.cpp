/* 
 * File:   main.cpp
 * Author: Colleen Carleton
 * Created on April 3, 2017, 10:55 AM
 * Purpose:  
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
void upper(char []);
void lower(char []);
void reverse(char []);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Create array to store string
    const int SIZE=101; //Size of array
    char manip[SIZE]; //Array to store string
    
    //Get user input (string)
    cout<<"Enter a string of up to 100 characters, and the program will convert";
    cout<<"the string to all capitals, all lowercase, and reversed."<<endl;
    cin.getline(manip, SIZE);
    
    //Send manip to function reverse
    reverse(manip);
    cout<<"Here is the string, with all uppercase and lowercase letters reversed:"<<endl;
    cout<<manip<<endl;
    
    //Send manip to function lower
    lower(manip);
    cout<<"Here is the string, converted to all lowercase letters: "<<endl;
    cout<<manip<<endl;
    
    //Send manip to function upper
    upper(manip);
    cout<<"Here is the string, converted to all capital letters: "<<endl;
    cout<<manip<<endl;
    
    //Exit
    return 0;
}

void upper(char manip[]) {
    for (int count=0; count<101; count++) {
        manip[count]=toupper(manip[count]);
    }
}

void lower(char manip[]) {
    for (int count=0; count<101; count++) {
        manip[count]=tolower(manip[count]);
    }
}

void reverse(char manip[]) {
    for (int count=0; count<101; count++) {
        if (isupper(manip[count])) {
            manip[count]=tolower(manip[count]);
        } else {
            manip[count]=toupper(manip[count]);
        }
    }
}