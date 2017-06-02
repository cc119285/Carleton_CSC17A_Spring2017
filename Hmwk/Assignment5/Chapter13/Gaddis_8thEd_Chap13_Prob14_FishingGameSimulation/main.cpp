/* 
 * File:   main.cpp
 * Author: Colleen Carleton
 * Created on May 8, 2017, 11:20 AM
 * Purpose:  Program that simulates a fishing game where the user fishes and 
 * gains points based on the type of fish caught. Uses the fishing class.
 */

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here
#include "Fishing.h"
//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    char choice;
    Fishing fish;

    cout<<"This is the fishing game. You will catch fish and earn points based on the type of fish you catch."<<endl;

    do {
    fish.points();

    cout<<"Would you like to fish again?"<<endl;
    cout<<"Enter y to continue, or n to stop."<<endl;
    cin>>choice;

    } while (choice=='y' || choice=='Y');

    fish.getTotl();

    //Exit
    return 0;
}

