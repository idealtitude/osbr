#include <iostream>
#include <string>
#include <filesystem>

#include "biblefiles.h"

BibleFiles::BibleFiles()
{
    std::string pwd = std::filesystem::current_path();
    std::string books = "books.txt";
    const std::string books_file_path = pwd + "/" + books;
}

BibleFiles::BibleFiles(std::string fname)
{
    std::string pwd = std::filesystem::current_path();
    const std::string books_file_path = pwd + "/" + fname;
}

BibleFiles::~BibleFiles(){}
