/* 
 * File:   main.cpp
 * Author: Colleen Carleton
 * Created on March 27, 2017, 11:16 AM
 * Purpose:  Program that stores customer information for 10 customers and 
 * allows the user to enter, change, and output information
 */

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here

#include "Customeraccounts.h"

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
void actChng(Account [], int);
void actDisp(Account [], int);

//Program Execution Begins Here
int main(int argc, char** argv) {
     //Create an array of 10 structures
    const int CUSTMRS=10;     //Number of speakers (10)
    Account actAry[CUSTMRS];  //Array of speakers
    
    //Declare all Variables Here
    char choice; //Stores user's choice in the menu
    int count=0; //Counter variable
    int cont=0;    //If user wants to continue
    
    //Have user fill the array
    cout<<"This program will allow you to enter information for ten customers."<<endl;
    cout<<"You can then change or display the information."<<endl;
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
    
    //Exit
    return 0;
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
        cout<<"Enter the new last date of payment."<<endl;
        getline(cin, actAry[elem].lastpay); cin.ignore();
}