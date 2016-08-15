#include "BearLibTerminal.h"
#include "Player.h"
#include "enums/races.cpp"

int select_race = 0;
int select_path = 0;
int select_gender = 0;
bool gender = false, race = false, path = false;

void start_menu()
{
    terminal_color(0xFFFF8000);
    terminal_print(1, 1, "Добро пожаловать!");
    terminal_color(0xFF00FFFF);
    terminal_print(1, 3, "Создайте своего героя!");
    terminal_print(6, 5, "Выберите пол персонажа:");
    terminal_color(0xFFFFFFFF);

    while (!gender)
    {
        if (select_gender == 0)
        {
            terminal_color(0XFFFF8000);
            terminal_print(6, 6, ">Мужской");
            terminal_color(0XFFFFFFFF);
            terminal_print(6, 7, " Женский");
            terminal_refresh();
        }
        else
        {
            terminal_color(0XFFFFFFFF);
            terminal_print(6, 6, " Мужской");
            terminal_color(0XFFFF8000);
            terminal_print(6, 7, ">Женский");
            terminal_refresh();
        }
        switch (terminal_read())
        {
        case TK_UP:
            {
                if (!(select_gender == 0))
                    select_gender--;
                break;
            }
        case TK_DOWN:
            {
                if (!(select_gender == 1))
                    select_gender++;
                break;
            }
        }
    }

    //for (int i = 0; i < 9; i++)
    //{
    //    terminal_print(7, 6 + i, Race_array[i].Name);
    //}
    terminal_refresh();
    while (true);
}



