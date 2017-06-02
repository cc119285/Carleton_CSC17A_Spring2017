/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ParkingMeter.h
 * Author: rcc
 *
 * Created on May 10, 2017, 12:14 PM
 */

#ifndef PARKINGMETER_H
#define PARKINGMETER_H

#include <ctime>
#include <cstdlib>
using namespace std;

class PrkngM {
private:
    int minpaid;
public:
    PrkngM() {
        srand(static_cast<unsigned int>(time(0)));
        minpaid=0;
    }
    void setPaid();
    int getPaid();
};

#endif /* PARKINGMETER_H */

