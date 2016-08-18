#include <BearLibTerminal.h>
#include "Player.h"
#include "Control.h"
#include "Menu.h"
#include "Map.h"


using namespace std;

void init()
{
    terminal_open();
    terminal_set("window: title='RYLIN', size=170x50");
    terminal_set("font: fonts/UbuntuMono-R.ttf, size=12");
    terminal_set("terminal.encoding=1251");
    terminal_set("input: cursor-symbol=0x5F");
}


int main()
{
    init();

    start_menu();
    Map::Load_level(0);
    Player::pos_x = Map::Player_posx;
    Player::pos_y = Map::Player_posy;

    while (true)
    {
        Map::Draw_level();
        Player::Draw();
        terminal_refresh();

        do_action();
        terminal_clear();
    }

    return 0;
}
