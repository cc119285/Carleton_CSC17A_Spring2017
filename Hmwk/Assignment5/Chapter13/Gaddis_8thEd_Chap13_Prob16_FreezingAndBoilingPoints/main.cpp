/* 
 * File:   main.cpp
 * Author: Colleen Carleton
 * Created on May 3, 2017, 11:07 AM
 * Purpose:  Program that uses a class to check whether a substance would be
 * freezing or boiling at a temperature input by the user.
 */

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here
#include "TempCheck.h"
//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare variable
    int temp;
    TempChk t;
    
    //Get temperature
    cout<<"Enter a temperature and the program will report whether ";
    cout<<"Ethyl alcohol, Oxygen, and Water are freezing or boiling at ";
    cout<<"that temperature."<<endl;
    cin>>temp;
    //Enter temperature into the class
    t.setTemp(temp);
    
    //Output Located Here
    //Ethyl alcohol
    if (t.isEthlB()) {
        cout<<"At the temperature "<<t.getTemp()<<", Ethyl alcohol is boiling."<<endl;
    } else if (t.isEthlF()) {
        cout<<"At the temperature "<<t.getTemp()<<", Ethyl alcohol is freezing."<<endl;
    }
    //Oxygen
    if (t.isOxyB()) {
        cout<<"At the temperature "<<t.getTemp()<<", Oxygen is boiling."<<endl;
    } else if (t.isOxyF()) {
        cout<<"At the temperature "<<t.getTemp()<<", Oxygen is freezing."<<endl;
    }
    //Water
    if (t.isWatrB()) {
        cout<<"At the temperature "<<t.getTemp()<<", Water is boiling."<<endl;
    } else if (t.isWatrF()) {
        cout<<"At the temperature "<<t.getTemp()<<", Water is freezing."<<endl;
    }
    
    //Exit
    return 0;
}

