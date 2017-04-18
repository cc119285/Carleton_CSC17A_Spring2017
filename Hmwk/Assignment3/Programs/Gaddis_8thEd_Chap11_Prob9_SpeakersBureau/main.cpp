/* 
 * File:   main.cpp
 * Author: Colleen Carleton
 * Created on March 20, 2017, 11:07 AM
 * Purpose:  Program that will allow the user to fill, alter, and display the 
 * values stored in an array of structures relating to speakers. Structure 
 * includes the speaker's name, number, topic, and fee.
 */

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here
#include "Speakers.h"

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
void option1(Speaker [], int);
void option2(Speaker [], int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    
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
        cout<<"Enter the name of speaker "<<count+1<<endl;
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

    //Exit
    return 0;
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