#ifndef BIBLE_H
#define BIBLE_H

class Bible
{
  public:
    Bible();
    Bible(std::string r);
    ~Bible();

    bool format_ok;

    struct aRef {
        std::string book;
        std::string chapter;
        std::string verse;
    } sref;

  private:
    std::string ref;

    bool check_ref_format();
};

#endif
