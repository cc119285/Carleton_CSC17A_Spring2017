/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TimeOff.h
 * Author: Professor
 *
 * Created on May 10, 2017, 8:15 PM
 */

#ifndef TIMEOFF_H
#define TIMEOFF_H

#include "NumDays.h"
#include <string>
using namespace std;

class TimeOff {
private:
    NumDays maxSick;
    NumDays sickTkn;
    NumDays maxVaca;
    NumDays vacaTkn;
    NumDays maxUnp;
    NumDays unpTkn;
    string empname;
    int idnum;
public:
    //Constructor
    TimeOff() {
        maxSick=0;
        sickTkn=0;
        maxVaca=0;
        vacaTkn=0;
        maxUnp=0;
        unpTkn=0;
        empname="";
        idnum=0;
    }
    //Member functions
    void setms(NumDays);
    void setst(NumDays);
    void setmv(NumDays);
    void setvt(NumDays);
    void setmu(NumDays);
    void setut(NumDays);
    void setname(string);
    void setid(int);
    NumDays getms();
    NumDays getst();
    NumDays getmv();
    NumDays getvt();
    NumDays getmu();
    NumDays getut();
    string getname();
    int getid();
};

#endif /* TIMEOFF_H */

