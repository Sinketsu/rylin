#define COUNT_OF_RACES 10

struct Race
{
    char Name[15];
    char Description[256];

    int8_t Strength; // Сила - наносимый урон в ближнем бою
    int8_t Agility; // Ловкость - шанс увернуться от атаки в ближнем бою
    int8_t Intellect; // Инетеллект - наносимый магией урон
    int8_t Stamina; // Здоровье - количество очков жизни
    int8_t Willpower; // Сила воли - количество очков маны
    int8_t Charm; // Харизма(обаяние) - цены на товары
    int8_t Fight; // Сражение - боевые навыки
    int8_t Stat1; // Зарезервировано для будущего использования
    int8_t Stat2; // Зарезервировано для будущего использования


    int8_t Magic_water; // Магия воды
    int8_t Magic_fire; // Магия огня
    int8_t Magic_earth; // Магия земли
    int8_t Magic_wind; // Магия воздуха
    int8_t Magic_light; // Магия света
    int8_t Magic_dark; // Магия тьмы
    int8_t Magic_other; // Разная магия

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
    {"Люди", "Самая обыкновенная раса. Ничем не примечательны.",
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
    {"Кайт-Ши", "Острое зрение и большие шансы поймать животных. Также обладают выделяющейся "\
                "внешностью - кошачьи уши и хвост.",
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
    {"Гномы", "Имеют низкий рост. Мастера магии земли.",
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
    {"Импы", "Ночная раса.",
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
    {"Лепреконы", "Искусные ремесленники.",
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
    {"Паки", "Раса музыкантов. В бою полагаются в основном на магию звука.",
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
    {"Саламандры", "Огненная воинственная раса. Лучше всех владеют магией огня.",
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
    {"Спригганы", "Мастера скрытности и обмана. Отлично владеют магией иллюзий.",
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
    {"Сильфы", "Самая быстрая раса.",
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
    {"Ундины", "Прекрасные целители и мастера магии воды.",
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





