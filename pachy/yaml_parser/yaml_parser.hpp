
#ifndef YAML_PARSER_YAML_PARSER_HPP_
#define YAML_PARSER_YAML_PARSER_HPP_

#include "pachy/error_handling/status_code.hpp"
#include "pachy/error_handling/status_return.hpp"
#include "file_system_handler.hpp"
#include "file_handler.hpp"
#include "job.hpp"
#include "job_container.hpp"

namespace pachy {

class YamlParser {
  public:
    explicit YamlParser();
    StatusCode parse();
  private:
    FileSystemHandler file_system_handler_;
    FileHandler file_handler_;
    FileParser file_parser_;
    Data data_;
};

}  // namespace pachy

#endif // YAML_PARSER_YAML_PARSER_HPP_
