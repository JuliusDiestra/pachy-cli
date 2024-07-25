
#include "parser.hpp"
#include "job.hpp"

Parser::Parser(std::string file_path) :
    file_path_{file_path},
    file_handler_{file_path},
    yaml_interface_{file_handler_.GetFile()} {
}

Parser::~Parser() {
}

bool Parser::Run() {
    bool status{true};
    yaml_interface_.ScanFile(jobs_);
    std::cout << "file name: " << file_path_ << "\n";
    std::cout << "Jobs : " << jobs_.size() << "\n";
    return status;
}

