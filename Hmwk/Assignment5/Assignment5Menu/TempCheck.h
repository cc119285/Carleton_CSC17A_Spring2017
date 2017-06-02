/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TempCheck.h
 * Author: rcc
 *
 * Created on May 3, 2017, 11:11 AM
 */

#ifndef TEMPCHECK_H
#define TEMPCHECK_H

class TempChk {
    private:
        int temprtr; //Stores temperature
    public:
        void setTemp(int); //Sets temperature
        int getTemp(); //Returns temperature
        bool isEthlF() const; //Checks for Ethyl's freezing point
        bool isEthlB() const; //Checks for Ethyl's boiling point
        bool isOxyF() const;  //Checks for Oxygen's freezing point
        bool isOxyB() const;  //Checks for Oxygen's bioling point
        bool isWatrF() const; //Checks for Water's freezing point
        bool isWatrB() const; //Checks for Water's boiling point
};

#endif /* TEMPCHECK_H */

