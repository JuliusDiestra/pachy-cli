
#ifndef FILE_HANDLER_HPP_
#define FILE_HANDLER_HPP_

#include <cstdio>
#include <string>

class FileHandler {
  public:
    FileHandler(std::string file_path);
    ~FileHandler();
    FILE& GetFile();
  private:
    FILE* file_;
};

#endif // FILE_HANDLER_HPP_
