/**
 * Author: CryosisOS
 * Date Created: 2020-08-24
 * GitHub: github.com/CryosisOS
 */

//Library Imports
#include <iostream>
#include <utility>
#include <argparse/argparse.hpp>
#include <csv/csv.hpp>

//Project Imports
#include "ui/ui.hpp"
#include "ffmpeg/ffmpeg_handler.hpp"

// Argument actions.
void actions(argparse::ArgumentParser&& args) {
    if (auto url = args.present("-u")) {
        std::cout << (std::string("URL: ") + url.value()) << std::endl;
    }
    if (auto csvfile = args.present("-c")) {
        std::cout << "Checking if CSV exists:" << std::endl << "Found: ";
        std::cout << std::boolalpha << check_file(csvfile.value()) << std::endl;
    }
}

int main(int argc, const char *argv[]) {
    argparse::ArgumentParser args{"yt_downloader"};
    args.add_argument("-u", "--url")
        .help("Specifies a single YouTube Video URL or a comma seperated string of YouTube Video URLs.");
    args.add_argument("-c", "--csv")
        .help("Specifies a CSV file of YouTube Video URLs to read in.");

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
