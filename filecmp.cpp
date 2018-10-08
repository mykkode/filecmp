#include "filecmp.hpp"

filecmp::filecmp(char * a, char * b){
    file_a.open(a, std::ifstream::in);
    file_b.open(b, std::ifstream::in);
}

bool filecmp::compareNumbers(){
    int numberA, numberB;
    /*we loop through the numbers in file A*/
    while(file_a>>numberA){
        /*if we have less numbers in file B then the files are not identical*/
        if(!(file_b>>numberB)){
            return 0;
        }
        /*if the numbers are different then the files are not identical*/
        if(numberA != numberB){
            return 0;
        }
    }
    /*we try to read one more number from the second file if we can the files are not identical*/
    if(file_b>>numberB){
        return 0;
    }
    /*all the numbers are equal and there is the exact same number of numbers in the files so we return 1*/
    return 1;
}

bool filecmp::compareCharactersExact(){
    char charA, charB;
    /* we loop through the characters in file A*/
    while(file_a.get(charA)){
        /*if we have less characters in file B then the files are not identical*/
        if(!(file_b.get(charB))){
           return 0;
        }
        /*if the characters are different then the files are not identical*/
        if(charA != charB){
            return 0;
        }
    }
    /*we try to read one more character from the second file if we can the files are not identical*/
    if(file_b.get(charB)){
        return 0;
    }
    /*the two files contain the exact characters*/
    return 1;
}