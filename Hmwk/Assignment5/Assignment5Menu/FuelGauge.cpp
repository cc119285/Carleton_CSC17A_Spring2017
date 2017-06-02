/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "FuelGauge.h"

FuelG::FuelG(int a) {
    fuel=0;
}

void FuelG::incFuel() {
    if (fuel<15) {
        fuel++;
    }
}

int FuelG::getFuel() {
    return fuel;
}

int FuelG::decFuel() {
    if (fuel>0) {
        fuel--;
    }
}