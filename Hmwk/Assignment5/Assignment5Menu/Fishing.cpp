/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Fishing.h"

Fishing::Fishing() {
	//random number seed
        srand(static_cast<unsigned int>(time(0)));
    
	total=0;
}

int Fishing::diceroll() {
	int die;
	die=rand()%6+1;
	return die;
}

void Fishing::points() {
	int score;
	score=Fishing::diceroll();
	if (score==1) {
		cout<<"You caught a big fish! You earned 7 points."<<endl;
		total+=7;
	} else if (score==2) {
		cout<<"You caught a shoe! You earned 1 point."<<endl;
		total+=1;
	} else if (score==3) {
		cout<<"You caught a medium fish! You earned 5 points."<<endl;
		total+=5;
	} else if (score==4) {
		cout<<"You caught a small fish! You earned 3 points."<<endl;
		total+=3;
	} else if (score==5) {
		cout<<"You caught a huge fish! You earned 10 points."<<endl;
		total+=10;
	} else  if (score==6) {
		cout<<"You caught seaweed! You earned 15 points."<<endl;
		total+=15;
	}
}

void Fishing::getTotl() {
	cout<<"You earned a total of "<<total<<" points!"<<endl;
	if (total<100) {
		cout<<"There are plenty more fish in the sea!"<<endl;
	} else if (total<250) {
		cout<<"That was quite a catch!"<<endl;
	} else if (total<500) {
		cout<<"That's a lot of fish!"<<endl;
	} else if (total<750) {
		cout<<"You are a pro fisherman!"<<endl;
	} else {
            cout<<"I'm amazed you kept playing this long."<<endl;
        }

}
