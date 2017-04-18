/* 
 * File:   main.cpp
 * Author: Colleen Carleton
 * Created on April 3, 2017, 10:45 AM
 * Purpose:  Program that counts the number of consonants, vowels, or both, in
 * strings entered by the user
 */

//System Libraries Here
#include <iostream>
#include <string>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
int numV(char []);
int numC(char []);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    int vowels=0; //Stores number of vowels
    int cnsnnts=0; //Stores number of consonants
    char choice=0; //User's menu choice

    //Create array for strings
    const int SIZE=101; //Size of array
    char vowlCon[SIZE]; //Array

    //Get user's string
    cout<<"Enter a string of up to 100 characters."<<endl;
    cin.getline(vowlCon, SIZE); 

    //Loop for choices/Menu
    do {
        //Menu for choice
        cout<<"Pick an option from the menu:"<<endl;
        cout<<"A) Count the number of vowels in the string"<<endl;
        cout<<"B) Count the number of consonants in the string"<<endl;
        cout<<"C) Count both vowels and consonants in the string"<<endl;
        cout<<"D) Enter another string"<<endl;
        cout<<"E) Exit the program"<<endl;
        cin>>choice;

        if (choice=='A' || choice=='a') {
                vowels=numV(vowlCon);
                cout<<"The number of vowels in the string is: "<<vowels<<endl;
        } else if (choice=='B' || choice=='b') {
                cnsnnts=numC(vowlCon);
                cout<<"The number of consonants in the string is: "<<cnsnnts<<endl;
        } else if (choice=='C'|| choice=='c') {
                vowels=numV(vowlCon);
                cout<<"The number of vowels in the string is: "<<vowels<<endl;
                cnsnnts=numC(vowlCon);
                cout<<"The number of consonants in the string is: "<<cnsnnts<<endl;
        } else if (choice=='D' || choice=='d') {
                cin.ignore();
                cout<<"Enter the new string."<<endl;
                cin.getline(vowlCon, SIZE);
        } else if (choice=='E' || choice=='e') {
                cout<<"Exiting the program"<<endl;
        } else {
                cout<<"Invalid option"<<endl;
        }
    } while (choice!='E' && choice!='e');

    //Exit
    return 0;
}

int numV(char vowlCon[]) {
	//Declare variables
	int vowel=0; //Stores number of vowels

	//Find number of vowels
	for (int count=0; count<101; count++) {
		if (vowlCon[count]!='\0') {
			if (tolower(vowlCon[count])=='a' || tolower(vowlCon[count])=='e' || tolower(vowlCon[count])=='i' || tolower(vowlCon[count])=='o' || tolower(vowlCon[count])=='u') {
				vowel++;
			}
		} else {
			//Return vowel count
			return vowel;
	}
    }
}

int numC(char vowlCon[]) {
	//Declare Variables
	int cons=0; //Stores number of consonants

	//Find number of consonants
	for (int count=0; count<101; count++) {
		if (vowlCon[count]!='\0') {
			if (tolower(vowlCon[count])!='a' && tolower(vowlCon[count])!='e' && tolower(vowlCon[count])!='i' && tolower(vowlCon[count])!='o' && tolower(vowlCon[count])!='u') {
				cons++;
			}
		} else {
			//Return consonant count
			return cons;
	}
    }
}
