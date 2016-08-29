#include "BearLibTerminal.h"
#include "Player.h"
#include "enums/races.cpp"
#include "enums/colors.cpp"
#include <cstring>

int selected_race = 0;
int selected_path = 0;
int selected_gender = 0;
bool gender = false, race = false, path = false;

void start_menu()
{
    char selected_name[20];
    selected_name[0] = 0;

    terminal_color(CL_ORANGE);
    terminal_print(1, 1, "Добро пожаловать в мир RYLIN!");
    terminal_color(CL_AQUA);
    terminal_print(1, 3, "Создайте своего героя!");

    //select gender
    terminal_print(6, 5, "Выберите пол персонажа:");
    terminal_color(CL_WHITE);


    while (!gender)
    {
        if (selected_gender == 0)
        {
            terminal_color(CL_ORANGE);
            terminal_print(6, 6, ">Мужской");
            terminal_color(CL_WHITE);
            terminal_print(6, 7, " Женский");
            terminal_refresh();
        }
        else
        {
            terminal_color(CL_WHITE);
            terminal_print(6, 6, " Мужской");
            terminal_color(CL_ORANGE);
            terminal_print(6, 7, ">Женский");
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
    terminal_color(CL_AQUA);
    terminal_print(40, 5, "Выберите расу персонажа:");
    terminal_color(CL_WHITE);

    terminal_print(6, 20, "Цвет:");

    terminal_print(11, 22, "Сила:");
    terminal_print(7, 23, "Ловкость:");
    terminal_print(6, 24, "Интеллект:");
    terminal_print(7, 25, "Здоровье:");
    terminal_print(11, 26, "Воля:");
    terminal_print(8, 27, "Харизма:");
    terminal_print(7, 28, "Сражение:");

    terminal_print(33, 22, "Вода:");
    terminal_print(32, 23, "Огонь:");
    terminal_print(32, 24, "Земля:");
    terminal_print(31, 25, "Воздух:");
    terminal_print(33, 26, "Свет:");
    terminal_print(33, 27, "Тьма:");
    terminal_print(31, 28, "Другая:");

    while (!race)
    {
        for (int i = 0; i < COUNT_OF_RACES; i++)
        {
            if (i == selected_race)
            {
                terminal_color(CL_ORANGE);
                terminal_put(40, 6 + i, '>');
                terminal_print(41, 6 + i, Race_array[i].Name);
                terminal_color(CL_AQUA);
                terminal_clear_area(6, 19, 170 - 6, 1);
                terminal_print(6, 19, Race_array[i].Description);

                terminal_clear_area(12, 20, 1, 1);
                terminal_color(Race_array[i].color);
                terminal_put(12, 20, '@');


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
                terminal_color(CL_WHITE);
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

    //select path
    terminal_color(CL_AQUA);
    terminal_print(80, 5, "Выберите путь персонажа:");
    terminal_color(CL_ORANGE);
    while (!path)
    {
        terminal_print(80, 6, ">PATH");
        terminal_refresh();
        switch (terminal_read())
        {
        case TK_UP:
            {
                if (!(selected_path == 0))
                    selected_path--;
                break;
            }
        case TK_DOWN:
            {
                if (!(selected_path == 0))
                    selected_path++;
                break;
            }
        case TK_RETURN:
            {
                path = true;
            }
        }
    }

    terminal_clear_area(0, 0, 60, 4);
    terminal_color(CL_AQUA);
    terminal_print(0, 0, "Введите имя персонажа:");
    terminal_color(CL_WHITE);
    if (terminal_read_str(23, 0, selected_name, 19) != TK_INPUT_CANCELLED)
    {
        memcpy(Player::name, selected_name, 20);
        memcpy(Player::race, Race_array[selected_race].Name, 15);
        memcpy(Player::path, "PATH1\0", 6);
        Player::color = Race_array[selected_race].color;

        Player::Agi.current = Player::Agi.normal = Race_array[selected_race].Agility;
        Player::Str.current = Player::Str.normal = Race_array[selected_race].Strength;
        Player::Int.current = Player::Int.normal = Race_array[selected_race].Intellect;
        Player::Sta.current = Player::Sta.normal = Race_array[selected_race].Stamina;
        Player::Will.current = Player::Will.normal = Race_array[selected_race].Willpower;
        Player::Cha.current = Player::Cha.normal = Race_array[selected_race].Charm;

        Player::level = 0;
        Player::experiance = 0;
    }

}



