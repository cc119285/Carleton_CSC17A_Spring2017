/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "ParkingTicket.h"
#include <iostream>
using namespace std;

void PrkngT::getInfo(ParkedC car, PrkngM meter, string name, int badge) {
    cout<<endl;
    cout<<"Parking Ticket"<<endl;
    cout<<"Car: "<<car.getColr()<<" "<<car.getMake()<<" "<<car.getModl()<<endl;
    cout<<"License Plate Number: "<<car.getLicn()<<endl;
    cout<<"Fine: ";
    if (meter.getPaid()-car.getMinP()<=60) {
        cout<<"$25"<<endl;
    } else {
        cout<<"$"<<25+(10*((car.getMinP()-meter.getPaid()-60)/60))<<endl;
    }
    cout<<"Ticket made by Officer "<<name<<", Badge number "<<badge<<endl;
    cout<<endl;
}