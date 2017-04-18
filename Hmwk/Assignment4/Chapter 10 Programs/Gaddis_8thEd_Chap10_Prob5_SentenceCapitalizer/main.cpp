/* 
 * File:   main.cpp
 * Author: Colleen Carleton
 * Created on April 3, 2017, 10:35 AM
 * Purpose:  Program that will capitalize the first letter of every sentence in 
 * a string entered by the user
 */

//System Libraries Here
#include <iostream>
#include <string>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
void striCap(char []);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Create Array
    const int SIZE=101; //Size of array
    char sentnce[SIZE]; //Array to store string

    //Get user input
    cout<<"Enter a string of sentences of up to 100 characters, and it will be ";
    cout<<"displayed with the first character of each sentence capitalized."<<endl;
    cin.getline(sentnce, SIZE);

    //Call function
    striCap(sentnce);

    //Output results
    cout<<"Here is the string you entered: "<<endl;
    cout<<sentnce<<endl;

    //Exit
    return 0;
}

void striCap(char sentnce[]) {
	//Change first letter to a capital
	sentnce[0]=toupper(sentnce[0]);

	for (int count=0; count<101; count++) {
		if (sentnce[count]!='\0') {
			if (sentnce[count]=='.') {
				sentnce[count+2]=toupper(sentnce[count+2]);
			}
		}
	}
}
