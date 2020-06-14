#include <iostream>
#include <fstream>
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
        int i = 0;

        while (std::getline(blist, line))
        {
            books_list[i] = line;
            i++;
        }

        blist.close();
    }
    else
    {
        std::cout << "Impossible d'ouvrir " << vpaths.books_file_path << std::endl;
    }
}

BibleFiles::~BibleFiles(){}
