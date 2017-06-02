/* 
  File:   main.cpp
  Author: Colleen Carleton
  Created on May 10, 2017, 5:40 PM
  Purpose: Program that has a class called NumDays. This class stores number of
 * hours worked and converts it to days.
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "NumDays.h"
//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from system of units to 
//another

//Function Prototypes


//Executable code begins here!!!
int main(int argc, char** argv) {
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
    
    //Exit
    return 0;
}

