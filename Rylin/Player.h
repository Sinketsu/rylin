#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

class Stat
{
    int normal;
    int current;
};

class Player
{
public:
    static int pos_x;
    static int pos_y;
    static char name[15]; //имя персонажа
    static char race[10]; //раса персонажа
    static char path[10]; //класс персонажа
    static Stat Str;
    static Stat Agi;
    static void Draw();
    static void Step(int, int);
};

#endif // PLAYER_H_INCLUDED
