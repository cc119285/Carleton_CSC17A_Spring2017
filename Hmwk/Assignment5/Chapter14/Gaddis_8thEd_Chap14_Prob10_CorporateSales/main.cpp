/* 
 * File:   main.cpp
 * Author: Colleen Carleton
 * Created on May 8, 2017, 11:45 AM
 * Purpose:  Program that stores sales for a company's divisions. It also 
 * determines the total sales for the year.
 */

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here
#include "DivisionSales.h"
//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
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

    //Exit
    return 0;
}

