#include <iostream>
#include <fstream>
#include <string>
#include "md5.h"

#define FILEPATH "/home/notahacker/Documents/string_search/text.txt"

int main() {
    std::ifstream file;
    std::string text;
    file.open(FILEPATH, std::ios::in);
    if(file.is_open()){
        std::string line;
        while(std::getline(file, line)){
            std::cout << line << std::endl;
        }
        file.close();
    }
    else{
        std::cerr << "Unable to open file.\n";
    }
    return 0;
}
