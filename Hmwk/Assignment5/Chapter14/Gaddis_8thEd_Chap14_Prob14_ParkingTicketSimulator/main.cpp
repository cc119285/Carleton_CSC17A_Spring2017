/* 
 * File:   main.cpp
 * Author: Colleen Carleton
 * Created on May 10, 2017, 12:07 PM
 * Purpose:  
 */

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here
#include "ParkedCar.h"
#include "ParkingMeter.h"
#include "ParkingTicket.h"
#include "PoliceOfficer.h"
//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    int numcrs;
    ParkedC car;
    PrkngM meter;
    Officer officr;
    
    //Info for car
    int make;
    string modl;
    string color;
    string licen;
    int prkd;
    //Info for officer
    string name;
    int badgnum;
    
    //Input or initialize values Here
    cout<<"This program simulates an officer creating parking tickets."<<endl;
    cout<<"How many cars do you want to check?"<<endl;
    cin>>numcrs;
    
    //Process/Calculations Here
    for (int i=1; i<=numcrs; i++) {
        cout<<"Car "<<i<<endl;
        cout<<endl;
        //Get car info
        cout<<"Enter the year make of the car."<<endl;
        cin>>make;
        cin.ignore();
        cout<<"Enter the model of the car."<<endl;
        getline(cin, modl);
        cout<<"Enter the color of the car."<<endl;
        getline(cin, color);
        cout<<"Enter the license number."<<endl;
        getline(cin, licen);
        cout<<"Enter the number of minutes it has been parked for."<<endl;
        cin>>prkd;
        car.setPKDC(make, modl, color, licen, prkd);
        //Get officer info
        cin.ignore();
        cout<<"Enter the name of the police officer."<<endl;
        getline(cin, name);
        cout<<"Enter their badge number."<<endl;
        cin>>badgnum;
        cin.ignore();
        officr.setInfo(name, badgnum);
        
        //Have meter get random number
        meter.setPaid();
        
        //Check car
        officr.chckCar(car, meter);
        
    }
    
    //Output Located Here
    

    //Exit
    return 0;
}

