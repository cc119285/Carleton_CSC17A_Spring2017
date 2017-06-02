/* 
 * File:   main.cpp
 * Author: Colleen Carleton
 * Created on May 8, 2017, 10:07 AM
 * Purpose:  Program demonstrating a car class that brakes and accelerates
 */

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here
#include "Car.h"
//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    int modl;
    string make;

    //Get year model and make
    cout<<"Enter the year model of the car."<<endl;
    cin>>modl;
    cout<<"Enter the make of the car."<<endl;
    cin>>make;

    //Create Car
    Car carA(modl, make);

    //Call accelerate
    for (int i=0; i<5; i++) {
            cout<<"Accelerating..."<<endl;
            carA.accelerate();
            cout<<"Current speed: "<<carA.getSpeed()<<endl;
    }

    //Call brake
    for (int j=0; j<5; j++) {
            cout<<"Braking...."<<endl;
            carA.brake();
            cout<<"Current speed: "<<carA.getSpeed()<<endl;
    }


    //Exit
    return 0;
}

