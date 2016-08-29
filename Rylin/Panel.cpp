#include <BearLibTerminal.h>
#include "Panel.h"
#include "Player.h"
#include "enums/colors.cpp"
#include <sstream>
#include <string>


void Panel::Draw()
{
    terminal_color(CL_AQUA);
    terminal_print(0, 2, Player::name);
    terminal_color(CL_ORANGE);
    terminal_print(0, 3, Player::race);
    terminal_color(CL_WHITE);
    terminal_print(0, 5, "�������");
    terminal_print(0, 6, "����");
    terminal_print(0, 7, "������");

    terminal_print(0, 9, "����");
    terminal_print(0, 10, "��������");
    terminal_print(0, 11, "���������");
    terminal_print(0, 12, "//�����");
    terminal_print(0, 13, "��������");
    terminal_print(0, 14, "�������");

    terminal_print(0, 16, "�.��������");
    terminal_print(0, 17, "��������");


    terminal_color(CL_AQUA);
    std::stringstream ss;
    std::string s;
    ss << Player::level;
    ss >> s;
    terminal_print(12, 5, s.c_str());
    ss.clear();
    ss << Player::experiance;
    s.clear();
    ss >> s;
    terminal_print(12, 6, s.c_str());

    /*
    * ������������ ������ �� ���������
    */
    terminal_print(12, 7, "500");

    ss.clear();
    ss << Player::Str.current;
    s.clear();
    ss >> s;
    terminal_print(12, 9, s.c_str());

    ss.clear();
    ss << Player::Agi.current;
    s.clear();
    ss >> s;
    terminal_print(12, 10, s.c_str());

    ss.clear();
    ss << Player::Int.current;
    s.clear();
    ss >> s;
    terminal_print(12, 11, s.c_str());

    ss.clear();
    ss << Player::Sta.current;
    s.clear();
    ss >> s;
    terminal_print(12, 12, s.c_str());

    ss.clear();
    ss << Player::Will.current;
    s.clear();
    ss >> s;
    terminal_print(12, 13, s.c_str());

    ss.clear();
    ss << Player::Cha.current;
    s.clear();
    ss >> s;
    terminal_print(12, 14, s.c_str());

    /*
    * some stats
    */




}
