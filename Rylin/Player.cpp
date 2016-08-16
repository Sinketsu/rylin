#include <BearLibTerminal.h>
#include "Player.h"
#include "enums/colors.cpp"

int Player::pos_x = -1;
int Player::pos_y = -1;
char Player::name[20] = "";
char Player::race[15] = "";
char Player::path[15] = "";


void Player::Draw()
{
    terminal_color(CL_YELLOW);
    terminal_put(Player::pos_x, Player::pos_y, '@');
}

void Player::Step(int dx, int dy)
{
    Player::pos_x += dx;
    Player::pos_y += dy;
}
