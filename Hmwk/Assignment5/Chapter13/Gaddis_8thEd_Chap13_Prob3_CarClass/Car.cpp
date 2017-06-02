/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Car.h"

Car::Car (int modlyr, string mke) {
    yrModel=modlyr;
    make=mke;
    speed=0;
}

void Car::accelerate() {
    speed+=5;
}

void Car::brake() {
    speed-=5;
}

int Car::getModel() {
    return yrModel;
}

string Car::getMake() {
    return make;
}

int Car::getSpeed() {
    return speed;
}