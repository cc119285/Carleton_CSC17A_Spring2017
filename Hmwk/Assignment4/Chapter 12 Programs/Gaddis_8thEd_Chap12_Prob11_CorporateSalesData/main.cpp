/* 
  File:   main.cpp
  Author: Colleen Carleton
  Created on April 5, 2017, 5:00 PM
  Purpose: Program that allows a user to enter sales figures for different
 * divisions of a company. This data will then be written to a file.
 */

//System Libraries
#include <iostream>
#include <fstream>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from system of units to 
//another

//Function Prototypes


//Executable code begins here!!!
int main(int argc, char** argv) {
    //Declare Variables
    string line; //Stores information entered by the user
    int quarter; //Stores the quarter
    int sales;   //Stores the sales for a quarter
    fstream input; //File to store data
    
    //Open file
    input.open("salesdata.txt", ios::out);
    
    //Get input for file
    for (int i=1; i<=4; i++) {
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
            cin.ignore();
        }
    }
    
    //Close file
    input.close();
    
    //Exit
    return 0;
}

