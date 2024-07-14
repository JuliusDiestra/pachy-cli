
#include "pachy.hpp"

namespace pachy {

Pachy::Pachy(const int& argc, char* argv[]) : arg_parser_{argc, argv}, runner_{} {}

int Pachy::Execute() {
    if (arg_parser_.IsHelp()) {
        return 0;
    }
    if (arg_parser_.IsVersion()) {
        return 0;
    }
    arg_parser_.Validate();
    runner_ = std::make_unique<pachy::Runner>();
    return runner_->Execute(arg_parser_.GetArguments());
}

}  // namespace pachy

