#ifndef BIBLEFILES_H
#define BIBLEFILES_H

class BibleFiles
{
  public:
    // Default constructor, display Bible menu
    BibleFiles();

    // Constructor with a Bible book defined
    BibleFiles(std::string fname);

    // Constructor with a Bible book defined and
    // a Bible version defined
    BibleFiles(std::string fname, std::string bversion);

    // Destructor
    ~BibleFiles();

    struct var_paths
    {
        // Working DIR
        std::string pwd;

        // Books menu file path
        std::string books_file_path;
    } vpaths;

    // Path to selected Bible book
    std::string book_name_path;

    // Struct books list data
    struct books_data
    {
        std::string book_name;
        std::string book_abr;
        int chapters;
    };

    // Bible bboks books_list
    std::map<int, books_data> books_list;

    // Get Bible books list
    void get_books_list();

  private:
    void set_basic_vars();
};

#endif
