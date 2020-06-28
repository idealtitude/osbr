#include <iostream>
#include <string>
#include <map>
#include <filesystem>

#include "../inc/appinit.h"

AppInit::AppInit()
{
    const std::map<std::string, std::string> data_files = {
        {"bibledb", "./data/bibledb.ini"}, 
        {"bookmarks", "./data/bookmarks.ini"}, 
        {"books.txt", "./data/books.txt"}, 
        {"help", "./data/help.txt"}, 
        {"menu", "./data/menu.txt"}, 
        {"settings", "./data/settings.ini"}
    };

    bool chk_files = check_dirs_and_files(data_files);

    if (!chk_files)
    {
        std::cerr << "Erreur, fichier de configuration manquant!" << std::endl;
    }
    else{
        std::cout << "Init OK!" << std::endl;
    }
}

bool AppInit::check_dirs_and_files(const std::map<std::string, std::string> &df)
{
    int ctrl = 0;
    std::map<std::string, std::string>::const_iterator it;
    
    for (it = df.begin(); it != df.end(); it++)
    {
        if (std::filesystem::exists(it->second))
        {
            ctrl += 1;
        }
    }

    if (ctrl == 6)
    {
        return true;
    }
    else
    {
        return false;
    }
}

AppInit::~AppInit(){}
