#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <map>
#include <filesystem>

#include "../inc/biblefiles.h"

BibleFiles::BibleFiles()
{
    set_basic_vars();
}

BibleFiles::BibleFiles(std::string fname)
{
    set_basic_vars();

    // Default Bible version is "Bible à la Colombe" (COL)
    std::string book_name_path = vpaths.pwd + "/BibleDir/COL/" + fname;
}

BibleFiles::BibleFiles(std::string fname, std::string bversion)
{
    set_basic_vars();

    // Version defined by user
    std::string book_name_path = vpaths.pwd + "/BibleDir/" + bversion + "/" + fname;
}

void BibleFiles::set_basic_vars()
{
    std::string p = std::filesystem::current_path();
    std::string tmp = p + "/data/books.txt";

    vpaths.pwd = p;
    vpaths.books_file_path = tmp;
}

void BibleFiles::get_books_list()
{
    std::ifstream blist(vpaths.books_file_path);

    if (blist.is_open())
    {
        std::string line;
        int i = 1;

        while (std::getline(blist, line))
        {
            std::regex book_ptn("^([0-9]{1,2})\\s\\|\\s(.+)\\s\\|\\s([a-z0-9]+)\\s\\|\\s([0-9]+)\\s?$");
            std::smatch m;

            if (std::regex_search(line, m, book_ptn))
            {
                std::string t = m.str(4);
                int x = std::stoi(t);

                books_list[i].book_name = m.str(2);
                books_list[i].book_abr = m.str(3);
                books_list[i].chapters = x;
                i++;
            }
        }

        blist.close();
    }
    else
    {
        std::cout << "Impossible d'ouvrir " << vpaths.books_file_path << std::endl;
    }
}

BibleFiles::~BibleFiles(){}
