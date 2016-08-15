#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

class Stat
{
    int normal;
    int current;
};

class Player
{
public:
    static int pos_x;
    static int pos_y;
    static char name[15]; //��� ���������
    static char race[10]; //���� ���������
    static char path[10]; //����� ���������
    static Stat Str;
    static Stat Agi;
    static void Draw();
    static void Step(int, int);
};

#endif // PLAYER_H_INCLUDED
