/**
 * Author: CryosisOS
 * Date Created: 2020-08-24
 * GitHub: github.com/CryosisOS
 */

#include "include/argparse.hpp"

int main(int argc, const char *argv[]) {
    argparse::ArgumentParser args{"YT Downloader"};
    try {
        args.parse_args(argc, argv);
    } catch (const std::runtime_error& err) {
        std::cout << err.what() << std::endl;
    }
    return 0;
}
