/* 
  File:   main.cpp
  Author: Colleen Carleton
  Created on May 10, 2017, 10:00 PM
  Purpose:  Menu for Chapter 13-14 Assignments (Assignment 5)
 */

//System Libraries
#include <iostream>//Input Output Library
using namespace std;

//User Libraries
#include "Car.h"
#include "TestScores.h"
#include "Coin.h"
#include "Fishing.h"
#include "TempCheck.h"
#include "NumDays.h"
#include "TimeOff.h"
#include "DivisionSales.h"
#include "ParkedCar.h"
#include "ParkingMeter.h"
#include "ParkingTicket.h"
#include "PoliceOfficer.h"
#include "FuelGauge.h"
#include "Odometer.h"
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

//Executable code begins here!!!
int main(int argc, char** argv) {
    //Declare Variables
    char choice;
    
    //Loop on the menu
    do{
    
        //Input values
        cout<<"Choose from the list"<<endl;
        cout<<"Type 1 for Problem 1 (13.3)"<<endl;
        cout<<"Type 2 for Problem 2 (13.7)"<<endl;
        cout<<"Type 3 for Problem 3 (13.12)"<<endl;
        cout<<"Type 4 for Problem 4 (13.14)"<<endl;
        cout<<"Type 5 for Problem 5 (13.16)"<<endl;
        cout<<"Type 6 for Problem 6 (14.4)"<<endl;
        cout<<"Type 7 for Problem 7 (14.5)"<<endl;
        cout<<"Type 8 for Problem 8 (14.10)"<<endl;
        cout<<"Type 9 for Problem 9 (14.14)"<<endl;
        cout<<"Type 0 for Problem 10 (14.15)"<<endl;
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
    
    //Exit stage right!
    return 0;
}

void prob1(){
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
}

void prob2(){
    //Declare all Variables Here
    int score1, score2, score3;

    //Get scores
    cout<<"Enter the first test score."<<endl;
    cin>>score1;
    while (score1<0 || score1>100) {
            cout<<"Invalid score."<<endl;
            cin>>score1;
    }
    cout<<"Enter the second test score."<<endl;
    cin>>score2;
    while (score2<0 || score2>100) {
            cout<<"Invalid score."<<endl;
            cin>>score2;
    }
    cout<<"Enter the third test score."<<endl;
    cin>>score3;
    while (score3<0 || score3>100) {
            cout<<"Invalid score."<<endl;
            cin>>score3;
    }

    //Create instance of class and enter test scores
    TestScores test;
    test.setScrs(score1, score2, score3);

    //Output average
    cout<<"The average is: "<<test.getAvrg()<<endl;
}

void prob3(){
    //Declare all Variables Here
    int heads=0;
    int tails=0;
    string result;
    Coin coin;
    
    //Initial coin flip
    cout<<"The side up is: "<<coin.getSide()<<endl;
    
    //Flip coin 20 times
    for (int i=1; i<=20; i++) {
        coin.toss();
        cout<<"The side up is: "<<coin.getSide()<<endl;
        result=coin.getSide();
        if (result=="Heads") {
            heads++;
        } else {
            tails++;
        }
    }
    
    //Display total heads and tails
    cout<<"Total number of heads: "<<heads<<endl;
    cout<<"Total number of tails: "<<tails<<endl;
    
}

void prob4() {
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
}

void prob5() {
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
    
}
void prob6() {
    //Declare Variables
    NumDays num;
    int choice; //number of initial hours
    char a;     //yes/no
    int addsub; //Add or subtract from hours
    NumDays temp;
    
    //Input values
    cout<<"This program will convert hours of work to days."<<endl;
    cout<<"Enter the number of hours worked."<<endl;
    cin>>choice;
    
    //Process Calculations
    num.setDays(choice, 0);
    num.simpl();
    
    //Output
    cout<<"Days: "<<num.getDays()<<endl;
    cout<<"Hours: "<<num.getHour()<<endl;
    
    //Increment/decrement hours?
    cout<<"Do you want to increment the hours? Enter y for yes, or n for no."<<endl;
    cin>>a;
    if (a=='y' || a=='Y') {
        num++;
        cout<<"Days: "<<num.getDays()<<endl;
        cout<<"Hours: "<<num.getHour()<<endl;
    }
    cout<<"Do you want to decrement the hours? Enter y for yes or n for no."<<endl;
    cin>>a;
    if (a=='y' || a=='Y') {
        num--;
        cout<<"Days: "<<num.getDays()<<endl;
        cout<<"Hours: "<<num.getHour()<<endl;
    }
    cout<<"Do you want to add to the hours? Enter y for yes or n for no."<<endl;
    cin>>a;
    if (a=='y' || a=='Y') {
        cout<<"What do you want to add to hours?"<<endl;
        cin>>addsub;
        temp=num.operator +(addsub);
        cout<<"Days: "<<temp.getDays()<<endl;
        cout<<"Hours: "<<temp.getHour()<<endl;
    }
    cout<<"Do you want to add to the hours? Enter y for yes or n for no."<<endl;
    cin>>a;
    if (a=='y' || a=='Y') {
        cout<<"What do you want to subtract from hours?"<<endl;
        cin>>addsub;
        temp=num.operator -(addsub);
        cout<<"Days: "<<temp.getDays()<<endl;
        cout<<"Hours: "<<temp.getHour()<<endl;
    }
}
void prob7() {
    //Declare Variables
    TimeOff employe;
    string name;
    int id;
    int sicktk;
    int vactk;
    int unptk;
    int maxs;
    int maxv;
    int maxu;
    
    //Get maximums
    cout<<"Enter the maximum number of sick days an employee may take."<<endl;
    cin>>maxs;
    cout<<"Enter the maximum number of vacation days an employee may take."<<endl;
    cin>>maxv;
    cout<<"Enter the maximum number of days of unpaid leave an employee may take."<<endl;
    cin>>maxu;
    cin.ignore();
    
    //Get information for employee
    cout<<"Enter the employee's name."<<endl;
    getline(cin, name);
    cout<<"Enter the employee's id number."<<endl;
    cin>>id;
    cout<<"Enter the number of sick days taken by the employee."<<endl;
    cin>>sicktk;
    cout<<"Enter the number of vacation days taken by the employee."<<endl;
    cin>>vactk;
    cout<<"Enter the number of days of unpaid leave taken by the employee."<<endl;
    cin>>unptk;
            
    //Set NumDays variables
    NumDays sickt(sicktk);
    NumDays sickm(maxs);
    NumDays vact(vactk);
    NumDays vacm(maxv);
    NumDays unpdt(unptk);
    NumDays unpdm(maxu);
    
    //Put in TimeOff class
    employe.setms(sickm);
    employe.setmv(vacm);
    employe.setmu(unpdm);
    employe.setst(sickt);
    employe.setvt(vact);
    employe.setut(unpdt);
    employe.setname(name);
    employe.setid(id);
    
    //Get from class
    NumDays sicktk1=employe.getst();
    NumDays vactk1=employe.getvt();
    NumDays unptk1=employe.getut();
    NumDays maxs1=employe.getms();
    NumDays maxv1=employe.getmv();
    NumDays maxu1=employe.getmu();
}

void prob8() {
    //Declare all Variables Here
    DivSales arry[6];
    float quartr1, quartr2, quartr3, quartr4;
    
    //Input or initialize values Here
    cout<<"Enter the quarterly sales for six divisions."<<endl;
    for (int i=0; i<=5; i++) {
        cout<<"For division "<<i+1<<":"<<endl;
        //Quarter 1
        cout<<"Enter the sales for quarter 1."<<endl;
        cin>>quartr1;
        while (quartr1<0) {
            cout<<"Sales cannot be negative."<<endl;
            cin>>quartr1;
        }
        //Quarter 2
        cout<<"Enter the sales for quarter 2."<<endl;
        cin>>quartr2;
        while (quartr2<0) {
            cout<<"Sales cannot be negative."<<endl;
            cin>>quartr2;
        }
        //Quarter 3
        cout<<"Enter the sales for quarter 3."<<endl;
        cin>>quartr3;
        while (quartr3<0) {
            cout<<"Sales cannot be negative."<<endl;
            cin>>quartr3;
        }
        //Quarter 4
    cout<<"Enter the sales for quarter 4."<<endl;
        cin>>quartr4;
        while (quartr4<0) {
            cout<<"Sales cannot be negative."<<endl;
            cin>>quartr4;
        }
        
        //Input to array
        arry[i].setSals(quartr1, quartr2, quartr3, quartr4);
        
    }
    
    //Output sales for each division, plus overall total
    for (int count=0; count<=5; count++) {
        cout<<"Sales for Quarter 1: $"<<arry[count].getSals(0)<<endl;
        cout<<"Sales for Quarter 2: $"<<arry[count].getSals(1)<<endl;
        cout<<"Sales for Quarter 3: $"<<arry[count].getSals(2)<<endl;
        cout<<"Sales for Quarter 4: $"<<arry[count].getSals(3)<<endl;
    }
    cout<<"Total corporate sales for the year: $"<<arry[0].getTotl()<<endl;

}

void prob9() {
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
}

void prob10() {
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
}