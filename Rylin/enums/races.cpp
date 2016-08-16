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
    int8_t Stat1; // ��������������� ��� �������� �������������
    int8_t Stat2; // ��������������� ��� �������� �������������

    int8_t Magic_water; // ����� ����
    int8_t Magic_fire; // ����� ����
    int8_t Magic_earth; // ����� �����
    int8_t Magic_wind; // ����� �������
    int8_t Magic_music; // ����� ��������� � ������
    int8_t Magic_illusion; // ����� �������
    int8_t Magic_buffs; // ����� �������� � �������
    int8_t Magic_light; // ����� �����
    int8_t Magic_dark; // ����� ����
    int8_t Magic_fight; // ����� ��������
};

Race Race_array[COUNT_OF_RACES] =
{
    {"����", "����� ������������ ����. ����� �� �������������.",
                3, // Strength
                2, // Agility
                2, // Intellect
                3, // Stamina
                1, // Willpower
                3, // Charm
                0, // Stat1
                0, // Stat2

                1, // Water
                1, // Fire
                1, // Earth
                3, // Wind
                3, // Music and support
                1, // Illusion
                2, // Buffs and heal
                1, // Light
                1, // Dark
                2, // Fight
                },
    {"����-��", "������ ������ � ������� ����� ������� ��������. ����� �������� ������������ "\
                "���������� - ������� ��� � �����.",
                2, // Strength
                3, // Agility
                2, // Intellect
                2, // Stamina
                3, // Willpower
                5, // Charm
                0, // Stat1
                0, // Stat2

                2, // Water
                1, // Fire
                3, // Earth
                1, // Wind
                1, // Music and support
                1, // Illusion
                3, // Buffs and heal
                2, // Light
                1, // Dark
                3, // Fight
                },
    {"�����", "����� ������ ����. ������� ����� �����.",
                4, // Strength
                1, // Agility
                2, // Intellect
                4, // Stamina
                1, // Willpower
                2, // Charm
                0, // Stat1
                0, // Stat2

                1, // Water
                3, // Fire
                5, // Earth
                1, // Wind
                1, // Music and support
                1, // Illusion
                1, // Buffs and heal
                1, // Light
                2, // Dark
                4, // Fight
                },
    {"����", "������ ����.",
                2, // Strength
                3, // Agility
                3, // Intellect
                2, // Stamina
                2, // Willpower
                2, // Charm
                0, // Stat1
                0, // Stat2

                2, // Water
                1, // Fire
                1, // Earth
                3, // Wind
                1, // Music and support
                2, // Illusion
                1, // Buffs and heal
                1, // Light
                5, // Dark
                5, // Fight
                },
    {"���������", "�������� ������������.",
                4, // Strength
                1, // Agility
                2, // Intellect
                4, // Stamina
                3, // Willpower
                3, // Charm
                0, // Stat1
                0, // Stat2

                1, // Water
                3, // Fire
                4, // Earth
                1, // Wind
                1, // Music and support
                1, // Illusion
                3, // Buffs and heal
                2, // Light
                1, // Dark
                2, // Fight
                },
    {"����", "���� ����������. � ��� ���������� � �������� �� ����� �����.",
                2, // Strength
                3, // Agility
                4, // Intellect
                1, // Stamina
                5, // Willpower
                3, // Charm
                0, // Stat1
                0, // Stat2

                2, // Water
                3, // Fire
                1, // Earth
                3, // Wind
                5, // Music and support
                3, // Illusion
                3, // Buffs and heal
                1, // Light
                1, // Dark
                1, // Fight
                },
    {"����������", "�������� ������������ ����. ����� ���� ������� ������ ����.",
                4, // Strength
                1, // Agility
                2, // Intellect
                2, // Stamina
                1, // Willpower
                2, // Charm
                0, // Stat1
                0, // Stat2

                1, // Water
                5, // Fire
                1, // Earth
                2, // Wind
                1, // Music and support
                2, // Illusion
                1, // Buffs and heal
                1, // Light
                2, // Dark
                5, // Fight
                },
    {"���������", "������� ���������� � ������. ������� ������� ������ �������.",
                2, // Strength
                4, // Agility
                3, // Intellect
                2, // Stamina
                2, // Willpower
                3, // Charm
                0, // Stat1
                0, // Stat2

                2, // Water
                1, // Fire
                2, // Earth
                3, // Wind
                2, // Music and support
                5, // Illusion
                2, // Buffs and heal
                2, // Light
                2, // Dark
                1, // Fight
                },
    {"��������", "����� ������� ����.",
                2, // Strength
                5, // Agility
                2, // Intellect
                1, // Stamina
                2, // Willpower
                2, // Charm
                0, // Stat1
                0, // Stat2

                1, // Water
                1, // Fire
                2, // Earth
                5, // Wind
                1, // Music and support
                1, // Illusion
                3, // Buffs and heal
                1, // Light
                3, // Dark
                4, // Fight
                },
    {"������", "���������� �������� � ������� ����� ����.",
                1, // Strength
                1, // Agility
                4, // Intellect
                4, // Stamina
                5, // Willpower
                4, // Charm
                0, // Stat1
                0, // Stat2

                5, // Water
                1, // Fire
                1, // Earth
                3, // Wind
                4, // Music and support
                1, // Illusion
                5, // Buffs and heal
                1, // Light
                1, // Dark
                1, // Fight
                },
};





