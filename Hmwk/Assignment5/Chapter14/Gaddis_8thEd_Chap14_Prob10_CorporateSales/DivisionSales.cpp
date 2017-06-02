/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "DivisionSales.h"

void DivSales::setSals(float one, float two, float three, float four) {
    divAry[0]=one;
    divAry[1]=two;
    divAry[2]=three;
    divAry[3]=four;
    
    totSals+=(one+two+three+four);
 //   cout << "DivSales::setSals: totSals=" << totSals << endl;
}

float DivSales::getSals(int choice) const {
    return divAry[choice];
}

float DivSales::getTotl() const {
    return totSals;
}

float DivSales::totSals = 0;