/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TestScores.h
 * Author: rcc
 *
 * Created on May 8, 2017, 11:10 AM
 */

#ifndef TESTSCORES_H
#define TESTSCORES_H

class TestScores {
private:
int tstscr1;
int tstscr2;
int tstscr3;
float avrg;
public:
TestScores();
void setScrs(int, int, int);
int getScr1();
int getScr2();
int getScr3();
float getAvrg();
};


#endif /* TESTSCORES_H */

