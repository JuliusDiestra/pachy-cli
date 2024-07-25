



#include "parser.hpp"

int main(int argc, char* argv[]) {
    if (argc < 1) {
        std::cout << "Argument needed" << "\n";
        return 1;
    }
    std::string file_name{argv[1]};
    Parser parser{file_name};
    parser.Run();

    return 0;
}
