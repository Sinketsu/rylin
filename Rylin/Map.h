#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#define M_WIGHT 150
#define M_HEIGTH 45

struct Tile
{
    char symbol;
    unsigned long long color;
    bool can_move;
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
    static bool get_moving_stat(char);
};

#endif // MAP_H_INCLUDED
