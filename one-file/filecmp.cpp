#include <fstream>
#include <string.h>

class filecmp{
private:
    /* the 2 files filestream */
    std::fstream file_a;
    std::fstream file_b;
    /* the array where the characters not to consider are stored */
    const char * markers;
    /* check if the character is a delimiter*/
    bool isMarked(char a){
        for(int i=0;i<2;i++){
            if(a == markers[i]){
                return 1;
            }
        }
        return 0;
    };
public:
    filecmp(const char * a, const char * b){
        file_a.open(a, std::ifstream::in);
        file_b.open(b, std::ifstream::in);
    }
    /* will return true if the files contain the same numbers spaced by ' ' or '\n' */
    bool compareNumbers(){
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
    /* will return true if the files are the EXACT same one*/
    bool compareCharacters() {
        char charA, charB;

        /* we loop through the characters in file A*/
        while(file_a.get(charA)){
            if(!(file_b.get(charB))) {
                return 0;
            }
            /*if the characters are different then the files are not identical*/
            if(charA != charB){
                return 0;
            }
        }
        /*we try to read one more character from the second file*/
        if(file_b.get(charB)){
            return 0;
        }
        return 1;
    }
    /* will return true if the only diferences between the files are characters in markers array */
    bool compareCharacters(const char * localMarkers){
        markers = localMarkers;
        char charA, charB;
        /* we loop through the characters in file A*/
        while(file_a.get(charA)){
            /* the character we read previously may be the last valid character */
            bool flag = false;
            /* we check if the character is marked and if it is we look for the first non-maked character */
            while(isMarked(charA)){
                /* if we reach eof then there is no other valid character in the file */
                if (!file_a.get(charA)){
                    flag = true;
                    break;
                }
            }
            /* if file no longer has a valid character we break the loop */
            if(flag){
                break;
            }
            /*if we have less characters in file B then the files are not identical*/
            if(!(file_b.get(charB))){
                return 0;
            }
            while(isMarked(charB)){
                /* if we reach eof we break the loop */
                if (!(file_b.get(charB))){
                    return 0;
                }
            }

            /*if the characters are different then the files are not identical*/
            if(charA != charB){
                return 0;
            }
        }
        /*we try to read one more character from the second file*/
        while(file_b.get(charB)){
            /* if we have one non-marked character the second file is bigger*/
            if (!isMarked(charB)){
                return 0;
            }
        }
        /*the two files contain the exact characters*/
        return 1;
    }
};