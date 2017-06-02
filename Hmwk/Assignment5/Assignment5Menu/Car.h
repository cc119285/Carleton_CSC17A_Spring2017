/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Car.h
 * Author: rcc
 *
 * Created on May 8, 2017, 10:25 AM
 */

#ifndef CAR_H
#define CAR_H

#include <string>
using namespace std;

class Car {
    private:
    int yrModel;
    string make;
    int speed;
    public:
    Car(int, string);
    void accelerate();
    void brake();
    int getModel();
    string getMake();
    int getSpeed();
};

#endif /* CAR_H */

