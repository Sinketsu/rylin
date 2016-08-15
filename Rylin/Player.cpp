#include <BearLibTerminal.h>
#include "Player.h"

int Player::pos_x = 1;
int Player::pos_y = 1;

void Player::Draw()
{
    terminal_color(0xFFFFFF00);
    terminal_put(Player::pos_x, Player::pos_y, '@');
}
