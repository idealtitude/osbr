#include <iostream>
#include <string>
#include <filesystem>

#include "../inc/biblefiles.h"

BibleFiles::BibleFiles()
{
    const std::string pwd = std::filesystem::current_path();

    std::string books_menu = "books.txt";

    const std::string books_file_path = pwd + "/" + books_menu;
}

BibleFiles::BibleFiles(std::string fname)
{
    const std::string pwd = std::filesystem::current_path();

    std::string books_menu = "books.txt";

    const std::string books_file_path = pwd + "/" + books_menu;

    // Default Bible version is "Bible à la Colombe" (COL)
    std::string book_name__path = pwd + "/BibleDir/COL/" + fname;
}

BibleFiles::BibleFiles(std::string fname, std::string bversion)
{
    const std::string pwd = std::filesystem::current_path();

    std::string books_menu = "books.txt";

    const std::string books_file_path = pwd + "/" + books_menu;

    std::string book_name__path = pwd + "/BibleDir/" + bversion + "/" + fname;
}

BibleFiles::~BibleFiles(){}
