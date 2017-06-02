/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "ParkingMeter.h"
#include "ParkedCar.h"

void PrkngM::setPaid() {
    minpaid=rand()%500+1;
}

int PrkngM::getPaid() {
    return minpaid;
}