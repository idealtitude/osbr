#ifndef FILEREADER_H
#define FILEREADER_H

class FileReader
{
  public:
    FileReader();
    FileReader(std::string fname);
    ~FileReader();

  private:
    std::string file_name;
};

#endif
