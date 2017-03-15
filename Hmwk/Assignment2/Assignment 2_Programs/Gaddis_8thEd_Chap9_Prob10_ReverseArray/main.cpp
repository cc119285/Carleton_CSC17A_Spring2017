/* 
 * File:   main.cpp
 * Author: Colleen Carleton
 * Created on March 13, 2017, 10:20 AM
 * Purpose:  Program that reverses the contents of an array
 */

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
int *reverse(int [], int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare and initialize variables
    const int SIZE=10;
    int arry1[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *ptr= nullptr;

    //Print array
    cout<<"These are the values in the array:"<<endl;
    for (int i=0; i<SIZE; i++) {
	cout<<arry1[i]<<" ";
    }
    cout<<endl;

    //Call function to reverse array
    ptr=reverse(arry1, SIZE);

    //Print reversed array
    cout<<"These are the values in the array reversed:"<<endl;
    for (int count=0; count<SIZE; count++) {
	cout<<*(ptr+count)<<" ";
    }
    cout<<endl;

    //Delete dynamic memory
    delete [] ptr;
    ptr=nullptr;

    //Exit
    return 0;
}

int *reverse(int arry1[], int SIZE) {
    //Create new array
    int *array = nullptr;
    array = new int[SIZE];

    //Fill 2nd array
    for (int count=0; count<SIZE; count++) {
	*(array+count)=arry1[(SIZE-1)-count];
    }

    //Return pointer
    return array;
}