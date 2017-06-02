/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "TimeOff.h"
#include <iostream>
using namespace std;

void TimeOff::setms(NumDays a) {
    maxSick.setDays(a.getHour(), a.getDays());
}

void TimeOff::setst(NumDays b) {
    sickTkn.setDays(b.getHour(), b.getDays());
}

void TimeOff::setmv(NumDays c) {
    maxVaca.setDays(c.getHour(), c.getDays());
    if (c.getHour()>240) {
        maxVaca.setDays(240, 0);
    }
}

void TimeOff::setvt(NumDays d) {
    vacaTkn.setDays(d.getHour(), d.getDays());
}

void TimeOff::setmu(NumDays e) {
    maxUnp.setDays(e.getHour(), e.getDays());
}

void TimeOff::setut(NumDays f) {
    unpTkn.setDays(f.getHour(), f.getDays());
}

void TimeOff::setname(string nme) {
    empname=nme;
}

void TimeOff::setid(int g) {
    idnum=g;
}

NumDays TimeOff::getms() {
    return maxSick;
}

NumDays TimeOff::getst() {
    return sickTkn;
}

NumDays TimeOff::getmv() {
    return maxVaca;
}

NumDays TimeOff::getvt() {
    return vacaTkn;
}

NumDays TimeOff::getmu() {
    return maxUnp;
}

NumDays TimeOff::getut() {
    return unpTkn;
}

string TimeOff::getname() {
    return empname;
}

int TimeOff::getid() {
    return idnum;
}