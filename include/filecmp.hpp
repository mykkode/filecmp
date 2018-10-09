#ifndef FILECMP_FILECMP_HPP
#define FILECMP_FILECMP_HPP
#include <fstream>
#include <iostream>
#include <string.h>
class filecmp{
    private:
        /* the 2 files filestream */
        std::fstream file_a;
        std::fstream file_b;
        /* the array where the characters not to consider are stored */
        const char * markers;
        /* check if the character is a delimiter*/
        bool isMarked(char);
    public:
        filecmp(const char*, const char*);
        /* will return true if the files contain the same numbers spaced by ' ' or '\n' */
        bool compareNumbers();
        /* will return true if the files are the EXACT same one*/
        bool compareCharacters();
        /* will return true if the only diferences between the files are characters in markers array */
        bool compareCharacters(const char *markers);
};

#endif //FILECMP_FILECMP_HPP
