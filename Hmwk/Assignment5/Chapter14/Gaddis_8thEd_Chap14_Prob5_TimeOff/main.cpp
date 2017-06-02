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
#include "TimeOff.h"
//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from system of units to 
//another

//Function Prototypes


//Executable code begins here!!!
int main(int argc, char** argv) {
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
    
    //Output information
    //cout<<"Here is the information: "<<endl;
    //cout<<"Employee name: "<<employe.getname()<<endl;
    //cout<<"Employee id: "<<employe.getid()<<endl;
    //cout<<"Number of sick days taken: "<<sicktk1<<endl;
    //cout<<"Max number of sick days: "<<maxs1<<endl;
    //cout<<"Number of vacation days taken: "<<vactk1<<endl;
    //cout<<"Max number of vacation days"<<maxv1<<endl;
    //cout<<"Number of days of unpaid leave taken: "<<unptk1<<endl;
    //cout<<"Max number of days of unpaid leave: "<<maxu1<<endl;
    
    //Exit
    return 0;
}

