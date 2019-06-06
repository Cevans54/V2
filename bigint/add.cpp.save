//==============================================================================
// Basics for openning a file for Part 2 of Project 1.
//
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "bigint.hpp"

int main() {
    std::ifstream in("data1-1.txt");    // Define stream for input
    if(!in) {                           // Make sure it opened correctly.
        std::cerr << "Could not open data1-1.txt, exiting." << std::endl;
        exit(1);
    }
    bigint a, b;
    
    //in >> a;
    //in >> b;

    //std::cout << "A: " << a << std::endl;
    //std::cout << "B: " << b << std::endl;

    //std::cout << a + b << std::endl;

    while (in>>a && in>>b)
    {
        std::cout << a << "\n+ " << b << "\n---------\n" << a+b << "\n" << std::endl;
    }

    in.close();
    return 0;

}

