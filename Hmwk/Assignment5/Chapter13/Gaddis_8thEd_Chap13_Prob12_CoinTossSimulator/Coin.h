/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Coin.h
 * Author: rcc
 *
 * Created on May 3, 2017, 11:57 AM
 */

#ifndef COIN_H
#define COIN_H
#include <string> //For string
#include <ctime>  //Time
#include <cstdlib> //Random number seed
using namespace std;

class Coin {
private:
    string sideUp; //Stores "Heads" or "Tails"
public:
    //Constructor
    Coin() {
        //Set random number seed
        srand(static_cast<unsigned int>(time(0)));
        
        //Declare variable
        int randnum;
        
        //Get random number for sideUp
        randnum=rand()%2+1;
        
        if (randnum==1) {
            sideUp="Heads";
        } else {
            sideUp="Tails";
        }
    }
    //Member functions
    void toss();
    string getSide();
};

#endif /* COIN_H */

