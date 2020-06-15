#ifndef BIBLEMENU_H
#define BIBLEMENU_H

class BibleMenu
{
    public:
        BibleMenu();
        ~BibleMenu();

        void show_menu();

    private:
        struct menu_paths
        {
            // Working DIR
            std::string pwd;

            // Menu file path
            std::string menu_file_path;
        } mpaths;
};

#endif
