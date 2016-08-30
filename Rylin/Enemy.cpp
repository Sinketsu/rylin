#include "Map.h"
#include "Enemy.h"

#include <cstring>

Monster::Monster(Monster_info mi, int x, int y)
{
    this->attack = mi.att;
    this->hp = mi.hp;
    this->cur_hp = mi.hp;
    this->color = mi.col;
    this->symbol = mi.symb;
    this->pos_x = x;
    this->pos_y = y;
    memcpy(this->name, mi.name, 30);
}

void Monster::Draw()
{
    terminal_color( this->color );
    terminal_put( this->pos_x + 170 - M_WIDTH, this->pos_y + 50 - 4 - M_HEIGHT, this->symbol );
}
