/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "NumDays.h"
#include <cstdlib>
using namespace std;

void NumDays::setDays(int h, float d) {
    days=d;
    hours=h;
}

int NumDays::getHour() {
    return hours;
}

int NumDays::getDays() {
    return days;
}

void NumDays::simpl() {
    if (hours>=8) {
        days+=(hours/8);
        hours= hours%8;
    } else if (hours<0){
        days-=((abs(hours)/8)+1);
        hours=8-(abs(hours)%8);
    }
}

NumDays NumDays::operator + (const NumDays &right) {
    NumDays temp;
    temp.hours=hours+right.hours;
    temp.simpl();
    return temp;
}

NumDays NumDays::operator - (const NumDays &right) {
    NumDays temp;
    temp.hours=hours-right.hours;
    temp.simpl();
    return temp;
}

NumDays NumDays::operator ++ () {
    ++hours;
    simpl();
    return *this;
}

NumDays NumDays::operator ++ (int) {
    NumDays temp(hours, days);
    hours++;
    simpl();
    return temp;
}

NumDays NumDays::operator -- () {
    --hours;
    simpl();
    return *this;
}

NumDays NumDays::operator -- (int) {
    NumDays temp(hours, days);
    hours--;
    simpl();
    return temp;
}