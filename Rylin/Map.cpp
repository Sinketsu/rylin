#include "Map.h"
#include "BearLibTerminal.h"
#include "enums/colors.cpp"
#include "Player.h"
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>


bool isExists(char* filePath)
{
    bool isExist = false;
    std::ifstream fin(filePath);

    if(fin.is_open())
        isExist = true;

    fin.close();
    return isExist;
}

/* Implementation of Map class */

Tile Map::level[M_WIDTH][M_HEIGHT];
Portal Map::portal;
int Map::cur_level;

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

bool is_round(int x, int y)
{
    return ((5 - x) * (5 - x) + (5 - y) * (5 - y) > 40) ? false : true;
}

bool check_room(int x, int y, int w, int h, char arr[M_HEIGHT][M_HEIGHT])
{
    for (int i = x - 1; i < x + w; i++)
        for (int k = y - 1; k < y + h; k++)
            if (arr[i][k] == '.')
                return false;
    return true;
}

draw_vertical_line(int y1, int y2, int x, char arr[M_HEIGHT][M_HEIGHT])
{
    for (int i = y1; i <= y2; i++)
        arr[x][i] = '.';
}

draw_horizontal_line(int x1, int x2, int y, char arr[M_HEIGHT][M_HEIGHT])
{
    for (int i = x1; i <= x2; i++)
        arr[i][y] = '.';
}

int load(char* filename)
{
    int x, y;
    std::ifstream fin(filename);
    for (int i = 0; i < M_HEIGHT; i++)
    {
        for (int k = 0; k < M_WIDTH; k++)
        {
            fin >> Map::level[k][i].symbol;
            fin >> Map::level[k][i].flags;
        }
    }

    fin >> x;
    fin >> y;
    Player::pos_x = x;
    Player::pos_y = y;

    fin >> x;
    fin >> y;
    Map::portal.x = x;
    Map::portal.y = y;

    fin.close();
}


int generate_level(int num)
{
    char arr[M_WIDTH][M_HEIGHT];
    std::vector<Room> V;
    for (int i = 0; i < M_WIDTH; i++)
        for (int k = 0; k < M_HEIGHT; k++)
            arr[i][k] = '#';


    int x_temp = M_WIDTH - BOSS_ROOM_WIDTH - 1;
    int y_temp = M_HEIGHT - BOSS_ROOM_HEIGHT - 1;
    for (int i = x_temp; i < x_temp + BOSS_ROOM_WIDTH; i++)
        for (int k = y_temp; k < y_temp + BOSS_ROOM_HEIGHT; k++)
            if (is_round(i - x_temp, k - y_temp))
                arr[i][k] = '.';
    arr[143][43] = 'D';

    V.push_back({x_temp, y_temp, BOSS_ROOM_WIDTH, BOSS_ROOM_HEIGHT});

    srand( time(0) );
    int w_temp, h_temp;
    for (int i = 0; i < ROOMS_COUNT; i++)
    {
        w_temp = rand() % ROOM_WIDTH_RANGE + MIN_ROOM_WIDTH;
        h_temp = rand() % ROOM_HEIGHT_RANGE + MIN_ROOM_HEIGHT;
        x_temp = rand() % 135 + 1;
        y_temp = rand() % 30 + 1;
        while (!check_room(x_temp, y_temp, w_temp, h_temp, arr))
        {
            w_temp = rand() % ROOM_WIDTH_RANGE + MIN_ROOM_WIDTH;
            h_temp = rand() % ROOM_HEIGHT_RANGE + MIN_ROOM_HEIGHT;
            x_temp = rand() % 135 + 1;
            y_temp = rand() % 30 + 1;
        }

        for (int k = x_temp; k < x_temp + w_temp; k++)
            for (int j = y_temp; j < y_temp + h_temp; j++)
                arr[k][j] = '.';

        V.push_back({x_temp, y_temp, w_temp, h_temp});
    }

    for (int i = 0; i < V.size() - 1; i++)
    {
        draw_horizontal_line( std::min(V[i].x + V[i].width / 2, V[i + 1].x + V[i + 1].width / 2),
                             std::max(V[i].x + V[i].width / 2, V[i + 1].x + V[i + 1].width / 2),
                             V[i].y + V[i].height / 2, arr );
        draw_vertical_line( std::min(V[i].y + V[i].height / 2, V[i + 1].y + V[i + 1].height / 2),
                             std::max(V[i].y + V[i].height / 2, V[i + 1].y + V[i + 1].height / 2),
                             V[i + 1].x + V[i + 1].width / 2, arr );
    }

    char name[] = "levels/level00.map";
    char num_arr[2];
    itoa(num, num_arr, 10);
    if (num_arr[1] == 0)
    {
        name[13] = num_arr[0];
    } else
    {
        name[12] = num_arr[0];
        name[13] = num_arr[1];
    }

    std::ofstream fout(name);
    for (int k = 0; k < M_HEIGHT; k++)
    {
        for (int i = 0; i < M_WIDTH; i++)
        {
            fout << arr[i][k];
            fout << ((arr[i][k] == '#') ? static_cast<char>(0) : static_cast<char>(128));
        }
    }
    fout << std::endl;
    fout << V[V.size() - 1].x + V[V.size() - 1].width / 2 + 170 - M_WIDTH;
    fout << ' ';
    fout << V[V.size() - 1].y + V[V.size() - 1].height / 2 + 46 - M_HEIGHT;
    fout << std::endl;
    fout << 146 + 170 - M_WIDTH;
    fout << ' ';
    fout << 43 + 46 - M_HEIGHT;
    fout.close();

    load(name);
}


int Map::Load_level(int level)
{
    switch (level)
    {
    case 0:
        {
            load("levels/town.map");
            Map::cur_level = 0;
            break;
        }
    case -1:
        {
            //load_pet_island;
        }
    default:
        {
            char name[] = "levels/level00.map";
            char t[2];
            itoa(level, t, 10);
            name[12] = t[0];
            name[13] = t[1];
            if ( isExists(name) )
            {
                generate_level(level);
            }
            else
            {
                generate_level(level);
            }

            break;
        }
    }
}

void Map::Draw_level()
{
    terminal_color(CL_WHITE);
    for (int i = 0; i < M_HEIGHT; i++)
    {
        for (int k = 0; k < M_WIDTH; k++)
        {
            terminal_put(170 - M_WIDTH + k, 50 - M_HEIGHT - 4 + i, Map::level[k][i].symbol);
        }
    }
}

void Map::Draw_portal()
{
    terminal_color(CL_AQUA);
    terminal_put(Map::portal.x, Map::portal.y, '*');
}

