#ifndef PLAYER_H
#define PLAYER_H

class Player{
    private:
        char* name;
        int level;
        double exp;

    public:
        char* getname();
        int getlevel();
        double getExp();

    public:
        void setname();
};

#endif