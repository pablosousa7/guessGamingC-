#include <iostream>
#include <cctype>
#include <string>
#include "../headers/Log.h"
#include "../headers/Exp.h"
#include <ncurses.h>
#include <termios.h>            
#include <unistd.h>
#include<stdio.h>


bool Log::uMenu(){
    int keyboard;
    static struct termios oldt, newt;
    tcgetattr( STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON);  
    tcsetattr( STDIN_FILENO, TCSANOW, &newt);

    std::cout << "\033[1;32m[ENTER]\033[0m - Start Game" << std::endl;
    std::cout << "\033[1;31m[ESPACE]\033[0m  - Exit Game" << std::endl;
     
    if((keyboard = getchar()) != 10){
        putchar(keyboard);
        return 0;
    }
    
    tcsetattr( STDIN_FILENO, TCSANOW, &oldt);
    return 1;
}

void Log::uWinWithAdvacedLevel(Exp* exp){
   
    Exp exp_ = *exp;

    std::cout << "\n\nPC say: \033[1;32mWoow.. you winner :]\033[0m" << std::endl;
    std::cout << "PC say: \033[1;32mYou advanced from " << exp_.getLevel() - 1 << " to " << exp_.getLevel() << " level.\033[0m" << std::endl;
    std::cout << "PC say: \033[1;32mExp: " << exp_.getExpPlayer() << "\033[0m\n\n" << std::endl;
}

void Log::uWinWithoutAdvancedLevel(Exp* exp){

    Exp exp_ = *exp;

    std::cout << "\nPC say: \033[1;32mWoow.. you winner :]\033[0m" << std::endl;
    std::cout << "PC say: \033[1;32mExp: " << exp_.getExpPlayer() << "\033[0m\n" << std::endl;
}

void Log::uLoser(){
    std::cout << "\nPC say: \033[1;31mSorry, you loser ;[\033[0m\n" << std::endl;
}

void Log::uCoution(){
    std::cout << "\nPC say: \033[1;33mBe careful, you only have one more chance.\033[0m\n" << std::endl;
}

bool Log::yPlayAgain(){

    char choice;

    std::cout << "\nPC say: \033[1;33mDo you play again? [Y][N]: \033[0m" << std::endl;
    std::cout << "You say: ";
    std::cin >> choice;
    
    // tranform all words in lowercase
    choice = tolower(choice);

    // condition if the player has continue with the game or not
    if(choice != 'y'){
        std::cout << "\n\n\nPC say: \033[1;33mOoh no, are you living?\033[0m\nPC say: \033[1;33mOk see you soon.\033[0m\n" << std::endl;
        return 0;
    }

    std::cout << "\n\nPC say: \033[1;32mYes, I know. Ok let's retart the game.\033[0m\nPC say: \033[1;32mGood Lock.\033[0m\n" << std::endl;
    return 1;
}

void Log::uWrong(){
    std::string phases[] = {
        "Oh no, this is not it, try again :)", 
        "Don't give up, I think you'll get it right now :D", 
        "You almost got it right, try again ;]",
        "Oh no, you wrong again ;["
    };

    int randPhase = (rand() % 4 + 1) - 1;

    std::cout << "\n\nPC say: \033[1;31m" << phases[randPhase] << "\033[0m\n" << std::endl;
}

void Log::uExit(){
    std::cout << "\nPC say: \033[1;33mOoh no, are you living?\033[0m\nPC say: \033[1;33mOk see you soon.\033[0m\nPC say: \033[1;33mBye bye..\033[0m" << std::endl;
}