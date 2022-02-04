#include <iostream>
#include <istream>
#include "../headers/Exp.h"
#include "../headers/Log.h"
#include "../headers/InitG.h"
#include "../headers/Player.h"


int chancesMax = 3, chancesMin = 2, chancesStart = 0;
int choiseUser, guessNPC;
char closeGame;
Exp exp;
Log log;
Player player;

/***************************************************
*    This function check if the user winner
*    or not. If the condition is true
*    one value boolean will be returned
****************************************************/
bool checkGain(int choiseUser, int guessNPC, int chancesStart){
    
     // verify the choise of user
    if(choiseUser == guessNPC){
        int oldLvl = exp.getLevel();

        // verify the nivel of chances what user gain the game
        if(chancesStart == 1) exp.setExpPlayer(100.0); 
        if(chancesStart == 2) exp.setExpPlayer(50.0); 
        if(chancesStart == 3) exp.setExpPlayer(25);

        exp.getLevel() > oldLvl ? log.uWinWithAdvacedLevel(&exp) : log.uWinWithoutAdvancedLevel(&exp);

        return 1;
    }
        
    return 0;   
}



/***************************************************
 * This function randNumber create a random number
 * if the user already stated the game then
 * randNumber returned a int based in your level
 * if level is better then 5. 
 ****************************************************/
int randNumber(bool reset){

    // initialize rand()
    srand (time(NULL));

    if(reset){
        
        return exp.getLevel() <= 5 ? (rand() % 5) + 1 : rand() % exp.getLevel();
    }

    return (rand() % 6) + 1;
}


/*************************************************
 * The function reset is respansable for reset the
 * guessNPC and chancesStart
 ************************************************/
void reset(){
    guessNPC = randNumber(true);
    chancesStart = 0;
}



/*******************************************************************
 * This function is responsable for initiliaze the game
 * If the user would exit the game he need press the '0' (zero)
 * If the user would continue the game after loser or win he need
 * press the 'y' or 'n' for the exit game.
 *******************************************************************/
void InitG::__init__(){
    
    if(!log.uMenu()) return;

    // init the number magic    
    guessNPC = randNumber(false);

    // enter name
    player.setname();

    while(true){
        std::cout << "Choose your number: ";
        std::cin >> choiseUser;

        if(choiseUser == 0){
            log.uExit();
            break;
        }

        chancesStart++;

        // validation chancess
        if(chancesStart == chancesMax){
            checkGain(choiseUser, guessNPC, chancesStart);
            if(!log.yPlayAgain()) break;

            // if user chooses to continue the game
            // we must reset the number magic
            // and reset the chances
            reset();
        }
        
        if(checkGain(choiseUser, guessNPC, chancesStart)){
            // ask user if he want continue
            if(!log.yPlayAgain()) break;

            // if user chooses to continue the game
            // we must reset the number magic
            // and reset the chances
            reset();
        }
        
        if(chancesStart == chancesMin) log.uCoution();
        if(chancesStart != 0) log.uWrong();
    }
}


