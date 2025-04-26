#ifndef YAML_PARSER_FILE_HANDLER_HPP_
#define YAML_PARSER_FILE_HANDLER_HPP_

#include <yaml.h>
#include "pachy/data_containers/data.hpp"

namespace pachy {

class FileParser {
  public:
    FileParser();
    StatusReturn<Data> parse(FILE& file);
  private:
    yaml_parser_t yaml_parser_;
    yaml_event_t yaml_event_;
};

}  // namespace pachy

#endif // YAML_PARSER_FILE_HANDLER_HPP_
