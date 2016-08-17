#include "Map.h"
#include "BearLibTerminal.h"
#include "enums/colors.cpp"
#include <fstream>

Tile Map::level[M_WIGHT][M_HEIGTH];
int Map::Player_posx = 50;
int Map::Player_posy = 30;


bool Map::get_moving_stat(char ch)
{
    switch (ch)
    {
    case '.':
        return true;
    case '#':
        return false;
    default:
        return true;
    }
}

int load(char* filename)
{
    std::ifstream fin(filename);
    for (int i = 0; i < M_HEIGTH; i++)
    {
        for (int k = 0; k < M_WIGHT; k++)
        {
            fin >> Map::level[k][i].symbol;
            Map::level[k][i].can_move = Map::get_moving_stat(Map::level[k][i].symbol);
        }
    }
    fin.close();
}

int Map::Load_level(int level)
{
    switch (level)
    {
    case 0:
        {
            load("levels/town.map");
        }
    case -1:
        {
            //load_pet_island;
        }
    default:
        {
            //load_level;
        }
    }
}

void Map::Draw_level()
{
    terminal_color(CL_WHITE);
    for (int i = 0; i < M_HEIGTH; i++)
    {
        for (int k = 0; k < M_WIGHT; k++)
        {
            terminal_put(170 - M_WIGHT + k, 50 - M_HEIGTH - 4 + i, Map::level[k][i].symbol);
        }
    }
}
