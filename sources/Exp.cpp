#include "../headers/Exp.h"
#include <math.h>
#include <iostream>

double Exp::getExpPlayer(){
    return expPlayer;
}

void Exp::setExpPlayer(double exp){
    // formula of the totalExp
    // based in level user
    double totalExp = ((( 50 * pow(level, 3)) - 150 * pow(level, 2) + 400 * level) / 3);

    // validation exp
    expPlayer += exp;

    // up level if (expPlayer - totalExp) 
    // is equal the zero
    if((expPlayer > totalExp)){
        int totalLevelUp = (int)(round(expPlayer / totalExp));
        setLevel(1);
    }
}

int Exp::getLevel(){
    return level;
}

void Exp::setLevel(int lvl){
    // validation level
    if(lvl > 0){
        level += lvl;
    }
}