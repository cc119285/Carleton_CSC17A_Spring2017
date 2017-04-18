/* 
 * File:   main.cpp
 * Author: Colleen Carleton
 * Created on April 5, 2017, 11:40 AM
 * Purpose:  Program that will display a joke and its punch line in separate
 * functions. The punch line file will include garbage which will not be 
 * displayed
 */

//System Libraries Here
#include <iostream>
#include <fstream>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
void jokeShw(fstream &);
void punShw(fstream &);

//Program Execution Begins Here
int main(int argc, char** argv) {
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

    //Exit
    return 0;
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