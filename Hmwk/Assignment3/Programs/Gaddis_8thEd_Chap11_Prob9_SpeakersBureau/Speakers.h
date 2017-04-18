/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Speakers.h
 * Author: Colleen Carleton
 *
 * Created on March 26, 2017, 3:05 PM
 */

#ifndef SPEAKERS_H
#define SPEAKERS_H

//Create Structure to store information on each speaker
    struct Speaker
    {
        string spName; //Stores speaker's name
        int spNum;     //Stores speaker's telephone number
        string spTopc; //Stores the speaker's topic
        float spFee;   //Stores the speaker's fee
    };

#endif /* SPEAKERS_H */

