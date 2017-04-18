/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Customeraccounts.h
 * Author: Professor
 *
 * Created on March 29, 2017, 4:18 PM
 */

#ifndef CUSTOMERACCOUNTS_H
#define CUSTOMERACCOUNTS_H

struct Account {
    string name; //Customer name
    string address; //Customer address
    string city; //Customer City, State, and ZIP
    string number; //Customer's telephone number
    int balance; //Customer's account balance
    string lastpay; //Date of last payment
};

#endif /* CUSTOMERACCOUNTS_H */

