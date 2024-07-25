#ifndef YAML_INTERFACE_HPP_
#define YAML_INTERFACE_HPP_

#include "yaml.h"
#include <string>
#include <vector>
#include "job.hpp"

class YamlInterface {
  public:
    YamlInterface(FILE& file);
    ~YamlInterface();
    bool ScanFile(const std::vector<Job>& jobs);
    bool UpdateEvent();
    bool IsDone();
    std::string ScalarToString();
    void PrintEvent() const;
  private:
    yaml_parser_t yaml_parser_;
    yaml_event_t yaml_event_;
};

#endif // YAML_INTERFACE_HPP_
