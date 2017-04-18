/* 
  File:   main.cpp
  Author: Colleen Carleton
  Created on February 10, 2017, 3:10 PM
  Purpose:  Menu for Assignment 4 Programs
 */

//System Libraries
#include <iostream> //Input Output Library
#include <fstream>  //input output to files library
#include <string>   //String library
#include <cstring>  //String library
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from system of units to another

//Function Prototypes
void prob1();
void prob2();
void prob3();
void prob4();
void prob5();
void prob6();
void prob7();
void prob8();
void prob9();
void prob10();

int getLen(char []);    //Program 1
void striCap(char []);  //Program 2
int numV(char []);      //Program 3
int numC(char []);      //Program 
void upper(char []);    //Program 4
void lower(char []);    //Program 4
void reverse(char []);  //Program 4
int leng(char []);      //Program 5
int uppr(char []);     //Program 5
int lowr(char []);     //Program 5
int digit(char []);     //Program 5
void jokeShw(fstream &);//Program 7
void punShw(fstream &); //Program 7

//Executable code begins here!!!
int main(int argc, char** argv) {
    //Declare Variables
    char choice;
    
    //Loop on the menu
    do{
    
        //Input values
        cout<<"Choose from the list"<<endl;
        cout<<"Type 1 for Problem 1"<<endl;
        cout<<"Type 2 for Problem 2"<<endl;
        cout<<"Type 3 for Problem 3"<<endl;
        cout<<"Type 4 for Problem 4"<<endl;
        cout<<"Type 5 for Problem 5"<<endl;
        cout<<"Type 6 for Problem 6"<<endl;
        cout<<"Type 7 for Problem 7"<<endl;
        cout<<"Type 8 for Problem 8"<<endl;
        cout<<"Type 9 for Problem 9"<<endl;
        cout<<"Type 0 for Problem 10"<<endl;
        cin>>choice;

        //Switch to determine the Problem
        switch(choice){
            case '1':{prob1();break;}
            case '2':{prob2();break;}
            case '3':{prob3();break;}
            case '4':{prob4();break;}
            case '5':{prob5();break;}
            case '6':{prob6();break;}
            case '7':{prob7();break;}
            case '8':{prob8();break;}
            case '9':{prob9();break;}
            case '0':{prob10();break;}
            default:
                cout<<"You are exiting the program"<<endl;
        }
    }while(choice>='0'&&choice<='9');
    
    //Exit
    return 0;
}

void prob10() {
    //Declare Variables
    string line; //Stores information entered by the user
    int quarter; //Stores the quarter
    int sales;   //Stores the sales for a quarter
    fstream input; //File to store data
    
    //Open file
    input.open("salesdata.txt", ios::out);
    
    //Get input for file
    for (int i=1; i<=4; i++) {
        cin.ignore();
        cout<<"Enter the name of the division (of North, South, East, and West)."<<endl;
        getline(cin, line); //Name of division
        input<<"Division: "<<line<<" ";
        for (int count=1; count<=4; count++) {
            cout<<"Enter the Quarter (of 1, 2, 3, or 4)."<<endl;
            cin>>quarter; //Quarter
            input<<"Quarter: "<<quarter<<" ";
            cout<<"Enter the sales for this quarter."<<endl;
            cin>>sales; //Sales
            while (sales<0) {
                cout<<"Sales cannot be negative."<<endl; //Input validation
                cin>>sales;
            }
            input<<"Sales: $"<<sales<<" ";
        }
    }
    
    //Close file
    input.close();
}

void prob9() {
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
}

void prob8() {
    //Declare all Variables Here
    fstream first; //Original file
    fstream second; //Second file
    char ch; //Stores each character in original
    
    //Open files
    first.open("original.txt", ios::in); //Opens original file
    second.open("encrypted.txt", ios::out); //Opens encryption file
    
    //Translate
    while (!first.eof()) {
        first.get(ch);
        second.put(ch+static_cast<char>(5));
    }
    
    //Close Files
    first.close();
    second.close();
}

void prob7() {
    //Declare all Variables Here
    fstream joke; //joke file
    fstream pnchln; //punch line file
    
    //Open files for input
    joke.open("joke.txt", ios::in); //Opens joke file
    pnchln.open("punchline.txt", ios::in); //Opens punch line file
    
    //Call function to show joke
    jokeShw(joke);
    
    //Call function to show punch line
    punShw(pnchln);
    
    //Close files
    joke.close();
    pnchln.close();
}

void jokeShw(fstream &joke) {
    //Declare variables
    string line; //Stores lines of file
    
    //Read information
    while (!joke.eof()) {
        getline(joke, line);//Input line
        cout<<line<<endl; //Output line
    }
    
}

void punShw(fstream &pnchln) {
    //Declare variables
    string line; //Stores lines of file
    
    //Read information
    while (!pnchln.eof()) {
        getline(pnchln, line);//Input line
        //Test for end of file
        if (pnchln.eof()) {
            cout<<line<<endl;
        }
    }
}

void prob6() {
    //Declare all Variables Here
    string fileNme; //Stores the file name entered by the user
    string line; //Stores each line of the file
    fstream headFil; //File that will be opened
    int test=0; //If end of file has been reached, this will become 1
    
    //Get string name
    cout<<"Enter the name of a file."<<endl;
    cout<<"Example files are: filehead.txt and filehead2.txt"<<endl;
    cin>>fileNme;
    
    //Open file
    headFil.open(fileNme, ios::in);
    
    //test if file opened successfully
    if (headFil) {
        //If successful, output the lines in the file
        for (int i=1; i<=10; i++) {
            if (test==0 && !headFil.eof()) {
                getline(headFil, line);
                cout<<line<<endl;
            } else {
                if (test==1) {
                
                } else {
                //If end of file has been reached
                cout<<"The entire file has been read."<<endl;
                test=1; //Increment test
                }
            }
        }
    } else {
        //If file did not open successfully
        cout<<"File could not be opened."<<endl;
    }
    
    //Close file
    headFil.close();
}

void prob5() {
    //Declare and initialize variables
    int length=0; //Is he length greater than 6?
    int up=0;  //Is there at least 1 uppercase letter?
    int low=0; //Is there at least 1 lowercase letter?
    int digits=0; //Is there at least 1 digit?
    
    //Create array to store string
    const int SIZE=51; //Size of array
    char passwrd[SIZE]; //Array to hold string
    
    //Get user's input (password)
    cin.ignore();
    cout<<"Enter a password of at least 6 characters, but no more than 50."<<endl;
    cin.getline(passwrd, SIZE);
    
    //Call functions length, upper, lower, and digit to check requirements
    length=leng(passwrd);
    up=uppr(passwrd);
    low=lowr(passwrd);
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
}

int leng(char passwrd[]) {
    //Declare variable
    int len=0;
    
    //Get length
    len=strlen(passwrd);
    
    //Return length
    return len;
}

int uppr(char passwrd[]) {
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

int lowr(char passwrd[]) {
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

void prob4() {
    //Create array to store string
    const int SIZE=101; //Size of array
    char manip[SIZE]; //Array to store string
    
    //Get user input (string)
    cin.ignore();
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

void prob3() {
    //Declare variables
    int vowels=0; //Stores number of vowels
    int cnsnnts=0; //Stores number of consonants
    char choice=0; //User's menu choice

    //Create array for strings
    const int SIZE=101; //Size of array
    char vowlCon[SIZE]; //Array

    //Get user's string
    cin.ignore();
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

void prob2() {
    //Create Array
    const int SIZE=101; //Size of array
    char sentnce[SIZE]; //Array to store string

    //Get user input
    cin.ignore();
    cout<<"Enter a string of sentences of up to 100 characters, and it will be ";
    cout<<"displayed with the first character of each sentence capitalized."<<endl;
    cin.getline(sentnce, SIZE);

    //Call function
    striCap(sentnce);

    //Output results
    cout<<"Here is the string you entered: "<<endl;
    cout<<sentnce<<endl;
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

void prob1() {
    //Declare Variables
    int length=0; //Stores length of string

    //Create array
    const int SIZE=51; //Size of array
    char striLen[SIZE]; //Array to store characters of string

    //Get string from user
    cin.ignore();
    cout<<"Enter a string of up to 50 characters, and the program will output its length."<<endl;
    cin.getline(striLen, SIZE);

    //Call function to get length
    length=getLen(striLen);

    //Output length of string
    cout<<"The string you entered is "<<length<<" characters long."<<endl;
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