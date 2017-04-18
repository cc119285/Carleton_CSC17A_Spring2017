/* 
  File:   main.cpp
  Author: Colleen Carleton
  Created on March 26, 2017, 3:30 PM
  Purpose: Program that allows a user to keep track of their budget and how much
 * over/under their planned budget they went
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

#include "Monthlybudget.h"

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from system of units to 
//another

//Function Prototypes
void getInfo(Budget [], int);
void display(Budget [], int);

//Executable code begins here!!!
int main(int argc, char** argv) {
    //Create array
    const int SIZE=2; //Stores size of array
    Budget bdgtAry[SIZE]; //Array: element 1 = planned budget, element 2 = actual budget

//Fill element 1 with planned budget info
bdgtAry[0].housing=500.00;
bdgtAry[0].utility=150.00;
bdgtAry[0].housExp=65.00;
bdgtAry[0].trnsprt=50.00;
bdgtAry[0].food=250.00;
bdgtAry[0].medical=30.00;
bdgtAry[0].insrnce=100.00;
bdgtAry[0].entertn=150.00;
bdgtAry[0].clothng=75.00;
bdgtAry[0].misc=50.00;

//Have user fill element 2
getInfo(bdgtAry, SIZE);

//Call function display to calculate and display over/under budget values
display(bdgtAry, SIZE);

    
    //Exit
    return 0;
}

void display(Budget bdgtAry[], int SIZE) {
	//Variable
	float total=0;

	//Display difference in each category
	cout<<"The difference between the planned budget and the actual budget for each category";
        cout<<"(positive numbers over, negative numbers under budget):"<<endl;
	cout<<"Housing: $"<<(bdgtAry[0].housing-bdgtAry[1].housing)<<endl;
	cout<<"Utilities: $"<<(bdgtAry[0].utility-bdgtAry[1].utility)<<endl;
	cout<<"Housing Expenses: $"<<(bdgtAry[0].housExp-bdgtAry[1].housExp)<<endl;
	cout<<"Transport: $"<<(bdgtAry[0].trnsprt-bdgtAry[1].trnsprt)<<endl;
	cout<<"Food: $"<<(bdgtAry[0].food-bdgtAry[1].food)<<endl;
	cout<<"Medical: $"<<(bdgtAry[0].medical-bdgtAry[1].medical)<<endl;
	cout<<"Insurance: $"<<(bdgtAry[0].insrnce-bdgtAry[1].insrnce)<<endl;
	cout<<"Entertainment: $"<<(bdgtAry[0].entertn-bdgtAry[1].entertn)<<endl;
	cout<<"Clothing: $"<<(bdgtAry[0].clothng-bdgtAry[1].clothng)<<endl;
	cout<<"Miscellaneous: $"<<(bdgtAry[0].misc-bdgtAry[1].misc)<<endl;

	//Calculate overall difference
	total+=bdgtAry[0].housing-bdgtAry[1].housing;
	total+=bdgtAry[0].utility-bdgtAry[1].utility;
	total+=bdgtAry[0].housExp-bdgtAry[1].housExp;
	total+=bdgtAry[0].trnsprt-bdgtAry[1].trnsprt;
	total+=bdgtAry[0].food-bdgtAry[1].food;
	total+=bdgtAry[0].medical-bdgtAry[1].medical;
	total+=bdgtAry[0].insrnce-bdgtAry[1].insrnce;
	total+=bdgtAry[0].entertn-bdgtAry[1].entertn;
	total+=bdgtAry[0].clothng-bdgtAry[1].clothng;
	total+=bdgtAry[0].misc-bdgtAry[1].misc;

	//Display overall difference
	cout<<setprecision(2)<<fixed<<showpoint<<endl;
        if (total>=0) {
	cout<<"The amount under for the entire month was: $"<<total<<endl;
        } else {
        cout<<"The amount over for the entire month was: $"<<(total/-1)<<endl;
        }
}

void getInfo(Budget bdgtAry[], int SIZE) {
	cout<<"Enter the amount, in dollars, spent in each of the following categories."<<endl;
	cout<<"Housing:"<<endl;
	cin>>bdgtAry[1].housing;
	cout<<"Utilities:"<<endl;
	cin>>bdgtAry[1].utility;
	cout<<"Housing Expenses:"<<endl;
	cin>>bdgtAry[1].housExp;
	cout<<"Transport:"<<endl;
	cin>>bdgtAry[1].trnsprt;
	cout<<"Food:"<<endl;
	cin>>bdgtAry[1].food;
	cout<<"Medical:"<<endl;
	cin>>bdgtAry[1].medical;
	cout<<"Insurance:"<<endl;
	cin>>bdgtAry[1].insrnce;
	cout<<"Entertainment:"<<endl;
	cin>>bdgtAry[1].entertn;
	cout<<"Clothing:"<<endl;
	cin>>bdgtAry[1].clothng;
	cout<<"Miscellaneous:"<<endl;
	cin>>bdgtAry[1].misc;
}