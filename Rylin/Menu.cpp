#include "BearLibTerminal.h"
#include "Player.h"
#include "enums/races.cpp"

int selected_race = 0;
int selected_path = 0;
int selected_gender = 0;
bool gender = false, race = false, path = false;

void start_menu()
{
    terminal_color(0xFFFF8000);
    terminal_print(1, 1, "����� ���������� � ��� RYLIN!");
    terminal_color(0xFF00FFFF);
    terminal_print(1, 3, "�������� ������ �����!");

    //select gender
    terminal_print(6, 5, "�������� ��� ���������:");
    terminal_color(0xFFFFFFFF);


    while (!gender)
    {
        if (selected_gender == 0)
        {
            terminal_color(0XFFFF8000);
            terminal_print(6, 6, ">�������");
            terminal_color(0XFFFFFFFF);
            terminal_print(6, 7, " �������");
            terminal_refresh();
        }
        else
        {
            terminal_color(0XFFFFFFFF);
            terminal_print(6, 6, " �������");
            terminal_color(0XFFFF8000);
            terminal_print(6, 7, ">�������");
            terminal_refresh();
        }
        switch (terminal_read())
        {
        case TK_UP:
            {
                if (!(selected_gender == 0))
                    selected_gender--;
                break;
            }
        case TK_DOWN:
            {
                if (!(selected_gender == 1))
                    selected_gender++;
                break;
            }
        case TK_RETURN:
            {
                gender = true;
            }
        }
    }

    //select race
    terminal_color(0xFF00FFFF);
    terminal_print(40, 5, "�������� ���� ���������:");
    terminal_color(0xFFFFFFFF);

    terminal_print(11, 22, "����:");
    terminal_print(7, 23, "��������:");
    terminal_print(6, 24, "���������:");
    terminal_print(7, 25, "��������:");
    terminal_print(11, 26, "����:");
    terminal_print(8, 27, "�������:");
    terminal_print(7, 28, "��������:");

    terminal_print(33, 22, "����:");
    terminal_print(32, 23, "�����:");
    terminal_print(32, 24, "�����:");
    terminal_print(31, 25, "������:");
    terminal_print(33, 26, "����:");
    terminal_print(33, 27, "����:");
    terminal_print(31, 28, "������:");

    while (!race)
    {
        for (int i = 0; i < COUNT_OF_RACES; i++)
        {
            if (i == selected_race)
            {
                terminal_color(0XFFFF8000);
                terminal_put(40, 6 + i, '>');
                terminal_print(41, 6 + i, Race_array[i].Name);
                terminal_color(0xFF00FFFF);
                terminal_clear_area(6, 20, 170 - 6, 1);
                terminal_print(6, 20, Race_array[i].Description);

                terminal_clear_area(17, 22, 5, 7);
                terminal_color(get_color_stat(Race_array[i].Strength));
                terminal_print(17, 22, get_level_stat(Race_array[i].Strength));
                terminal_color(get_color_stat(Race_array[i].Agility));
                terminal_print(17, 23, get_level_stat(Race_array[i].Agility));
                terminal_color(get_color_stat(Race_array[i].Intellect));
                terminal_print(17, 24, get_level_stat(Race_array[i].Intellect));
                terminal_color(get_color_stat(Race_array[i].Stamina));
                terminal_print(17, 25, get_level_stat(Race_array[i].Stamina));
                terminal_color(get_color_stat(Race_array[i].Willpower));
                terminal_print(17, 26, get_level_stat(Race_array[i].Willpower));
                terminal_color(get_color_stat(Race_array[i].Charm));
                terminal_print(17, 27, get_level_stat(Race_array[i].Charm));
                terminal_color(get_color_stat(Race_array[i].Fight));
                terminal_print(17, 28, get_level_stat(Race_array[i].Fight));

                terminal_clear_area(39, 22, 5, 7);
                terminal_color(get_color_stat(Race_array[i].Magic_water));
                terminal_print(39, 22, get_level_stat(Race_array[i].Magic_water));
                terminal_color(get_color_stat(Race_array[i].Magic_fire));
                terminal_print(39, 23, get_level_stat(Race_array[i].Magic_fire));
                terminal_color(get_color_stat(Race_array[i].Magic_earth));
                terminal_print(39, 24, get_level_stat(Race_array[i].Magic_earth));
                terminal_color(get_color_stat(Race_array[i].Magic_wind));
                terminal_print(39, 25, get_level_stat(Race_array[i].Magic_wind));
                terminal_color(get_color_stat(Race_array[i].Magic_light));
                terminal_print(39, 26, get_level_stat(Race_array[i].Magic_light));
                terminal_color(get_color_stat(Race_array[i].Magic_dark));
                terminal_print(39, 27, get_level_stat(Race_array[i].Magic_dark));
                terminal_color(get_color_stat(Race_array[i].Magic_other));
                terminal_print(39, 28, get_level_stat(Race_array[i].Magic_other));


            } else
            {
                terminal_color(0XFFFFFFFF);
                terminal_put(40, 6 + i, ' ');
                terminal_print(41, 6 + i, Race_array[i].Name);
            }
        }
        terminal_refresh();
        switch (terminal_read())
        {
        case TK_UP:
            {
                if (!(selected_race == 0))
                    selected_race--;
                break;
            }
        case TK_DOWN:
            {
                if (!(selected_race == COUNT_OF_RACES - 1))
                    selected_race++;
                break;
            }
        case TK_RETURN:
            {
                race = true;
            }
        }
    }


    terminal_refresh();
    while (true);
}



