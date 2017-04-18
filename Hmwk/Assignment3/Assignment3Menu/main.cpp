/* 
  File:   main.cpp
  Author: Colleen Carleton
  Created on March 29, 2017, 4:55 PM
  Purpose:  Menu for Assignment 3 Programs
 */

//System Libraries
#include <iostream>//Input Output Library
#include <iomanip> //Format Library

using namespace std;

//User Libraries
#include "Structures.h"

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from system of units to another

//Function Prototypes
void prob1();
void prob2();
void prob3();
void prob4();
void prob5();
void prob6();
void prob7();
void prob8();

//Program 1
void moviDis(MoviDat);

//Program 2
void movDisp(MoviPro);

//Program 5
void actChng(Account [], int);
void actDisp(Account [], int);

//Program 6
void option1(Speaker [], int);
void option2(Speaker [], int);

//Program 7
void getInfo(Budget [], int);
void display(Budget [], int);


//Executable code begins here!!!
int main(int argc, char** argv) {
    //Declare Variables
    char choice;
    
    //Loop on the menu
    do{
    
        //Input values
        cout<<"Choose from the list"<<endl;
        cout<<"Type 1 for Problem 1 (11.1)"<<endl;
        cout<<"Type 2 for Problem 2 (11.2)"<<endl;
        cout<<"Type 3 for Problem 3 (11.4)"<<endl;
        cout<<"Type 4 for Problem 4 (11.6)"<<endl;
        cout<<"Type 5 for Problem 5 (11.7)"<<endl;
        cout<<"Type 6 for Problem 6 (11.9)"<<endl;
        cout<<"Type 7 for Problem 7 (11.11)"<<endl;
        cout<<"Type 8 for Problem 8 (11.13)"<<endl;
        cin>>choice;

        //Switch to determine the Problem
        switch(choice){
            case '1':{prob1();break;}
            case '2':{prob2();break;}
            case '3':{prob3();break;}
            case '4':{prob4();break;}
            case '5':{prob5();break;}
            case '6':{prob6();break;}
            case '7':{prob7();break;}
            case '8':{prob8();break;}
            default:
                cout<<"You are exiting the program"<<endl;
        }
    }while(choice>='1'&&choice<='8');
    
    //Exit
    return 0;
}

void prob8() {
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
}

void prob7() {
    //Create array
    const int SIZE=2; //Stores size of array
    Budget bdgtAry[SIZE]; //Array: element 1 = planned budget, element 2 = actual budget

    //Fill element 1 with planned budget info
    bdgtAry[0].housing=500.00;
    bdgtAry[0].utility=150.00;
    bdgtAry[0].housExp=65.00;
    bdgtAry[0].trnsprt=50.00;
    bdgtAry[0].food=250.00;
    bdgtAry[0].medical=30.00;
    bdgtAry[0].insrnce=100.00;
    bdgtAry[0].entertn=150.00;
    bdgtAry[0].clothng=75.00;
    bdgtAry[0].misc=50.00;

    //Have user fill element 2
    getInfo(bdgtAry, SIZE);

    //Call function display to calculate and display over/under budget values
    display(bdgtAry, SIZE);
}

void display(Budget bdgtAry[], int SIZE) {
	//Variable
	float total=0;

	//Display difference in each category
	cout<<"The difference between the planned budget and the actual budget for each category";
        cout<<"(positive numbers under, negative numbers over budget):"<<endl;
	cout<<"Housing: $"<<(bdgtAry[0].housing-bdgtAry[1].housing)<<endl;
	cout<<"Utilities: $"<<(bdgtAry[0].utility-bdgtAry[1].utility)<<endl;
	cout<<"Housing Expenses: $"<<(bdgtAry[0].housExp-bdgtAry[1].housExp)<<endl;
	cout<<"Transport: $"<<(bdgtAry[0].trnsprt-bdgtAry[1].trnsprt)<<endl;
	cout<<"Food: $"<<(bdgtAry[0].food-bdgtAry[1].food)<<endl;
	cout<<"Medical: $"<<(bdgtAry[0].medical-bdgtAry[1].medical)<<endl;
	cout<<"Insurance: $"<<(bdgtAry[0].insrnce-bdgtAry[1].insrnce)<<endl;
	cout<<"Entertainment: $"<<(bdgtAry[0].entertn-bdgtAry[1].entertn)<<endl;
	cout<<"Clothing: $"<<(bdgtAry[0].clothng-bdgtAry[1].clothng)<<endl;
	cout<<"Miscellaneous: $"<<(bdgtAry[0].misc-bdgtAry[1].misc)<<endl;

	//Calculate overall difference
	total+=bdgtAry[0].housing-bdgtAry[1].housing;
	total+=bdgtAry[0].utility-bdgtAry[1].utility;
	total+=bdgtAry[0].housExp-bdgtAry[1].housExp;
	total+=bdgtAry[0].trnsprt-bdgtAry[1].trnsprt;
	total+=bdgtAry[0].food-bdgtAry[1].food;
	total+=bdgtAry[0].medical-bdgtAry[1].medical;
	total+=bdgtAry[0].insrnce-bdgtAry[1].insrnce;
	total+=bdgtAry[0].entertn-bdgtAry[1].entertn;
	total+=bdgtAry[0].clothng-bdgtAry[1].clothng;
	total+=bdgtAry[0].misc-bdgtAry[1].misc;

	//Display overall difference
	cout<<setprecision(2)<<fixed<<showpoint<<endl;
        if (total>=0) {
	cout<<"The amount under for the entire month was: $"<<total<<endl;
        } else {
        cout<<"The amount over for the entire month was: $"<<(total/-1)<<endl;
        }
}

void getInfo(Budget bdgtAry[], int SIZE) {
	cout<<"Enter the amount, in dollars, spent in each of the following categories."<<endl;
	cout<<"Housing:"<<endl;
	cin>>bdgtAry[1].housing;
	cout<<"Utilities:"<<endl;
	cin>>bdgtAry[1].utility;
	cout<<"Housing Expenses:"<<endl;
	cin>>bdgtAry[1].housExp;
	cout<<"Transport:"<<endl;
	cin>>bdgtAry[1].trnsprt;
	cout<<"Food:"<<endl;
	cin>>bdgtAry[1].food;
	cout<<"Medical:"<<endl;
	cin>>bdgtAry[1].medical;
	cout<<"Insurance:"<<endl;
	cin>>bdgtAry[1].insrnce;
	cout<<"Entertainment:"<<endl;
	cin>>bdgtAry[1].entertn;
	cout<<"Clothing:"<<endl;
	cin>>bdgtAry[1].clothng;
	cout<<"Miscellaneous:"<<endl;
	cin>>bdgtAry[1].misc;
}

void prob6() {
    //Create an array of 10 structures
    const int SPKRS=10;     //Number of speakers (10)
    Speaker spkAry[SPKRS];  //Array of speakers
    
    //Declare all Variables Here
    char choice; //Stores user's choice in the menu
    int count=0; //Counter variable
    int cont=0;    //If user wants to continue
    
    //Have user fill the array
    cout<<"This program will allow you to enter information for ten speakers."<<endl;
    cout<<"You can then change or display the information."<<endl;
    for (count=0; count<SPKRS; count++) {
        //Fill each part of the structure for each element in the array
        //Speaker's name
        cout<<"Enter the name of speaker "<<count+1<<endl; cin.ignore();
        getline(cin, spkAry[count].spName); 
        //Speaker's telephone number
        cout<<"Enter the telephone number of speaker "<<count+1<<endl;
        cin>>spkAry[count].spNum; cin.ignore();
        //Speaker's topic
        cout<<"Enter the topic discussed by speaker "<<count+1<<endl;
        getline(cin, spkAry[count].spTopc);
        //Speaker's fees
        cout<<"Enter the fees charged by speaker "<<count+1<<endl;
        cin>>spkAry[count].spFee;
        while (spkAry[count].spFee<0) {
            cout<<"The fee cannot be a negative number."<<endl; //Input validation
            cin>>spkAry[count].spFee;
        }
        cin.ignore();
    }
    
    //Menu to allow the user to select an option
    cout<<"You may now choose to alter the information about a speaker, or ";
    cout<<"display the current information."<<endl;
    do {
        //Get user's choice (which of 2 options they want to use)
        cout<<"Enter 1 to change information and 2 to display the current ";
        cout<<"information."<<endl;
        cin>>choice;
        
        //Switch to call the function for the selected option
        switch (choice) {
            case '1': option1(spkAry, SPKRS);break; //Calls function to change info
            case '2': option2(spkAry, SPKRS);break; //Calls function to display info
            default: break;
        }
        
        //Ask if user wants to continue
        cout<<"Do you want to continue making changes or displaying information?"<<endl;
        cout<<"Enter 1 to continue, or 0 to stop."<<endl;
        cin>>cont;
   } while (cont!=0);
}

void option2(Speaker spkAry[], int SPKRS) {
    //Displays information
    for (int count=0; count<SPKRS; count++) {
        cout<<"Here is the information for speaker "<<count+1<<endl;
        cout<<"Name: "<<spkAry[count].spName<<endl;
        cout<<"Telephone number: "<<spkAry[count].spNum<<endl;
        cout<<"Topic: "<<spkAry[count].spTopc<<endl;
        cout<<"Fee: "<<spkAry[count].spFee<<endl;
    }
}

void option1(Speaker spkAry[], int SPKRS) {
    //Allows user to change information
    //Variables
    int elem; //Which element will be altered
    
    //Get user's choice
    cout<<"For which speaker would you like to change the information?"<<endl;
    cout<<"Enter a number from 0 to 9."<<endl;
    cin>>elem;
    
    //Have user enter new information
        cin.ignore();
        cout<<"Enter the new name."<<endl;
        getline(cin, spkAry[elem].spName); 
        cout<<"Enter the new telephone number."<<endl;
        cin>>spkAry[elem].spNum; cin.ignore();
        cout<<"Enter the new topic."<<endl;
        getline(cin, spkAry[elem].spTopc);
        cout<<"Enter the new fee."<<endl;
        cin>>spkAry[elem].spFee;
        while (spkAry[elem].spFee<0) {
            cout<<"The fee cannot be a negative number."<<endl; //Input validation
            cin>>spkAry[elem].spFee;
        }
    
}

void prob5() {
    //Create an array of 10 structures
    const int CUSTMRS=10;     //Number of speakers (10)
    Account actAry[CUSTMRS];  //Array of speakers
    
    //Declare all Variables Here
    char choice; //Stores user's choice in the menu
    int count=0; //Counter variable
    int cont=0;    //If user wants to continue
    
    //Have user fill the array
    cout<<"This program will allow you to enter information for ten customers."<<endl;
    cout<<"You can then change or display the information."<<endl; cin.ignore();
    for (count=0; count<CUSTMRS; count++) {
        //Fill each part of the structure for each element in the array
        //Customer's name
        cout<<"Enter the name of customer "<<count+1<<endl;
        getline(cin, actAry[count].name);
        //Customer's Address
        cout<<"Enter the address of customer "<<count+1<<endl;
        getline(cin, actAry[count].address);
        //Customer's City, etc.
        cout<<"Enter the City, State, and ZIP associated with customer "<<count+1<<endl;
        getline(cin, actAry[count].city);
        //Customer's telephone number
        cout<<"Enter the telephone number of customer "<<count+1<<endl;
        getline(cin, actAry[count].number); 
        //Customer's balance
        cout<<"Enter the balance of customer "<<count+1<<endl;
        cin>>actAry[count].balance;
        while (actAry[count].balance<0) {
            cout<<"The balance cannot be a negative number."<<endl; //Input validation
            cin>>actAry[count].balance;
        }
        cin.ignore();
        //Customer's date of last payment
        cout<<"Enter the date of last payment for customer "<<count+1<<endl;
        getline(cin, actAry[count].lastpay);
    }
    
    
     //Menu to allow the user to select an option
    cout<<"You may now choose to alter the information about a customer, or ";
    cout<<"display the current information."<<endl;
    do {
        //Get user's choice (which of 2 options they want to use)
        cout<<"Enter 1 to change information and 2 to display the current ";
        cout<<"information."<<endl;
        cin>>choice;
        
        //Switch to call the function for the selected option
        switch (choice) {
            case '1': actChng(actAry, CUSTMRS);break; //Calls function to change info
            case '2': actDisp(actAry, CUSTMRS);break; //Calls function to display info
            default: break;
        }
        
        //Ask if user wants to continue
        cout<<"Do you want to continue making changes or displaying information?"<<endl;
        cout<<"Enter 1 to continue, or 0 to stop."<<endl;
        cin>>cont;
   } while (cont!=0);
}

void actDisp(Account actAry[], int CUSTMRS) {
    //Displays information
    for (int count=0; count<CUSTMRS; count++) {
        cout<<"Here is the information for customer "<<count+1<<endl;
        cout<<"Name: "<<actAry[count].name<<endl;
        cout<<"Address: "<<actAry[count].address<<endl;
        cout<<"City, State, and ZIP: "<<actAry[count].city<<endl;
        cout<<"Telephone number: "<<actAry[count].number<<endl;
        cout<<"Balance: "<<actAry[count].balance<<endl;
        cout<<"Date of Last Payment: "<<actAry[count].lastpay<<endl;
    }
}

void actChng(Account actAry[], int CUSTMRS) {
    //Allows user to change information
    //Variables
    int elem; //Which element will be altered
    
    //Get user's choice
    cout<<"For which speaker would you like to change the information?"<<endl;
    cout<<"Enter a number from 0 to 9."<<endl;
    cin>>elem;
    
    //Have user enter new information
        cin.ignore();
        cout<<"Enter the new name."<<endl;
        getline(cin, actAry[elem].name); 
        cout<<"Enter the new Address."<<endl;
        getline(cin, actAry[elem].address); 
        cout<<"Enter the new City, State, and ZIP."<<endl;
        getline(cin, actAry[elem].city); 
        cout<<"Enter the new telephone number."<<endl;
        cin>>actAry[elem].number;
        cout<<"Enter the new balance."<<endl;
        cin>>actAry[elem].balance;
        while (actAry[elem].balance<0) {
            cout<<"The fee cannot be a negative number."<<endl; //Input validation
            cin>>actAry[elem].balance;
        }
        cin.ignore();
        cout<<"Enter the new last date of payment."<<endl;
        getline(cin, actAry[elem].lastpay); 
}

void prob4() {
    //Declare and initialize variables
    int total=0; //Total points scored by team
    int mostpts=0; //Stores highest points scored

    //Create array
    const int SIZE=12; //Size of array
    Soccer socrAry[SIZE]; //Array of 12 players

    //Fill array
    for (int count=0; count<SIZE; count++) {
            cout<<"Enter Player "<<count+1<<"'s name:"<<endl;
            cin>>socrAry[count].plyrNam;
            cout<<"Enter their number:"<<endl;
            cin>>socrAry[count].plyrNum;
            while (socrAry[count].plyrNum<0) {
                cout<<"Number cannot be negative"<<endl;
                cin>>socrAry[count].plyrNum;
            }
            cout<<"Enter the number of points scored:"<<endl;
            cin>>socrAry[count].ptsScrd;
            while (socrAry[count].ptsScrd<0) {
                cout<<"Points scored cannot be negative"<<endl;
                cin>>socrAry[count].ptsScrd;
            }
    }

    //Display table of info
    cout<<setw(20)<<"Name"<<setw(10)<<"Number"<<setw(10)<<"Points Scored"<<endl;
    for (int count=0; count<SIZE; count++) {
            cout<<setw(20)<<socrAry[count].plyrNam<<setw(10)<<socrAry[count].plyrNum<<setw(10)<<socrAry[count].ptsScrd<<endl;
    }

    //Calculate total points
    for (int i=0; i<SIZE; i++) {
            total+=socrAry[i].ptsScrd;
    }

    //Display total
    cout<<"Total points scored by the entire team: "<<total<<endl;

    //display name and number of the player who earned the most points
    for (int count=0; count<SIZE-1; count++) {
            if (socrAry[mostpts].ptsScrd<socrAry[count+1].ptsScrd) {
                    mostpts=count+1;
            }
    }
    cout<<"The player who scored the most points was "<<socrAry[mostpts].plyrNam<<", #"<<socrAry[mostpts].plyrNum;

}

void prob3() {
    //Create array of structures
    const int SIZE=12; //Size of array
    Weather yearAry[SIZE]; //Weather for entire year; each element is one month

    //Declare variables
    float total=0; //Stores total temperature for month
    float dayTemp; //Stores daily temperatures
    int high=0; //Stores month in which highest temp occurred
    int low=0; //Stores month in which lowest temp occurred

    //Get information
    for (int count=0; count<SIZE; count++) {
            cout<<"Enter the total rainfall in month "<<count+1<<endl;
            cin>>yearAry[count].totRain;
            cout<<"Enter the highest temperature in month "<<count+1<<endl;
            cin>>yearAry[count].tempHi;
            cout<<"Enter the lowest temperature in month "<<count+1<<endl;
            cin>>yearAry[count].tempLow;
            for (int i=0; i<30; i++) {
                    cout<<"Enter the temperature on day "<<i+1<<endl;
                    cin>>dayTemp;
                    while (dayTemp<-100 || dayTemp>140) {
                            cout<<"Invalid temperature."<<endl;
                            cin>>dayTemp;
                    }
                    total+=dayTemp;
            }
            yearAry[count].avgTemp=total/30;
            total=0;
    }

    //Calculate total rainfall and average monthly rainfall
    for (int i=0; i<SIZE; i++) {
            total+=yearAry[i].totRain;
    }
    cout<<"Average monthly rainfall: "<<total/12<<endl;
    cout<<"Total rainfall for the year: "<<total<<endl;
    total=0;

    //Calculate highest temp for the year
    for (int i=0; i<SIZE-1; i++) {
            if (yearAry[i].tempHi<yearAry[i+1].tempHi) {
                    high=i+1;
            }
    }
    cout<<"The highest temperature was "<<yearAry[high].tempHi<<" and occurred in month "<<high+1<<endl;

    //Calculate lowest temp for the year
    for (int i=0; i<SIZE-1; i++) {
            if (yearAry[i].tempLow>yearAry[i+1].tempLow) {
                    low=i+1;
            }
    }
    cout<<"The lowest temperature was "<<yearAry[low].tempLow<<" and occurred in month "<<low+1<<endl;

    //Calculate average of all monthly average temperatures
    for (int i=0; i<SIZE; i++) {
            total+=yearAry[i].avgTemp;
    }
    cout<<"The average of the average monthly temperatures was "<<total/SIZE<<endl;
}

void prob2() {
    //Declare variables
    MoviPro movie1; //First Movie
    MoviPro movie2; //Second Movie

    //Get information for each movie
    //Movie 1
    cin.ignore();
    cout<<"Enter the name of the first movie."<<endl;
    getline(cin, movie1.title);
    cout<<"Enter the director of movie 1."<<endl;
    getline(cin, movie1.directr);
    cout<<"Enter the year of release for movie 1."<<endl;
    cin>>movie1.yrReles;
    cout<<"Enter the run time of movie 1."<<endl;
    cin>>movie1.rnTime;
    cout<<"Enter the production costs for movie 1."<<endl;
    cin>>movie1.proCost;
    cout<<"Enter the first year revenue for movie 1."<<endl;
    cin>>movie1.revenue;
    cin.ignore();
    //Movie2
    cout<<"Enter the name of the second movie."<<endl;
    getline(cin, movie2.title);
    cout<<"Enter the director of movie 2."<<endl;
    getline(cin, movie2.directr);
    cout<<"Enter the year of release for movie 2."<<endl;
    cin>>movie2.yrReles;
    cout<<"Enter the run time (in minutes) of movie 2."<<endl;
    cin>>movie2.rnTime;
    cout<<"Enter the production costs for movie 2."<<endl;
    cin>>movie2.proCost;
    cout<<"Enter the first year revenue for movie 2."<<endl;
    cin>>movie2.revenue;

    //Call function to display info for movie 1
    movDisp(movie1);

    //Call function  to display info for movie 2
    movDisp(movie2);
}

void movDisp(MoviPro movie) {
    cout<<"Title: "<<movie.title<<endl;
    cout<<"Director: "<<movie.directr<<endl;
    cout<<"Year of release: "<<movie.yrReles<<endl;
    cout<<"Run time: "<<movie.rnTime<<endl;
    if (movie.revenue-movie.proCost>=0) {
            cout<<"First year's profit: $"<<movie.revenue-movie.proCost<<endl;
    } else {
            cout<<"First year's loss: $"<<movie.revenue-movie.proCost<<endl;
    }
}

void prob1() {
    //Declare variables
    MoviDat movie1; //First Movie
    MoviDat movie2; //Second Movie

    //Get information for each movie
    //Movie 1
    cin.ignore();
    cout<<"Enter the name of the first movie."<<endl;
    getline(cin, movie1.title);
    cout<<"Enter the director of movie 1."<<endl;
    getline(cin, movie1.directr);
    cout<<"Enter the year of release for movie 1."<<endl;
    cin>>movie1.yrReles;
    cout<<"Enter the run time of movie 1."<<endl;
    cin>>movie1.rnTime; cin.ignore();
    //Movie2
    cout<<"Enter the name of the second movie."<<endl;
    getline(cin, movie2.title);
    cout<<"Enter the director of movie 2."<<endl;
    getline(cin, movie2.directr);
    cout<<"Enter the year of release for movie 2."<<endl;
    cin>>movie2.yrReles;
    cout<<"Enter the run time (in minutes) of movie 2."<<endl;
    cin>>movie2.rnTime;

    //Call function to display info for movie 1
    moviDis(movie1);

    //Call function  to display info for movie 2
    moviDis(movie2);
}

void moviDis(MoviDat movie) {
cout<<"Title: "<<movie.title<<endl;
cout<<"Director: "<<movie.directr<<endl;
cout<<"Year of release: "<<movie.yrReles<<endl;
cout<<"Run time: "<<movie.rnTime<<endl;
}