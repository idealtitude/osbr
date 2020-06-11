#include <iostream>
#include <string>

#include "biblib.h"
#include "biblefiles.h"

int main(int argc, char **argv)
{
    std::string bp = "books.txt";

    BibleFiles bfiles1;
    BibleFiles bfiles2(bp);

    if (argc == 1)
    {
        //Bible bible;
        std::cout << "Affichage du menu..." << std::endl;
    }
    else if (argc == 2)
    {
        std::cout << "Affichage de l'aide..." << std::endl;
    }
    else if (argc == 3)
    {
        std::string arg = argv[1];
        std::string rf = argv[2];

        if (arg == "-r" || arg == "--ref")
        {
            Bible bible(rf);

            if (bible.format_ok)
            {
                std::cout << "Livre: " << bible.sref.book << std::endl;
            }
            else
            {
                std::cout << "Référence \"" << rf << "\" non valide..." << std::endl;
            }
        }
    }

    return 0;
}
