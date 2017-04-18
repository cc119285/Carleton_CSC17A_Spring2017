/* 
 * File:   main.cpp
 * Author: Colleen Carleton
 * Created on April 5, 2017, 12:05 PM
 * Purpose:  Program that encrypts the information in a file and outputs it to 
 * another file.
 */

//System Libraries Here
#include <iostream>
#include <fstream>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    fstream first; //encrypted file
    fstream second; //Decrypted file
    char ch; //Stores each character in original
    
    //Open files
    first.open("encrypted.txt", ios::in); //Opens encrypted file
    second.open("decrypted.txt", ios::out); //Opens decryption file
    
    //Translate
    while (!first.eof()) {
        first.get(ch);
        second.put(ch-static_cast<char>(5));
    }
    
    //Close Files
    first.close();
    second.close();

    //Exit
    return 0;
}

