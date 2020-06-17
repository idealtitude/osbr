#include <iostream>
#include <string>

#include "../inc/filereader.h"

FileReader::FileReader()
{
    std::string file_name = "menu.txt";
}

FileReader::FileReader(std::string fname)
{
    std::string file_name = fname;
}

FileReader::~FileReader(){}
