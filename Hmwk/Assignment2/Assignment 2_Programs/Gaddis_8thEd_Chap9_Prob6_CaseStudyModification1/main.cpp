/* 
  File:   main.cpp
  Author: Colleen Carleton
  Created on March 10, 2017, 1:00 PM
  Purpose: Program that modifies the case study presented in chapter 9.
 * Uses a dynamically allocated array to store the donations, which will be 
 * entered by the user.
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from system of units to 
//another

//Function Prototypes
void arrSort(int *, int);
void showAry(int *, int);
void showPtr(int *, int);

//Executable code begins here!!!
int main(int argc, char** argv) {
    //Declare Variables, pointer
    int numDon=0;
    int *donPtr = nullptr;
    int *arrPtr = nullptr;
    
    //Get number of donations
    cout<<"Enter the number of donations received."<<endl;
    cin>>numDon;
    
    //Create array
    donPtr = new int[numDon];

    //Fill Array
    for (int count=0; count<numDon; count++) {
	cout<<"Enter the donation amount for donation "<<count+1<<endl;
	cin>>donPtr[count];
    }

    //An array of pointers to int
    arrPtr = new int[numDon];

    //Make each element point to an element in the first array
    for (int i=0; i<numDon; i++) {
	arrPtr[i]=donPtr[i];
    }
    
    //Call sort function
    arrSort(arrPtr, numDon);
    
    //Display sorted donations (pointer array)
    cout<<"The donations, in sorted order, are: "<<endl;
    showPtr(arrPtr, numDon);
    
    //Display donations (original order)
    cout<<"The donations, in their original order, are:"<<endl;
    showAry(donPtr, numDon);
    
    //Delete dynamically allocated arrays
    delete [] donPtr;
    donPtr=nullptr;
    delete [] arrPtr;
    arrPtr=nullptr;
    
    //Exit
    return 0;
}

void arrSort(int *arrPtr, int NUMDON) {
	int srtStrt, mindex, minElem;

	for (srtStrt=0; srtStrt<NUMDON; srtStrt++) {
		mindex=srtStrt;
		minElem=arrPtr[srtStrt];
		for (int index=srtStrt+1; index<NUMDON; index++) {
			if (*(arrPtr+index) < minElem) {
				minElem=arrPtr[index];
				mindex=index;
			}
		}
		arrPtr[mindex] = arrPtr[srtStrt];
		arrPtr[srtStrt]=minElem;
	}
}

void showAry(int *arrPtr, int NUMDON) {
	for (int count=0; count<NUMDON; count++) {
		cout<<*(arrPtr+count)<<" ";
	}
	cout<<endl;
}

void showPtr(int *arrPtr, int NUMDON) {
	for (int count=0; count<NUMDON; count++) {
		cout<<*(arrPtr+count)<<" ";
	}
	cout<<endl;
}