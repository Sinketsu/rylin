#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

struct Stat
{
    int normal;
    int current;
};

class Player
{
public:
    static int pos_x;
    static int pos_y;
    static int FOV_radius;
    static char name[20]; //имя персонажа
    static char race[15]; //раса персонажа
    static char path[15]; //класс персонажа
    static color_t color;

    static Stat Str;
    static Stat Agi;



    static void Draw();
    static void Step(int, int);
};

#endif // PLAYER_H_INCLUDED
