/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "TestScores.h"

TestScores::TestScores() {
	tstscr1=0;
	tstscr2=0;
	tstscr3=0;
}

void TestScores::setScrs(int one, int two, int three) {
	tstscr1=one;
	tstscr2=two;
	tstscr3=three;
}

int TestScores::getScr1() {
	return tstscr1;
}

int TestScores::getScr2() {
	return tstscr2;
}

int TestScores::getScr3() {
	return tstscr3;
}

float TestScores::getAvrg() {
	avrg=(tstscr1+tstscr2+tstscr3)/3;
	return avrg;
}
