
#ifndef YAML_PARSER_YAML_PARSER_HPP_
#define YAML_PARSER_YAML_PARSER_HPP_

#include <string>
#include <vector>

#include "pachy/error_handling/status_code.hpp"
#include "file_system_handler.hpp"
//#include "job.hpp"
//#include "yaml_interface.hpp"
//#include "file_handler.hpp"

namespace pachy {

class YamlParser {
  public:
    explicit YamlParser();
    StatusCode parse();
  private:
    FileSystemHandler file_system_handler_;
    //FileHandler file_handler_;
    //YamlInterface yaml_interface_;
    std::string file_path_;
    //std::vector<Job> jobs_;
};

}  // namespace pachy

#endif // YAML_PARSER_YAML_PARSER_HPP_
