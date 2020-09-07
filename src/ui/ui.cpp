/**
 * Author: CryosisOS
 * Date Created: 2020-08-24
 * GitHub: github.com/CryosisOS
 */

//Linked Header Import
#include "ui.hpp"

//Library Imports
#include <fstream>
#include <iostream>

//Project Imports


bool validateCSVFileName(const std::string& filename){
    std::ifstream file;
    file.open(filename);
    if(!file)
        return false;
    file.close();
    return true;
}
