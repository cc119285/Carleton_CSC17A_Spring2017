/* 
 * File:   main.cpp
 * Author: Colleen Carleton
 * Created on March 13, 2016, 11:07 AM
 * Purpose:  Program that calculates the average, median, and mode of the data
 * gathered from a survey of how many movies students see per month.
 */

//System Libraries Here
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
void sort(int *, int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare and initialize variables
    int size=0;
    int sum=0;
    float avrg=0;
    float median=0;
    int mode=0;

    //Get size for array
    cout<<"Enter the number of students surveyed."<<endl;
    cin>>size;
    while (size<0) {
	cout<<"Number of students cannot be negative."<<endl;
	cin>>size;
    }

    //Create array
    int *moviAry=nullptr;
    moviAry= new int[size];

    //Fill array
    for (int count=0; count<size; count++) {
	cout<<"Enter the number of movies student "<<count+1<<" saw in one month."<<endl;
	cin>>*(moviAry+count);
	while (*(moviAry+count)<0) {
		cout<<"Number of movies cannot be negative."<<endl;
		cin>>*(moviAry+count);
	}
    }

    //Calculate and Output Average
    for (int i=0; i<size; i++) {
	sum+=*(moviAry+i);
    }
    avrg=(sum/static_cast<float>(size));
    cout<<setprecision(2)<<fixed<<showpoint;
    cout<<"The average number of movies seen per month is: "<<avrg<<endl;

    //Calculate and Output Median
    //Sort array
    sort(moviAry, size);
    //Find midpoint
    if (size%2==1) {
	//Odd
	median=moviAry[(size)/2];
    } else if (size%2==0) {
	//Even
	median=(moviAry[size/2]+moviAry[(size/2)-1])/static_cast<float>(2);
    }
    cout<<"The median number of movies seen per month is: "<<median<<endl;

    //Calculate and Output Mode
    int freq=0;
    int mode1=0;
    int *modeptr=nullptr;
    modeptr= new int[size];
    for (int i=0; i<size; i++) {
	if (moviAry[i]==moviAry[i+1]) {
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
            cout<<moviAry[count]<<" ";
        }
    }
    cout<<endl;

    //Delete dynamic memory
    delete [] moviAry;
    moviAry=nullptr;
    delete [] modeptr;
    modeptr=nullptr;

    //Exit
    return 0;
}

void sort(int *moviAry, int size) {
    int srtStrt, mindex, minElem;

    for (srtStrt=0; srtStrt<size; srtStrt++) {
	mindex=srtStrt;
	minElem=moviAry[srtStrt];
            for (int index=srtStrt+1; index<size; index++) {
		if (*(moviAry+index) < minElem) {
                    minElem=moviAry[index];
                    mindex=index;
		}
	}
	moviAry[mindex] = moviAry[srtStrt];
	moviAry[srtStrt]=minElem;
    }
}