/* 
 * File:   main.cpp
 * Author: Colleen Carleton
 * Created on May 8, 2017, 11:07 AM
 * Purpose:  Program that uses a TestScores class to find the averages of 3 
 * tests.
 */

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here
#include "TestScores.h"
//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    int score1, score2, score3;

    //Get scores
    cout<<"Enter the first test score."<<endl;
    cin>>score1;
    while (score1<0 || score1>100) {
            cout<<"Invalid score."<<endl;
            cin>>score1;
    }
    cout<<"Enter the second test score."<<endl;
    cin>>score2;
    while (score2<0 || score2>100) {
            cout<<"Invalid score."<<endl;
            cin>>score2;
    }
    cout<<"Enter the third test score."<<endl;
    cin>>score3;
    while (score3<0 || score3>100) {
            cout<<"Invalid score."<<endl;
            cin>>score3;
    }

    //Create instance of class and enter test scores
    TestScores test;
    test.setScrs(score1, score2, score3);

    //Output average
    cout<<"The average is: "<<test.getAvrg()<<endl;

    //Exit
    return 0;
}

