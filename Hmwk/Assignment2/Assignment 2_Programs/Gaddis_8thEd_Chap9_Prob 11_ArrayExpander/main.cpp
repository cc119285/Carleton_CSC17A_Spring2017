/* 
 * File:   main.cpp
 * Author: Colleen Carleton
 * Created on March 13, 2017, 10:50 AM
 * Purpose:  Program that creates an array twice the size of an existing array 
 * and fills it with the contents of the first array, with the leftover elements
 * initialized to zero.
 */

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
int *incrAry(int *, int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare and initialize variables
    int *ptr= nullptr;
    const int SIZE=10;
    int ary1[SIZE]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    //Print array
    cout<<"These are the values in the array:"<<endl;
    for (int i=0; i<SIZE; i++) {
	cout<<ary1[i]<<" ";
    }
    cout<<endl;

    //Call function to increase size
    ptr=incrAry(ary1, SIZE);

    //Print increased array
    cout<<"These are the values in the increased array:"<<endl;
    for (int count=0; count<SIZE*2; count++) {
	cout<<*(ptr+count)<<" ";
    }
    cout<<endl;

    //Delete dynamic memory
    delete [] ptr;
    ptr=nullptr;

    //Exit
    return 0;
}

int *incrAry(int *arry1, int SIZE) {
    //Create new array
    int *array = nullptr;
    array = new int[SIZE*2];

    //Fill 2nd array
    for (int count=0; count<SIZE; count++) {
	array[count]=arry1[count];
    }
    for (int i=SIZE; i<(SIZE*2); i++) {
        array[i]=0;
    }

    //Return pointer
    return array;
}