#include <BearLibTerminal.h>
#include "Player.h"
#include "Control.h"
#include "Menu.h"
#include "Map.h"
#include "Panel.h"
#include "Enemy.h"
#include "enums/colors.cpp"
#include <cstring>

using namespace std;

__attribute__((always_inline)) void init()
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
    Map::calculate_cosinus();
    Map::calculate_sinus();

    start_menu();
    Player::FOV_radius = 5;
    Map::Load_level(0);

    Monster_info mi;
    mi.att = 10;
    mi.col = CL_GOLD;
    mi.hp = 100;
    memcpy(mi.name, "Кабанчик\0", 30);
    mi.symb = 'k';
    Monster m(mi, Player::pos_x, Player::pos_y);

    Monster_list.push_back(m);

    while (true)
    {
        Panel::Draw();
        Map::Draw_level();
        Map::Draw_portal();
        for ( std::list<Monster>::iterator i = Monster_list.begin(); i != Monster_list.end(); i++ )
        {
            (*i).Draw();
        }

        Player::Draw();

        terminal_refresh();
        do_action();
        terminal_clear();
    }

    return 0;
}
