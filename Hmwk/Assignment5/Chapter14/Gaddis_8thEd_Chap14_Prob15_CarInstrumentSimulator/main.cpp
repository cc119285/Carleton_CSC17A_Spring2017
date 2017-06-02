/* 
  File:   main.cpp
  Author: Colleen Carleton
  Created on May 8, 2017, 6:05 PM
  Purpose: Program that simulates a car's fuel gauge and odometer using classes.
 * Simulates filling a car up with fuel and then driving until the car runs out
 * of fuel.
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "FuelGauge.h"
#include "Odometer.h"
//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from system of units to 
//another

//Function Prototypes


//Executable code begins here!!!
int main(int argc, char** argv) {
    //Declare Variables
    int test=1;
    FuelG car(test);
    Odometr miles;
    
    //Fill car with gas
    for (int i=1; i<=15; i++) {
        cout<<"Filling car with fuel...."<<endl;
        car.incFuel();
        cout<<"Fuel amount: "<<car.getFuel()<<endl;
    }
    
    //Loop to drive until out of fuel
    for (int count=1; count<=360; count++) {
        cout<<"Driving..."<<endl;
        miles.incMile();
        cout<<" , Current mileage: "<<miles.getMile()<<endl;
    }
    
    //Exit
    return 0;
}

