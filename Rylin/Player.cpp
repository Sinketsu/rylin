#include <BearLibTerminal.h>
#include "Player.h"
#include "enums/colors.cpp"
#include "Map.h"

int Player::pos_x;
int Player::pos_y;
int Player::FOV_radius;

int Player::level;
int Player::experiance;
char Player::name[20];
char Player::race[15];
char Player::path[15];
color_t Player::color = CL_WHITE;

Stat Player::Agi;
Stat Player::Str;
Stat Player::Int;
Stat Player::Sta;
Stat Player::Will;
Stat Player::Cha;

void Player::Draw()
{
    terminal_color(Player::color);
    terminal_put(Player::pos_x, Player::pos_y, '@');
}

void Player::Step(int dx, int dy)
{
    if (Map::get_moving_flag(Player::pos_x + dx - 170 + M_WIDTH, Player::pos_y + dy - 46 + M_HEIGHT))
    {
        Player::pos_x += dx;
        Player::pos_y += dy;
    }
    Map::Clear_FOV(Player::pos_x, Player::pos_y);
    Map::Calculate_FOV(Player::pos_x, Player::pos_y);

}
