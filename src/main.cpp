#include <iostream>
#include <map>
#include <string>

#include "../inc/biblib.h"
#include "../inc/biblefiles.h"

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        //Bible bible;
        std::cout << "Affichage du menu..." << std::endl;
        BibleFiles bfiles;

        bfiles.get_books_list();

        //std::map<int, std::string>::iterator it;

        for (auto const& x : bfiles.books_list)
        {
            //std::cout << "Livre " << it->first << ": " << it->second.book_name << std::endl;
            std::cout << x.first << " " << x.second.book_name << " " << x.second.book_abr << " " << x.second.chapters << std::endl;
        }
    }
    else if (argc == 2)
    {
        std::cout << "Affichage de l'aide..." << std::endl;
        std::cout << "... ou affichage de la version de osbr..." << std::endl;
    }
    else if (argc == 3)
    {
        std::string arg1 = argv[1];
        std::string arg2 = argv[2];

        if (arg1 == "-r" || arg1 == "--ref")
        {
            Bible bible(arg2);

            if (bible.format_ok)
            {
                std::cout << "Livre: " << bible.sref.book << std::endl;

                std::string chap;

                if (bible.sref.chapter == "nil")
                {
                    chap = "1";
                }
                else
                {
                    chap = bible.sref.chapter;
                }

                std::string bookpth = bible.sref.book + "-" + chap;
                BibleFiles bfiles(bookpth);
            }
            else
            {
                std::cout << "Référence \"" << arg2 << "\" non valide..." << std::endl;
            }
        }
    }
    else if (argc == 4)
    {
        std::cout << "Affichage de l'aide... (wrong number of args)" << std::endl;
    }
    else if (argc == 5)
    {
        std::string arg1 = argv[1];
        std::string arg2 = argv[2];
        std::string arg3 = argv[3];
        std::string arg4 = argv[4];

        if (arg1 == "-r" || arg1 == "--ref")
        {
            Bible bible(arg2);

            if (bible.format_ok)
            {
                std::cout << "Livre: " << bible.sref.book << std::endl;

                std::string chap;

                if (bible.sref.chapter == "nil")
                {
                    chap = "1";
                }
                else
                {
                    chap = bible.sref.chapter;
                }

                std::string bookpth = bible.sref.book + "-" + chap;

                if (arg3 == "-t" || arg3 == "--trd")
                {
                    // Verif Bible version (traduction)
                    if (arg4 == "COL" || arg4 == "DBY" || arg4 == "LSG")
                    {
                        BibleFiles bfiles(bookpth, arg4);
                    }
                    else
                    {
                        std::cout << "La version demandée \"" + arg4 + "\" n'est pas disponible." << std::endl;
                    }
                }
            }
            else
            {
                std::cout << "Référence \"" << arg2 << "\" non valide..." << std::endl;
            }
        }
    }

    return 0;
}
