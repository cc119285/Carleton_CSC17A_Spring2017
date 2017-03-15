/* 
 * File:   main.cpp
 * Author: Colleen Carleton
 * Created on March 13, 2017, 11:30 AM
 * Purpose:  Class assignment -> Mean Median Mode
Input an array, return the mean,median,and mode array.  Array -> number of modes, frequency of modes, then modes.
 */

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
void sortMMM(int *, int);
float averg(int *, int);
float medin(int *, int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    int size=0;
    float avrg=0;
    float median=0;
    int mode=0;
    
    //Get size of array
    cout<<"Enter the number of values to be entered."<<endl;
    cin>>size;
    while (size<0) {
	cout<<"Number of values cannot be negative."<<endl;
	cin>>size;
    }
    
    //Create array
    int *aryMMM=nullptr;
    aryMMM= new int[size];

    //Fill array
    for (int count=0; count<size; count++) {
	cout<<"Enter the number for value "<<count+1<<endl;
	cin>>*(aryMMM+count);
	while (*(aryMMM+count)<0) {
		cout<<"Number cannot be negative."<<endl;
		cin>>*(aryMMM+count);
	}
    }
    
    //Call function to calculate average
    avrg=averg(aryMMM, size);
    cout<<"The average value was "<<avrg<<endl;
    
    //Call function to calculate median
    median=medin(aryMMM, size);
    cout<<"The median value was "<<median<<endl;
    
    //Calculate and Output Mode
    int freq=0;
    int mode1=0;
    int *modeptr=nullptr;
    modeptr= new int[size];
    for (int i=0; i<size; i++) {
	if (aryMMM[i]==aryMMM[i+1]) {
		freq++;
	} else {
		*(modeptr+i)=freq;
		if (freq>mode1) { mode1=freq; }
		freq=0;
	}
    }
    //Search modeptr for the highest frequency (mode1) and output mode(s)
    cout<<"The mode appeared "<<mode1+1<<" times, and was: ";
    for (int count=0; count<size; count++) {
        if (*(modeptr+count)==mode1) {
            cout<<aryMMM[count]<<" ";
        }
    }
    cout<<endl;
    
    //Delete dynamic memory
    delete [] aryMMM;
    aryMMM=nullptr;
    delete [] modeptr;
    modeptr=nullptr;

    //Exit
    return 0;
}

float medin(int *aryMMM, int size) {
    //Variable
    float medi=0;
    
    //Find midpoint
    if (size%2==1) {
	//Odd
	medi=aryMMM[(size)/2];
    } else if (size%2==0) {
	//Even
	medi=(aryMMM[size/2]+aryMMM[(size/2)-1])/static_cast<float>(2);
    }
    
    //return median
    return medi;
}

float averg(int *aryMMM, int size) {
    //Variables
    float avrg=0;
    float sum=0;
    
    //Get sum and average
    for (int i=0; i<size; i++) {
	sum+=*(aryMMM+i);
    }
    avrg=(sum/static_cast<float>(size));
    
    //Return average
    return avrg;
}

void sortMMM(int *aryMMM, int size) {
    int srtStrt, mindex, minElem;

    for (srtStrt=0; srtStrt<size; srtStrt++) {
	mindex=srtStrt;
	minElem=aryMMM[srtStrt];
            for (int index=srtStrt+1; index<size; index++) {
		if (*(aryMMM+index) < minElem) {
                    minElem=aryMMM[index];
                    mindex=index;
		}
	}
	aryMMM[mindex] = aryMMM[srtStrt];
	aryMMM[srtStrt]=minElem;
    }
}