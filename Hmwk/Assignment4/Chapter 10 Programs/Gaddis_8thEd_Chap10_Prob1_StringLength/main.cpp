/* 
 * File:   main.cpp
 * Author: Colleen Carleton
 * Created on April 3, 2017, 10:25 AM
 * Purpose:  Program that will find the length of a string entered by the user
 */

//System Libraries Here
#include <iostream>
#include <string>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
int getLen(char []);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    int length=0; //Stores length of string

    //Create array
    const int SIZE=51; //Size of array
    char striLen[SIZE]; //Array to store characters of string

    //Get string from user
    cout<<"Enter a string of up to 50 characters, and the program will output its length."<<endl;
    cin.getline(striLen, SIZE);

    //Call function to get length
    length=getLen(striLen);

    //Output length of string
    cout<<"The string you entered is "<<length<<" characters long."<<endl;

    //Exit
    return 0;
}

int getLen(char striLen[]) {
	// Declare variables
	int leng=0;

	//Get length
	for (int count=0; count<51; count++) {
		if (striLen[count]!='\0') {
			leng++; //increment length
		}
		if (striLen[count]=='\0') {
			return leng;
		}
	}
}