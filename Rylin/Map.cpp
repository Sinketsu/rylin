#include "Map.h"
#include "BearLibTerminal.h"
#include "enums/colors.cpp"
#include <fstream>

Tile Map::level[M_WIGHT][M_HEIGTH];
int Map::Player_posx = 50;
int Map::Player_posy = 30;


bool Map::get_moving_flag(int x, int y)
{
    return (Map::level[x][y].flags & 128) == 0 ? false : true;
}

bool Map::get_fov_visible_flag(int x, int y)
{
    return (Map::level[x][y].flags & 32) == 0 ? false : true;
}

bool Map::get_discovered_flag(int x, int y)
{
    return (Map::level[x][y].flags & 64) == 0 ? false : true;
}

void Map::set_moving_flag(int x, int y, bool state)
{
    if (state)
    {
        Map::level[x][y].flags |= 128;
    } else
    {
        Map::level[x][y].flags &= !128;
    }
}

void Map::set_fov_visible_flag(int x, int y, bool state)
{
    if (state)
    {
        Map::level[x][y].flags |= 32;
    } else
    {
        Map::level[x][y].flags &= !32;
    }
}

void Map::set_discovered_flag(int x, int y, bool state)
{
    if (state)
    {
        Map::level[x][y].flags |= 64;
    } else
    {
        Map::level[x][y].flags &= !64;
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
            fin >> Map::level[k][i].flags;
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
