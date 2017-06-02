/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "TempCheck.h"

void TempChk::setTemp(int t) {
    temprtr=t;
}

int TempChk::getTemp() {
    return temprtr;
}

bool TempChk::isEthlF() const {
    bool freeze;
    if (temprtr<=-173) {
        freeze=true;
    } else {
        freeze=false;
    }
    return freeze;
}

bool TempChk::isEthlB() const {
     bool boil;
     if (temprtr>=172) {
         boil=true;
     } else {
         boil=false;
     }
     return boil;
}

bool TempChk::isOxyF() const {
    bool freeze;
    if (temprtr<=-362) {
        freeze=true;
    } else {
        freeze=false;
    }
    return freeze;
}

bool TempChk::isOxyB() const {
    bool boil;
     if (temprtr>=-306) {
         boil=true;
     } else {
         boil=false;
     }
     return boil;
}

bool TempChk::isWatrF() const {
    bool freeze;
    if (temprtr<=32) {
        freeze=true;
    } else {
        freeze=false;
    }
    return freeze;
}

bool TempChk::isWatrB() const {
    bool boil;
     if (temprtr>=212) {
         boil=true;
     } else {
         boil=false;
     }
     return boil;
}
