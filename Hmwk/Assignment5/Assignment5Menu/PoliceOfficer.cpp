/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "PoliceOfficer.h"
#include "ParkedCar.h"
#include "ParkingMeter.h"
#include "ParkingTicket.h"
#include <iostream>
using namespace std;

void Officer::setInfo(string nme, int num) {
    name=nme;
    badge=num;
}

string Officer::getName() {
    return name;
}

int Officer::getBadge() {
    return badge;
}

void Officer::chckCar(ParkedC car, PrkngM meter) {
    if (car.getMinP()>meter.getPaid()) {
        PrkngT ticket;
        ticket.getInfo(car, meter, name, badge);
    } else {
        cout<<"The car has not been parked too long."<<endl;
    }
}