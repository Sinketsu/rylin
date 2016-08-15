#include <BearLibTerminal.h>
#include "Player.h"

int Player::pos_x = -1;
int Player::pos_y = -1;
char Player::name[15] = "";
char Player::race[10] = "";
char Player::path[10] = "";


void Player::Draw()
{
    terminal_color(0xFFFFFF00);
    terminal_put(Player::pos_x, Player::pos_y, '@');
}

void Player::Step(int dx, int dy)
{
    Player::pos_x += dx;
    Player::pos_y += dy;
}
