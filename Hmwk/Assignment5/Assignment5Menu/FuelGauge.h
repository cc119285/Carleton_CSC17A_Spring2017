/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuelGauge.h
 * Author: Professor
 *
 * Created on May 8, 2017, 6:10 PM
 */

#ifndef FUELGAUGE_H
#define FUELGAUGE_H

class FuelG {
private:
    int fuel; // Fuel, in gallons
public:
    //Constructor
    FuelG() {
        fuel=15;
    }
    //Member functions
    FuelG(int);
    void incFuel();
    int getFuel();
    int decFuel();
};

#endif /* FUELGAUGE_H */

