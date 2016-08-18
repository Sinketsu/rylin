#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#define M_WIGHT 150
#define M_HEIGTH 45

struct Tile
{
    char symbol;
    char flags;
};

class Map
{
public:
    static Tile level[M_WIGHT][M_HEIGTH];
    static int Player_posx;
    static int Player_posy;


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
