#ifndef EXP_H
#define EXP_H
/**
 * This function is responsable for the control of experience user
 * like level and experience rateing.
 */

class Exp
{
    private:
        int level = 1;
        double expPlayer = 0;
    
    public:
        // Setting the funcions 
        // level and experience of player
        void setLevel(int);
        void setExpPlayer(double);

        // Getting the functions 
        //level and experience of player
        int getLevel();
        double getExpPlayer();
};

#endif