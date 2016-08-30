#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

#include <BearLibTerminal.h>
#include "enums/colors.cpp"
#include <list>


struct Monster_info
{
    int hp;
    int att;
    char symb;
    color_t col;
    char name[30];
};

class Monster
{
public:
    int pos_x, pos_y;  // Position
    int cur_hp;        // Current Hit points
    int hp;            // Normal Hit points
    int attack;        // Attack points
    char symbol;       // Character for drawing
    color_t color;     // Color for drawing symbol
    char name[30];

    Monster(Monster_info, int, int);
    void Draw();
};

std::list<Monster> Monster_list;

#endif // ENEMY_H_INCLUDED
