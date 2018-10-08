//
// Created by mykkode on 04.10.2018.
//

#ifndef FILECMP_FILECMP_HPP
#define FILECMP_FILECMP_HPP
#include <fstream>
#include <iostream>
#include <string.h>
class filecmp{
    private:
        std::fstream file_a;
        std::fstream file_b;
        char getCharFromFile();
    public:
        filecmp(char*, char*);
        /* will return true if the files contain the same numbers spaced by ' ' or '\n' */
        bool compareNumbers();
        /* will return true if the only diferences between the files are in the given array */
        bool compareCharactersDelimiters(char *);
        /* will return true if the files are the EXACT same one*/
        bool compareCharactersExact();
};

#endif //FILECMP_FILECMP_HPP
