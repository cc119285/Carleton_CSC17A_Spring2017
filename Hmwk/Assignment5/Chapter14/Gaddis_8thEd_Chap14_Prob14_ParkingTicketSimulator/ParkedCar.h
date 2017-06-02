/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ParkedCar.h
 * Author: rcc
 *
 * Created on May 10, 2017, 12:14 PM
 */

#ifndef PARKEDCAR_H
#define PARKEDCAR_H

#include <string>
using namespace std;

class ParkedC {
private:
    int make; //year make
    string model; //car model
    string color; //color of car
    string licnse; //license number
    int minprkd; //number of minutes parked
public:
    //Constructor
    ParkedC() {
        make=0;
        model="";
        color="";
        licnse="";
        minprkd=0;
    }
    //Member functions
    void setPKDC(int, string, string, string, int);
    int getMake();
    string getModl();
    string getColr();
    string getLicn();
    int getMinP();
};

#endif /* PARKEDCAR_H */

