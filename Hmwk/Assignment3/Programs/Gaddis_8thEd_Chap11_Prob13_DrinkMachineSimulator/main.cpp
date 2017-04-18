/* 
  File:   main.cpp
  Author: Colleen Carleton
  Created on March 26, 2017, 3:40 PM
  Purpose: Program that simulates a drink machine. The user may select a drink
 * to purchase, and repeat this as many times as they want.
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

#include "Drinkmachine.h"

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from system of units to 
//another

//Function Prototypes


//Executable code begins here!!!
int main(int argc, char** argv) {
    //Create and initialize variables
    char cont; //Counter for if they want to continue
    int choice; //Stores choice
    int total=0; //Stores total revenue
    int amntIn=0; //Stores amount they enter in the machine

    //Create array
    const int SIZE=5; //Size of array
    Drinks driMach[SIZE]; //Create array
    //Initialize array
    driMach[0].driName="Cola";
    driMach[0].driCost=75;
    driMach[0].driNum=20;
    driMach[1].driName="Root Beer";
    driMach[1].driCost=75;
    driMach[1].driNum=20;
    driMach[2].driName="Lemon-Lime";
    driMach[2].driCost=75;
    driMach[2].driNum=20;
    driMach[3].driName="Grape Soda";
    driMach[3].driCost=80;
    driMach[3].driNum=20;
    driMach[4].driName="Cream Soda";
    driMach[4].driCost=80;
    driMach[4].driNum=20;

//Loop for program
do {
//Display names and cost
cout<<setw(10)<<"Soda name"<<" Cost"<<endl;
for (int count=0; count<SIZE; count++) {
	cout<<setw(10)<<driMach[count].driName<<" "<<driMach[count].driCost<<endl;
}

//Get type of soda they want
cout<<"Select a drink: 1 for Cola, 2 for Root Beer, 3 for Lemon-Lime, 4 for Grape Soda, and 5 for Cream Soda."<<endl;
cin>>choice;
switch (choice) {
	case 1: {
	if (driMach[0].driNum == 0) {
		cout<<"The machine is sold out of this drink."<<endl;
	} else {
		cout<<"Enter the amount of money (in cents) you are entering into the machine."<<endl;
		cin>>amntIn;
		//Input Validation
		while (amntIn<75) {
			cout<<"Amount entered was not enough to pay for the soda. Please enter an amount of at least 75 cents."<<endl;
			cin>>amntIn;
		}
		while (amntIn>100) {
			cout<<"Amount entered cannot be greater than one dollar."<<endl;
			cin>>amntIn;
		}
		cout<<"Your change is "<<(amntIn-75)<<" cents."<<endl; //Display change
		total+=75; //Add 75 cents to revenue
		driMach[0].driNum=(driMach[0].driNum - 1); //Decrement number of soda remaining
	}
	}; break;
	case 2: {
	if (driMach[1].driNum == 0) {
		cout<<"The machine is sold out of this drink."<<endl;
	} else {
		cout<<"Enter the amount of money (in cents) you are entering into the machine."<<endl;
		cin>>amntIn;
		//Input Validation
		while (amntIn<75) {
			cout<<"Amount entered was not enough to pay for the soda. Please enter an amount of at least 75 cents."<<endl;
			cin>>amntIn;
		}
		while (amntIn>100) {
			cout<<"Amount entered cannot be greater than one dollar."<<endl;
			cin>>amntIn;
		}
		cout<<"Your change is "<<(amntIn-75)<<" cents."<<endl; //Display change
		total+=75; //Add 75 cents to revenue
		driMach[1].driNum=(driMach[1].driNum - 1); //Decrement number of soda remaining
	}
	}; break;
	case 3: {
	if (driMach[2].driNum == 0) {
		cout<<"The machine is sold out of this drink."<<endl;
	} else {
		cout<<"Enter the amount of money (in cents) you are entering into the machine."<<endl;
		cin>>amntIn;
		//Input Validation
		while (amntIn<75) {
			cout<<"Amount entered was not enough to pay for the soda. Please enter an amount of at least 75 cents."<<endl;
			cin>>amntIn;
		}
		while (amntIn>100) {
			cout<<"Amount entered cannot be greater than one dollar."<<endl;
			cin>>amntIn;
		}
		cout<<"Your change is "<<(amntIn-75)<<" cents."<<endl; //Display change
		total+=75; //Add 75 cents to revenue
		driMach[2].driNum=(driMach[2].driNum - 1); //Decrement number of soda remaining
	}
	}; break;
	case 4: {
	if (driMach[3].driNum == 0) {
		cout<<"The machine is sold out of this drink."<<endl;
	} else {
		cout<<"Enter the amount of money (in cents) you are entering into the machine."<<endl;
		cin>>amntIn;
		//Input Validation
		while (amntIn<80) {
			cout<<"Amount entered was not enough to pay for the soda. Please enter an amount of at least 80 cents."<<endl;
			cin>>amntIn;
		}
		while (amntIn>100) {
			cout<<"Amount entered cannot be greater than one dollar."<<endl;
			cin>>amntIn;
		}
		cout<<"Your change is "<<(amntIn-80)<<" cents."<<endl; //Display change
		total+=80; //Add 80 cents to revenue
		driMach[3].driNum=(driMach[3].driNum - 1); //Decrement number of soda remaining
	}
	}; break;
	case 5: {
	if (driMach[4].driNum == 0) {
		cout<<"The machine is sold out of this drink."<<endl;
	} else {
		cout<<"Enter the amount of money (in cents) you are entering into the machine."<<endl;
		cin>>amntIn;
		//Input Validation
		while (amntIn<80) {
			cout<<"Amount entered was not enough to pay for the soda. Please enter an amount of at least 80 cents."<<endl;
			cin>>amntIn;
		}
		while (amntIn>100) {
			cout<<"Amount entered cannot be greater than one dollar."<<endl;
			cin>>amntIn;
		}
		cout<<"Your change is "<<(amntIn-80)<<" cents."<<endl; //Display change
		total+=80; //Add 80 cents to revenue
		driMach[4].driNum=(driMach[4].driNum - 1); //Decrement number of soda remaining
	}
	}; break;
	default: cout<<"Invalid input."<<endl; break;
}

//Ask if they want to continue
cout<<"Would you like to purchase another soda? Type 'Y' for yes or 'N' for no."<<endl;
cin>>cont;
} while (cont=='y' || cont=='Y');

//Display total revenue
cout<<"Total revenue was "<<total<<" cents."<<endl;
    
    //Exit
    return 0;
}

