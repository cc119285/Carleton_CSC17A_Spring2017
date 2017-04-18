/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Structures.h
 * Author: Professor
 *
 * Created on March 29, 2017, 5:00 PM
 */

#ifndef STRUCTURES_H
#define STRUCTURES_H

struct MoviDat {
    string title; //Movie title
    string directr; //Director
    int yrReles; //Year released
    int rnTime; //Run time (in minutes)
};

struct MoviPro {
    string title; //Movie title
    string directr; //Director
    int yrReles; //Year released
    int rnTime; //Run time (in minutes)
    float proCost; //Production costs
    float revenue; //First year revenue
};

struct Weather {
    int totRain; //Total rainfall in month
    int tempHi; //Highest temperature
    int tempLow; //Lowest temperature
    float avgTemp; //Average temperature
};

struct Soccer {
    string plyrNam; //Stores player's name
    int plyrNum;      //Stores player's number
    int ptsScrd;      //Stores number of points scored by player
};

struct Account {
    string name; //Customer name
    string address; //Customer address
    string city; //Customer City, State, and ZIP
    string number; //Customer's telephone number
    int balance; //Customer's account balance
    string lastpay; //Date of last payment
};

struct Speaker
    {
        string spName; //Stores speaker's name
        int spNum;     //Stores speaker's telephone number
        string spTopc; //Stores the speaker's topic
        float spFee;   //Stores the speaker's fee
    };
    
    struct Budget {
    float housing; //amount of budget allocated for housing costs
    float utility;   //amount of budget allocated for utilities
    float housExp; //amount of budget allocated for household expenses
    float trnsprt;  //amount of budget allocated for transportation
    float food;      //amount of budget allocated for food
    float medical; //amount of budget allocated for medical expenses
    float insrnce; //amount of budget allocated for insurance
    float entertn; //amount of budget allocated for entertainment
    float clothng;  //amount of budget allocated for clothing
    float misc;       //amount of budget allocated for miscellaneous stuff
};

struct Drinks {
    string driName;	//Stores name of drink
    int driCost;	//Stores cost of drink in cents
    int driNum;	//Stores number of drinks remaining
};

#endif /* STRUCTURES_H */

