#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

#include "../inc/biblemenu.h"


BibleMenu::BibleMenu()
{
    std::string p = std::filesystem::current_path();
    std::string tmp = p + "/data/menu.txt";

    mpaths.pwd = p;
    mpaths.menu_file_path = tmp;
}

void BibleMenu::show_menu()
{
    std::string line;
    std::ifstream menu_file(mpaths.menu_file_path);

    while (std::getline(menu_file, line))
    {
        std::cout << line << std::endl;
    }

    menu_file.close();
}

BibleMenu::~BibleMenu(){}
