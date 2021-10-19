#include <iostream>
#include <string>
#include "md5.h"

int main() {
    std::string toHash("Hi, this is a sample string.");
    std::cout << "Sample string : " << toHash << "\nHashed: ";
    std::cout << md5(toHash) << "\n";
    return 0;
}
