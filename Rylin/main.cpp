#include <BearLibTerminal.h>
#include "Player.h"
#include "Control.h"
#include "Menu.h"
#include "Map.h"
#include "enums/colors.cpp"

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



    while (true)
    {
        Map::Draw_level();
        Map::Draw_portal();
        Player::Draw();

        terminal_refresh();
        do_action();
        terminal_clear();
    }

    return 0;
}
