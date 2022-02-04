#include "../headers/Player.h"
#include "../headers/Exp.h"
#include <iostream>


char* Player::getname() {return name; };
void Player::setname(){ 
    bool isValid = false;
    char m_name[256];

    while(!isValid){
        
        std::cout << "PC say: \033[1;33mPlease enter your name: \033[0m" << std::endl;
        std::cout << "You say: ";
        std::cin >> m_name;

        if(m_name != NULL){
            std::cout << "PC say: \033[1;33mWelcome to the game " << m_name << " Let's get stated.\n\033[0m" << std::endl;
            this->name = name;
            break;
        }
    }
}

int Player::getlevel(){
    Exp exp;

    return exp.getLevel();
}

double Player::getExp(){
    Exp exp;

    return exp.getExpPlayer();
}