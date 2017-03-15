/* 
 * File:   main.cpp
 * Author: Colleen Carleton
 * Created on March 8, 2017, 11:07 AM
 * Purpose:  Program that will dynamically allocate an array to store test 
 * scores, then call functions to sort them in ascending order and average
 * them.
 */

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
void testSrt(int *, int);
float avgTest(int *, int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    int size=0; //Stores number of tests
    int *tests=nullptr; //pointer for array
    float avrage=0; //Stores average 
    
    //Get number of test scores
    cout<<"This program will sort and average test scores.";
    cout<<"Enter the number of tests."<<endl;
    cin>>size;
    
    //Dynamically allocate array
    tests= new int[size];
    
    //Fill array with test scores
    for (int count=0; count<size; count++) {
        cout<<"Enter test score "<<count+1<<endl;
        cin>>tests[count];
        while (tests[count]<0) {
            cout<<"Test score cannot be negative."; //Validate test score
            cin>>tests[count];
        }
    }
    
    //Call function to sort the array
    testSrt(tests, size);
    
    //Find average

    avrage=avgTest(tests, size);
    
    //Display sorted list and average
    //Display list
    cout<<"The test scores sorted are: ";
    for (int count=0; count<size; count++) {
        cout<<tests[count]<<" ";
    }
    cout<<endl;
    //Display average
    cout<<"The average of the test scores was "<<avrage<<endl;
    
    //Delete dynamically allocated array
    delete [] tests;
    tests=nullptr; //Make tests a null pointer again
    
    //Exit
    return 0;
}

void testSrt(int *tests, int size) {
    //Declare and initialize variables
    int index;
    int minElem;
    
    //Sort
    for (int start=0; start<size; start++) {
        index=start;
        minElem=*(tests+start);
        for (int i=start+1; i<size; i++) {
            if (*(tests+i) < minElem) {
                minElem=*(tests+i);
                index=i;
            }
        }
        *(tests+index) = *(tests+start);
        *(tests+start) = minElem;
    }
}

float avgTest(int *tests, int size) {
    //Declare and initialize variables
    int total=0; //Stores total of scores
    float avrg=0; //Stores average
    
    //Get total
    for (int count=0; count<size; count++){
        total+=*(tests+count);
    }
    
    //Average
    avrg=static_cast<float>(total)/size;
    
    //Return average
    return avrg;
}