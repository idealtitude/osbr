#ifndef BIBLEFILES_H
#define BIBLEFILES_H

class BibleFiles
{
  public:
    BibleFiles();
    BibleFiles(std::string fname);
    ~BibleFiles();

private:
    const std::string pwd;
    const std::string books_file_path;
};

#endif
