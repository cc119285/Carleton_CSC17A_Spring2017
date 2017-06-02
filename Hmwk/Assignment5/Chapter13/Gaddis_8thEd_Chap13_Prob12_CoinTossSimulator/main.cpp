/* 
 * File:   main.cpp
 * Author: Colleen Carleton
 * Created on May 3, 2017, 11:55 AM
 * Purpose:  Program that uses a coin class to simulate flipping a coin.
 */

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here
#include "Coin.h"
//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    int heads=0;
    int tails=0;
    string result;
    Coin coin;
    
    //Initial coin flip
    cout<<"The side up is: "<<coin.getSide()<<endl;
    
    //Flip coin 20 times
    for (int i=1; i<=20; i++) {
        coin.toss();
        cout<<"The side up is: "<<coin.getSide()<<endl;
        result=coin.getSide();
        if (result=="Heads") {
            heads++;
        } else {
            tails++;
        }
    }
    
    //Display total heads and tails
    cout<<"Total number of heads: "<<heads<<endl;
    cout<<"Total number of tails: "<<tails<<endl;
    
    //Exit
    return 0;
}

