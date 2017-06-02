/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Odometer.h"

int Odometr::getMile() {
    return mileage;
}

void Odometr::incMile() {
    if (mileage<999998) {
        mileage++;
        if (mileage%24==0) {
            chkFuel.decFuel();
        }
        cout<<"Fuel amount: "<<chkFuel.getFuel();
    } else {
        mileage=0;
    }
}