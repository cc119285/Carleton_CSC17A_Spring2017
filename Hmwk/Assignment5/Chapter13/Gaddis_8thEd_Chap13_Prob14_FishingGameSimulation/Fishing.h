/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Fishing.h
 * Author: rcc
 *
 * Created on May 8, 2017, 11:21 AM
 */

#ifndef FISHING_H
#define FISHING_H
#include <iostream>
#include <ctime>  //Time
#include <cstdlib> //Random number seed
using namespace std;

class Fishing {
private: 
int total; //Stores total points
public: 
Fishing();
int diceroll();
void points();
void getTotl();
};

#endif /* FISHING_H */

