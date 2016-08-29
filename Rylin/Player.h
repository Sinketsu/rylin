#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

struct Stat
{
    int normal;
    int current;
};

class Player
{
public:
    static int pos_x;
    static int pos_y;
    static int FOV_radius;

    static int level;
    static int experiance;

    static char name[20]; //��� ���������
    static char race[15]; //���� ���������
    static char path[15]; //����� ���������
    static color_t color;

    static Stat Str;
    static Stat Agi;
    static Stat Int;
    static Stat Sta;
    static Stat Will;
    static Stat Cha;

    static void Draw();
    static void Step(int, int);
};

#endif // PLAYER_H_INCLUDED
