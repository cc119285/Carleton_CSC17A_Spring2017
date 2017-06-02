/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DivisionSales.h
 * Author: rcc
 *
 * Created on May 8, 2017, 11:49 AM
 */

#ifndef DIVISIONSALES_H
#define DIVISIONSALES_H

class DivSales {
private:
    static float totSals;
    float divAry[4];
public:

    //Constructor
    DivSales() {
        for (int i=0; i<4; i++) {
            divAry[i]=0;
        }
    }
    //Member functions
    void setSals(float, float, float, float);
    float getSals(int) const;
    float getTotl() const;
};

//float DivSales::totSals = 0;

#endif /* DIVISIONSALES_H */

