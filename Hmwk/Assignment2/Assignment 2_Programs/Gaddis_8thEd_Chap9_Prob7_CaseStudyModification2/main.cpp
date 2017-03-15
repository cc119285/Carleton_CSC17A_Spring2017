/* 
  File:   main.cpp
  Author: Colleen Carleton
  Created on March 10, 2017, 1:15 PM
  Purpose: Second modification of the case study in chapter 9.
 * Sorts donations in descending order rather than ascending order.
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
void arrSrt2(int *, int);
void shwAry2(int *, int);
void shwPtr2(int *, int);

//Executable code begins here!!!
int main(int argc, char** argv) {
    const int NUMDON = 15; //Number of donations

    //An array containing the donation amounts
    int donatns[NUMDON] = {5, 100, 5, 25, 10, 5, 25, 5, 5, 100, 10, 15, 10, 5, 10};

    //Display donations (original order)
    cout<<"The donations, in their original order, are:"<<endl;
    shwAry2(donatns, NUMDON);
    
    //An array of pointers to int
    int *arrPtr[NUMDON] = {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr};

    //Make each element point to an element in the first array
    for (int i=0; i<NUMDON; i++) {
	*(arrPtr+i)=&donatns[i];
    }

    //Call sort function
    arrSrt2(*arrPtr, NUMDON);

    //Display sorted donations (pointer array)
    cout<<"The donations, in sorted order, are: "<<endl;
    shwPtr2(*arrPtr, NUMDON);
    
    //Exit
    return 0;
}

void arrSrt2(int *arrPtr, int NUMDON) {
	int srtStrt, mindex, minElem;

	for (srtStrt=0; srtStrt<NUMDON; srtStrt++) {
		mindex=srtStrt;
		minElem=arrPtr[srtStrt];
		for (int index=srtStrt+1; index<NUMDON; index++) {
			if (*(arrPtr+index) > minElem) {
				minElem=arrPtr[index];
				mindex=index;
			}
		}
		arrPtr[mindex] = arrPtr[srtStrt];
		arrPtr[srtStrt]=minElem;
	}
}

void shwAry2(int donatns[], int NUMDON) {
	for (int count=0; count<NUMDON; count++) {
		cout<<donatns[count]<<" ";
	}
	cout<<endl;
}

void shwPtr2(int *arrPtr, int NUMDON) {
	for (int count=0; count<NUMDON; count++) {
		cout<<*(arrPtr+count)<<" ";
	}
	cout<<endl;
}
