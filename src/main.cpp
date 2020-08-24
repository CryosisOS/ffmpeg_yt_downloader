/**
 * Author: CryosisOS
 * Date Created: 2020-08-24
 * GitHub: github.com/CryosisOS
 */

#include <iostream>
#include <utility>
#include "include/argparse.hpp"

void actions(argparse::ArgumentParser&& args) {
    if (auto url = args.present("-u")) {
        std::cout << (std::string("URL: ") + url.value()) << std::endl;
    }
}

int main(int argc, const char *argv[]) {
    argparse::ArgumentParser args{"YT Downloader"};
    args.add_argument("-u", "--url")
        .help("specifies video URL");

    try {
        args.parse_args(argc, argv);
        actions(std::move(args));
    } catch (const std::runtime_error& err) {
        std::cerr << err.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "ERROR" << std::endl;
        return 1;
    }
    return 0;
}
