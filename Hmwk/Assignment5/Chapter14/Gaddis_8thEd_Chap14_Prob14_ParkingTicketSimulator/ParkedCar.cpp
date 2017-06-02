/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "ParkedCar.h"

void ParkedC::setPKDC(int mak, string modl, string colr, string lice, int minpkd) {
    make=mak;
    model=modl;
    color=colr;
    licnse=lice;
    minprkd=minpkd;
}

int ParkedC::getMake() {
    return make;
}

string ParkedC::getModl() {
    return model;
}

string ParkedC::getColr() {
    return color;
}

string ParkedC::getLicn() {
    return licnse;
}

int ParkedC::getMinP() {
    return minprkd;
}