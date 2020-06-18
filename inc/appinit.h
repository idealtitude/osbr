#ifndef APPINIT_H
#define APPINIT_H

class AppInit
{
  public:
    AppInit();
    ~AppInit();

  private:
    // Attrs
    const std::map<std::string, std::string> data_files;

    // Meths
    bool check_dirs_and_files(const std::map<std::string, std::string> &df);
};

#endif
