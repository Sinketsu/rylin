#define COUNT_OF_RACES 10

struct Race
{
    char Name[15];
    char Description[256];

    int8_t Strength; // ���� - ��������� ���� � ������� ���
    int8_t Agility; // �������� - ���� ���������� �� ����� � ������� ���
    int8_t Intellect; // ���������� - ��������� ������ ����
    int8_t Stamina; // �������� - ���������� ����� �����
    int8_t Willpower; // ���� ���� - ���������� ����� ����
    int8_t Charm; // �������(�������) - ���� �� ������
    int8_t Fight; // �������� - ������ ������
    int8_t Stat1; // ��������������� ��� �������� �������������
    int8_t Stat2; // ��������������� ��� �������� �������������


    int8_t Magic_water; // ����� ����
    int8_t Magic_fire; // ����� ����
    int8_t Magic_earth; // ����� �����
    int8_t Magic_wind; // ����� �������
    int8_t Magic_light; // ����� �����
    int8_t Magic_dark; // ����� ����
    int8_t Magic_other; // ������ �����

};

color_t get_color_stat(int i)
{
    switch (i)
    {
    case 1:
        return 0xFFFF0000;
    case 2:
        return 0xFFFF8000;
    case 3:
        return 0xFFFFFF00;
    case 4:
        return 0xFF00FF00;
    case 5:
        return 0xFF00FFFF;
    }
}

char* get_level_stat(int i)
{
    switch (i)
    {
    case 1:
        return "*";
    case 2:
        return "**";
    case 3:
        return "***";
    case 4:
        return "****";
    case 5:
        return "*****";
    }
}

Race Race_array[COUNT_OF_RACES] =
{
    {"����", "����� ������������ ����. ����� �� �������������.",
                3, // Strength
                2, // Agility
                2, // Intellect
                3, // Stamina
                1, // Willpower
                3, // Charm
                3, // Fight
                0, // Stat1
                0, // Stat2

                2, // Water
                3, // Fire
                2, // Earth
                1, // Wind
                2, // Light
                1, // Dark
                2, // Other
                },
    {"����-��", "������ ������ � ������� ����� ������� ��������. ����� �������� ������������ "\
                "���������� - ������� ��� � �����.",
                2, // Strength
                4, // Agility
                2, // Intellect
                2, // Stamina
                3, // Willpower
                5, // Charm
                4, // Fight
                0, // Stat1
                0, // Stat2

                2, // Water
                1, // Fire
                3, // Earth
                1, // Wind
                1, // Light
                1, // Dark
                4, // Other
                },
    {"�����", "����� ������ ����. ������� ����� �����.",
                4, // Strength
                1, // Agility
                2, // Intellect
                4, // Stamina
                1, // Willpower
                2, // Charm
                4, // Fight
                0, // Stat1
                0, // Stat2

                1, // Water
                2, // Fire
                5, // Earth
                1, // Wind
                1, // Light
                2, // Dark
                2, // Other
                },
    {"����", "������ ����.",
                1, // Strength
                4, // Agility
                3, // Intellect
                2, // Stamina
                2, // Willpower
                2, // Charm
                2, // Fight
                0, // Stat1
                0, // Stat2

                2, // Water
                1, // Fire
                1, // Earth
                3, // Wind
                1, // Light
                5, // Dark
                3, // Other
                },
    {"���������", "�������� ������������.",
                4, // Strength
                1, // Agility
                2, // Intellect
                5, // Stamina
                3, // Willpower
                3, // Fight
                3, // Charm
                0, // Stat1
                0, // Stat2

                1, // Water
                3, // Fire
                4, // Earth
                1, // Wind
                1, // Light
                1, // Dark
                3, // Other
                },
    {"����", "���� ����������. � ��� ���������� � �������� �� ����� �����.",
                2, // Strength
                3, // Agility
                4, // Intellect
                1, // Stamina
                5, // Willpower
                3, // Charm
                1, // Fight
                0, // Stat1
                0, // Stat2

                1, // Water
                1, // Fire
                1, // Earth
                2, // Wind
                2, // Light
                1, // Dark
                4, // Other
                },
    {"����������", "�������� ������������ ����. ����� ���� ������� ������ ����.",
                5, // Strength
                1, // Agility
                2, // Intellect
                3, // Stamina
                1, // Willpower
                1, // Charm
                5, // Fight
                0, // Stat1
                0, // Stat2

                1, // Water
                5, // Fire
                2, // Earth
                1, // Wind
                1, // Light
                2, // Dark
                1, // Other
                },
    {"���������", "������� ���������� � ������. ������� ������� ������ �������.",
                2, // Strength
                3, // Agility
                3, // Intellect
                2, // Stamina
                2, // Willpower
                2, // Charm
                4, // Fight
                0, // Stat1
                0, // Stat2

                2, // Water
                1, // Fire
                2, // Earth
                3, // Wind
                2, // Light
                2, // Dark
                5, // Other
                },
    {"������", "����� ������� ����.",
                2, // Strength
                5, // Agility
                2, // Intellect
                1, // Stamina
                2, // Willpower
                2, // Charm
                2, // Fight
                0, // Stat1
                0, // Stat2

                1, // Water
                1, // Fire
                2, // Earth
                5, // Wind
                1, // Light
                3, // Dark
                3, // Other
                },
    {"������", "���������� �������� � ������� ����� ����.",
                1, // Strength
                1, // Agility
                4, // Intellect
                4, // Stamina
                5, // Willpower
                4, // Charm
                2, // Fight
                0, // Stat1
                0, // Stat2

                5, // Water
                1, // Fire
                1, // Earth
                2, // Wind
                4, // Light
                2, // Dark
                5, // Other
                },
};





