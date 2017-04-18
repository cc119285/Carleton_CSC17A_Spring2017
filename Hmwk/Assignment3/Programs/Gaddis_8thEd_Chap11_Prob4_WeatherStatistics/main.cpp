/* 
  File:   main.cpp
  Author: Colleen Carleton
  Created on March 26, 2017, 7:40 PM
  Purpose: Calculates average rainfall, temperature, and other information
 * based on information input by the user.
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

#include "Weatherstats.h"

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from system of units to 
//another

//Function Prototypes


//Executable code begins here!!!
int main(int argc, char** argv) {
    //Create array of structures
const int SIZE=12; //Size of array
Weather yearAry[SIZE]; //Weather for entire year; each element is one month

//Declare variables
float total=0; //Stores total temperature for month
float dayTemp; //Stores daily temperatures
int high=0; //Stores month in which highest temp occurred
int low=0; //Stores month in which lowest temp occurred

//Get information
for (int count=0; count<SIZE; count++) {
	cout<<"Enter the total rainfall in month "<<count+1<<endl;
	cin>>yearAry[count].totRain;
	cout<<"Enter the highest temperature in month "<<count+1<<endl;
	cin>>yearAry[count].tempHi;
	cout<<"Enter the lowest temperature in month "<<count+1<<endl;
	cin>>yearAry[count].tempLow;
	for (int i=0; i<30; i++) {
		cout<<"Enter the temperature on day "<<i+1<<endl;
		cin>>dayTemp;
		while (dayTemp<-100 || dayTemp>140) {
			cout<<"Invalid temperature."<<endl;
			cin>>dayTemp;
		}
		total+=dayTemp;
	}
	yearAry[count].avgTemp=total/30;
	total=0;
}

//Calculate total rainfall and average monthly rainfall
for (int i=0; i<SIZE; i++) {
	total+=yearAry[i].totRain;
}
cout<<"Average monthly rainfall: "<<total/12<<endl;
cout<<"Total rainfall for the year: "<<total<<endl;
total=0;

//Calculate highest temp for the year
for (int i=0; i<SIZE-1; i++) {
	if (yearAry[i].tempHi<yearAry[i+1].tempHi) {
		high=i+1;
	}
}
cout<<"The highest temperature was "<<yearAry[high].tempHi<<" and occurred in month "<<high+1<<endl;

//Calculate lowest temp for the year
for (int i=0; i<SIZE-1; i++) {
	if (yearAry[i].tempLow>yearAry[i+1].tempLow) {
		low=i+1;
	}
}
cout<<"The lowest temperature was "<<yearAry[low].tempLow<<" and occurred in month "<<low+1<<endl;

//Calculate average of all monthly average temperatures
for (int i=0; i<SIZE; i++) {
	total+=yearAry[i].avgTemp;
}
cout<<"The average of the average monthly temperatures was "<<total/SIZE<<endl;
    
    //Exit
    return 0;
}

