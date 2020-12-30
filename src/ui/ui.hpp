/**
 * Author: CryosisOS
 * Date Created: 2020-08-24
 * GitHub: github.com/CryosisOS
 */

#pragma once

//Library Imports
#include <fstream>
#include <vector>
#include <string>

//Project Imports

inline bool check_file(const std::string& filename) {
    std::ifstream f{filename};
    return f.good();
}
