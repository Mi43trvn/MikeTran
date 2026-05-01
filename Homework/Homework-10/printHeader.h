#ifndef PRINTHEADER_H
#define PRINTHEADER_H

#include <iostream>
#include <string>

inline void printHeader(const std::string& title) {
    std::cout << "==============================" << std::endl;
    std::cout << "        " << title << std::endl;
    std::cout << "==============================" << std::endl;
}

#endif
