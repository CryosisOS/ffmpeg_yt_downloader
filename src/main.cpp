/**
 * Author: CryosisOS
 * Date Created: 2020-08-24
 * GitHub: github.com/CryosisOS
 */

#include <iostream>
#include <utility>
#include "include/argparse.hpp"
#include "include/csv.hpp"

// Argument actions.
void actions(argparse::ArgumentParser&& args) {
    if (auto url = args.present("-u")) {
        std::cout << (std::string("URL: ") + url.value()) << std::endl;
    }
    if (auto csvfile = args.present("-c")) {
        std::cout << (std::string("CSV: ") + csvfile.value()) << std::endl;
    }
}

int main(int argc, const char *argv[]) {
    argparse::ArgumentParser args{"YT Downloader"};
    args.add_argument("-u", "--url")
        .help("specifies video URL");
    args.add_argument("-c", "--csv")
        .help("specifies a CSV file to read in");

    try {
        args.parse_args(argc, argv);
        actions(std::move(args));
    } catch (const std::exception& err) {
        std::cerr << err.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "unknown error" << std::endl;
        return 1;
    }
    return 0;
}
