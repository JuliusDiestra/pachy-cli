#ifndef DATA_CONTAINERS_JOB_HPP_
#define DATA_CONTAINERS_JOB_HPP_

#include <string>
#include <vector>
#include <map>

namespace pachy {

struct Job {
    std::string name;
    std::string docker_file;
    std::vector<std::string> commands;
    std::map<std::string,std::string> vars;
};

}  // namepsace pachy

#endif // DATA_CONTAINERS_JOB_HPP_

