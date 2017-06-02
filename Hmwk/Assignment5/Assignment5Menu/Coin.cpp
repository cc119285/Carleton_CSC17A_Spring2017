/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Coin.h"

void Coin::toss() {
    //Declare variable
        int randnum;
        
        //Get random number for sideUp
        randnum=rand()%2+1;
        
        if (randnum==1) {
            sideUp="Heads";
        } else {
            sideUp="Tails";
        }
}
   
string Coin::getSide() {
    return sideUp;
}