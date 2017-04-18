/* 
  File:   main.cpp
  Author: Colleen Carleton
  Created on March 26, 2017, 4:40 PM
  Purpose: Program that stores a list of soccer players' names, numbers, and
 * points scored and calculates information based off user-entered information
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries
#include "Soccer.h" 

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from system of units to 
//another

//Function Prototypes


//Executable code begins here!!!
int main(int argc, char** argv) {
    //Declare and initialize variables
    int total=0; //Total points scored by team
    int mostpts=0; //Stores highest points scored

    //Create array
    const int SIZE=12; //Size of array
    Soccer socrAry[SIZE]; //Array of 12 players

    //Fill array
    for (int count=0; count<SIZE; count++) {
            cout<<"Enter Player "<<count+1<<"'s name:"<<endl;
            cin>>socrAry[count].plyrNam;
            cout<<"Enter their number:"<<endl;
            cin>>socrAry[count].plyrNum;
            while (socrAry[count].plyrNum<0) {
                cout<<"Number cannot be negative"<<endl;
                cin>>socrAry[count].plyrNum;
            }
            cout<<"Enter the number of points scored:"<<endl;
            cin>>socrAry[count].ptsScrd;
            while (socrAry[count].ptsScrd<0) {
                cout<<"Points scored cannot be negative"<<endl;
                cin>>socrAry[count].ptsScrd;
            }
    }

    //Display table of info
    cout<<setw(20)<<"Name"<<setw(10)<<"Number"<<setw(10)<<"Points Scored"<<endl;
    for (int count=0; count<SIZE; count++) {
            cout<<setw(20)<<socrAry[count].plyrNam<<setw(10)<<socrAry[count].plyrNum<<setw(10)<<socrAry[count].ptsScrd<<endl;
    }

    //Calculate total points
    for (int i=0; i<SIZE; i++) {
            total+=socrAry[i].ptsScrd;
    }

    //Display total
    cout<<"Total points scored by the entire team: "<<total<<endl;

    //display name and number of the player who earned the most points
    for (int count=0; count<SIZE-1; count++) {
            if (socrAry[mostpts].ptsScrd<socrAry[count+1].ptsScrd) {
                    mostpts=count+1;
            }
    }
    cout<<"The player who scored the most points was "<<socrAry[mostpts].plyrNam<<", #"<<socrAry[mostpts].plyrNum;

    //Exit
    return 0;
}

