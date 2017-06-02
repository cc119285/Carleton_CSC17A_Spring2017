/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PoliceOfficer.h
 * Author: rcc
 *
 * Created on May 10, 2017, 12:15 PM
 */

#ifndef POLICEOFFICER_H
#define POLICEOFFICER_H

#include <string>
using namespace std;
#include "ParkingTicket.h"
#include "ParkedCar.h"
#include "ParkingMeter.h"

class Officer {
private:
    string name;
    int badge;
public:
    Officer() {
        name="";
        badge=0;
    }
    void setInfo(string, int);
    string getName();
    int getBadge();
    void chckCar(ParkedC, PrkngM);
};

#endif /* POLICEOFFICER_H */

