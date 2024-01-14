//
// Created by Aiden Pratt on 1/11/24.
//

#include <iostream>
#include "cmdline.hpp"


void use_arguments(int argc, char **argv) {
    int length = argc;
    bool testFlag = false;

    for (int i = 1; i < length; i++) {
        std::string argumentV = argv[i];

        if (argumentV.compare("--help") == 0) {
            std::cout << "here is help\n";
            exit(0);
        }
        if(argumentV.compare("--test") == 0) {
            if (!testFlag) {
                std::cout << "tests passed\n";
                testFlag = true;
            }else{
                std::cerr << "error: --tests already seen\n";
                exit(1);
            }
        }
        else{
            std::cerr << "error: bad flag\n";
            exit(1);
        }
    }

}