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

    // Working DIR
    const std::string pwd;

    // Books menu file path
    const std::string books_file_path;

    // Path to selected Bible book
    std::string book_name_path;
};

#endif
