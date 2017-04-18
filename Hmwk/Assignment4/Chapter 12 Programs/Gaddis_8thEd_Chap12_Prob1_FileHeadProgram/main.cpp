/* 
 * File:   main.cpp
 * Author: Colleen Carleton
 * Created on April 5, 2017, 11:00 AM
 * Purpose:  Program that will output the first 10 lines of a file, or the 
 * entire file if it is less than 10 lines
 */

//System Libraries Here
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
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
    
    //Exit
    return 0;
}

