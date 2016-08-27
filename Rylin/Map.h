#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#define M_WIDTH 150
#define M_HEIGHT 45
#define BOSS_ROOM_WIDTH 11
#define BOSS_ROOM_HEIGHT 11
#define ROOMS_COUNT 15
#define ROOM_WIDTH_RANGE 6
#define ROOM_HEIGHT_RANGE 6
#define MIN_ROOM_WIDTH 6
#define MIN_ROOM_HEIGHT 6

struct Tile
{
    char symbol;
    char flags;
};

struct Portal
{
    int x;
    int y;
};

struct Room
{
    int x, y;
    int width, height;
};

class Map
{
public:
    static Tile level[M_WIDTH][M_HEIGHT];
    static Portal portal;
    static Portal ret_portal;
    static int cur_level;

    static void Draw_portal();

    static int Load_level(int);
    static void Draw_level();
    static int Save_level(char*);

    static bool get_moving_flag(int, int);      // *0000000; 1 - можно пройти, 0 - нельзя
    static bool get_discovered_flag(int, int);  // 0*000000; 1 - исследовано, 0 - не исследовано
    static bool get_fov_visible_flag(int, int); // 00*00000; 1 - видимо игроку, 0 - невидимо игроку

    static void set_moving_flag(int, int, bool);
    static void set_discovered_flag(int, int, bool);
    static void set_fov_visible_flag(int, int, bool);
};

#endif // MAP_H_INCLUDED
