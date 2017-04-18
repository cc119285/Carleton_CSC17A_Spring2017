/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Monthlybudget.h
 * Author: Professor
 *
 * Created on March 29, 2017, 4:38 PM
 */

#ifndef MONTHLYBUDGET_H
#define MONTHLYBUDGET_H

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

#endif /* MONTHLYBUDGET_H */

