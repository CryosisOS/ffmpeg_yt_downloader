/**
 * Author: CryosisOS
 * Date Created: 2020-08-24
 * GitHub: github.com/CryosisOS
 */

#include <iostream>
#include "include/argparse.hpp"

int main(int argc, const char *argv[]) {
    argparse::ArgumentParser args{"YT Downloader"};
    try {
        args.parse_args(argc, argv);
    } catch (const std::runtime_error& err) {
        std::cerr << err.what() << std::endl;
    } catch (...) {
        std::cerr << "ERROR" << std::endl;
    }
    return 0;
}
