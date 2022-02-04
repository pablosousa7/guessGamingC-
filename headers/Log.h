#ifndef LOG_H
#define LOG_H
#include "Exp.h"

class Log
{
    public:
        void uWinWithAdvacedLevel(Exp*);
        void uWinWithoutAdvancedLevel(Exp*);
        void uLoser();
        void uCoution();
        void uWrong();
        void uExit();
        bool uMenu();
        bool yPlayAgain();
};




#endif