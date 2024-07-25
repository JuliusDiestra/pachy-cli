#ifndef JOB_HPP_
#define JOB_HPP_

#include <string>

struct Job {
    std::string name;
    std::string dockerfile;
    std::vector<std::string> run;
};

#endif // JOB_HPP_
