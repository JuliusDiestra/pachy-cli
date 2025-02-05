
#include "pachy.hpp"

int main(int argc, char* argv[]) {
    // Store arguments in a vector
    std::vector<std::string> input_args;
    for (auto j = 1; j < argc; ++j) {
        input_args.push_back(argv[j]);
    }
    // Execute pachy
    pachy::Pachy pachy(input_args);
    return pachy.execute();
}

