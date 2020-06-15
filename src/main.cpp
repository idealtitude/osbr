#include <iostream>
#include <map>
#include <string>

#include "../inc/biblib.h"
#include "../inc/biblefiles.h"
#include "../inc/biblemenu.h"

void get_user_choice();

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        BibleMenu bmenu;

        bmenu.show_menu();
        get_user_choice();
    }
    else if (argc == 2)
    {
        std::string arg = argv[1];

        if (arg == "-h" || arg == "--help")
        {
            std::cout << "Affichage de l'aide..." << std::endl;
        }
        else if (arg == "-v" || arg == "--version")
        {
            std::cout << "osbr 0.1" << std::endl;
        }
        else
        {
            std::cout << "Argument inconnu, affichage de l'aide..." << std::endl;
        }
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
    else
    {
        std::cout << "Trop d'arguments... Affichage de l'aide" << std::endl;
    }

    return 0;
}

void get_user_choice()
{
    bool keep_menu = true;

    while (keep_menu)
    {
        std::cout << "\nVotre choix: ";

        std::string choice;

        getline(std::cin, choice);

        if (choice == "1")
        {
            std::cout << "\nListe des livres:" << std::endl;
            std::cout << "-----------------\n" << std::endl;

            BibleFiles bfiles;

            bfiles.get_books_list();

            for (auto const& x : bfiles.books_list)
            {
                //std::cout << x.first << " " << x.second.book_name << " " << x.second.book_abr << " " << x.second.chapters << " *** ";
                std::cout << "(" << x.first << ") " << x.second.book_name << " ~ ";
            }

            std::cout << "\n";

            while (true)
            {
                std::string book_choice;
                std::cout << "\nNuméro du livre: ";
                getline(std::cin, book_choice);

                int x = std::stoi(book_choice);

                if (x >= 1 && x <= 66)
                {
                    std::cout << "\nVous avez choisi le livre " << book_choice << std::endl;
                    break;
                }
                else
                {
                    std::cout << "Choix de livre invalide, veuillez entrer un numéro de 1 à 66." << std::endl;
                }
            }

            break;
        }
        else if (choice == "2")
        {
            std::cout << "Afficher un passage..." << std::endl;
            break;
        }
        else if (choice == "3")
        {
            std::cout << "Effectuer une recherche..." << std::endl;
            break;
        }
        else if (choice == "4")
        {
            std::cout << "Favoris..." << std::endl;
            break;
        }
        else if (choice == "5")
        {
            std::cout << "Afficher l'aide..." << std::endl;
            break;
        }
        else if (choice == "6")
        {
            std::cout << "Préférences..." << std::endl;
            break;
        }
        else if (choice == "7")
        {
            std::cout << "A propos..." << std::endl;
            break;
        }
        else if (choice == "8")
        {
            std::cout << "Quitter..." << std::endl;
            break;
        }
        else
        {
            std::cout << "Choix non valide, veuillez entrer une autre valeur..." << std::endl;
        }
    }
}
