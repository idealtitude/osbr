#include <iostream>
#include <regex>
#include <string>

#include "biblib.h"

Bible::Bible()
{
    ref = "";
    sref.book = "nil";
    sref.chapter = "nil";
    sref.verse = "nil";
}

Bible::Bible(std::string r)
{
    ref = r;

    if (check_ref_format())
    {
        format_ok = true;
    }
    else
    {
        format_ok = false;
    }
}

bool Bible::check_ref_format()
{
    std::regex ref_ptn("^([123]?[a-zA-Z]{1,3})(-[0-9]+)?(-[0-9]+)?$");
    std::smatch m;

    if (std::regex_search(ref, m, ref_ptn))
    {
        sref.book = m.str(1);

        if (sref.chapter.length() > 0)
        {
            std::string tmp_chapter = m.str(2);
            sref.chapter = tmp_chapter.erase(0, 1);
        }
        else
        {
            sref.chapter = "0";
        }

        if (sref.chapter.length() > 0)
        {
            std::string tmp_verse = m.str(3);
            sref.verse = tmp_verse.erase(0, 1);
        }
        else
        {
            sref.verse = "0";
        }

        return true;
    }
    else
    {
        return false;
    }
}

Bible::~Bible(){}
