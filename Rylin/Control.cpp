#include "BearLibTerminal.h"
#include "Control.h"
#include "Player.h"
#include "Map.h"


void do_action()
{
    int key = terminal_read();
    switch (key)
    {
    case TK_KP_1:
        {
            Player::Step(-1, 1);
            break;
        }
    case TK_KP_2:
        {
            Player::Step(0, 1);
            break;
        }
    case TK_KP_3:
        {
            Player::Step(1, 1);
            break;
        }
    case TK_KP_4:
        {
            Player::Step(-1, 0);
            break;
        }
    case TK_KP_5:
        {
            Player::Step(0, 0);
            break;
        }
    case TK_KP_6:
        {
            Player::Step(1, 0);
            break;
        }
    case TK_KP_7:
        {
            Player::Step(-1, -1);
            break;
        }
    case TK_KP_8:
        {
            Player::Step(0, -1);
            break;
        }
    case TK_KP_9:
        {
            Player::Step(1, -1);
            break;
        }
    case TK_ESCAPE:
        {
            terminal_close();
            break;
        }
    case TK_KP_MULTIPLY:
        {
            if ((Player::pos_x == Map::portal.x) && (Player::pos_y == Map::portal.y))
            {
                Map::Load_level(Map::cur_level + 1);
            }
            if ((Player::pos_x == Map::ret_portal.x) && (Player::pos_y == Map::ret_portal.y))
            {
                Map::Load_level(Map::cur_level + 1);
            }
            break;
        }
    }
}
