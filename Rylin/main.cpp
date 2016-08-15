#include <BearLibTerminal.h>
#include "Player.h"
#include "Control.h"
#include "Menu.h"


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

    if (Player::name == "")
    {
        start_menu();
    }

    while (true)
    {
        Player::Draw();

        terminal_refresh();
        terminal_clear();
        do_action();
    }

    return 0;
}
