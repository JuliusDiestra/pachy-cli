
#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <iostream>
#include <string>
#include <vector>
#include "job.hpp"
#include "yaml_interface.hpp"
#include "file_handler.hpp"

class Parser {
  public:
    explicit Parser(std::string file_path);
    ~Parser();
    bool Run();
  private:
    FileHandler file_handler_;
    YamlInterface yaml_interface_;
    std::string file_path_;
    std::vector<Job> jobs_;
};

#endif // PARSER_HPP_
