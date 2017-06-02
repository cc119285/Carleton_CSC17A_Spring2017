/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Odometer.h
 * Author: Professor
 *
 * Created on May 8, 2017, 6:10 PM
 */

#ifndef ODOMETER_H
#define ODOMETER_H

#include <iostream>
#include "FuelGauge.h"
using namespace std;

class Odometr {
private:
    FuelG chkFuel;
    int mileage;
    int totMile;
public:
    Odometr() {
        mileage=0;
        totMile=0;
    }
    int getMile();
    void incMile();
    
};

#endif /* ODOMETER_H */

