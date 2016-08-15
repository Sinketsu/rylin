#include "BearLibTerminal.h"
#include "Control.h"
#include "Player.h"


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
    }
}
