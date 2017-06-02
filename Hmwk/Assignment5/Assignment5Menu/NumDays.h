/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NumDays.h
 * Author: Professor
 *
 * Created on May 10, 2017, 6:14 PM
 */

#ifndef NUMDAYS_H
#define NUMDAYS_H

class NumDays {
private:
    int hours;
    float days;
public:
    NumDays() {
        hours=0;
        days=0;
    }
    NumDays(int numh) {
        hours=numh;
    }
    NumDays(int numh, int numd) {
        hours=numh;
        days=numd;
    }
    void setDays(int, float);
    int getHour();
    int getDays();
    void simpl(); //simplifies hours/days
    //Operator overloading
    NumDays operator + (const NumDays &); //Overloaded +
    NumDays operator - (const NumDays &); //Overloaded -
    NumDays operator ++ (); //Prefix ++
    NumDays operator ++ (int); //Postfix ++
    NumDays operator -- (); //Prefix --
    NumDays operator -- (int); //Postfix --
};

#endif /* NUMDAYS_H */

