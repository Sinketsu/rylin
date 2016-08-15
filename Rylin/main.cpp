#include <BearLibTerminal.h>
#include "Player.h"

using namespace std;

void init()
{
    terminal_open();
    terminal_set("window: title='RYLIN', size=160x50");
    terminal_set("font: fonts/UbuntuMono-R.ttf, size=12");
    terminal_set("terminal.encoding=1251");
}

int main()
{
    init();
    Player::pos_x = 10;
    Player::pos_y = 10;
    while (true)
    {
        Player::Draw();
        terminal_refresh();
        terminal_clear();
        switch (terminal_read())
        {
            case TK_RIGHT:
                Player::pos_x++;
                break;
            case TK_LEFT:
                Player::pos_x--;
                break;
            case TK_UP:
                Player::pos_y--;
                break;
            case TK_DOWN:
                Player::pos_y++;
                break;
            case TK_ESCAPE:
                terminal_close();
        }
    }

    return 0;
}
