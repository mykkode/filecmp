# FILECMP

Filecmp is a library which compares two files. It will return either TRUE if the files are identical or FALSE if they are not.

## Installing

There are 2 ways to install this library.

### 1st way

1. Copy one-file/filecmp.cpp to your project directory
2. Include the library with: *#include "filecmp.cpp"*

### 2nd way - using makefile

1. You copy include/filecmp.cpp and include/filecmp.hpp to your project directory
2. Include the library header with: *#include "filecmp.hpp"*
3. Write the makefile and save it with the name makefile, here's a simple example:

```
all: filecmp.o main.o
	g++ main.o filecmp.o -o main

filecmp.o: filecmp.cpp
	g++ -c filecmp.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	-rm main;
	-rm *.o;
```
4. Execute in directory: *make*
5. If everything works you should have your executable named main :)

## How to use it?
### compareNumbers()
This method compares two files which contain numbers. 
WARNING: the two files MUST only contain numbers (INTEGERS) and no other letter or character (except blank spaces and newlines).

1. Create the object:
```
    filecmp files("file_1_name", "file_2_name");
```

2. Call the method (in this case we output the result):
```
    std::cout << files.compareNumbers();
```
Example of code: 
```
#include "filecmp.hpp" // change .cpp if you install the one-file library

int main(){
    filecmp files("file_1_name", "file_2_name");

    std::cout << files.compareNumbers();
};
```
TESTS:
```
file_1_name:
1 2 3
file_2_name:
1 2 3
output:
1
```
```
file_1_name:
1   2   3

file_2_name:
1 2 3
output:
1
```
```
file_1_name:
1
2
3
file_2_name:
1 2 3
output:
1
```
```
file_1_name:
1 2 3 4
file_2_name:
1 2 3
output:
0
```
### compareCharacters()

This method compares two files which contains characters. 
WARNING: it will only return TRUE if the two files are IDENTICAL (does NOT ignore blank spaces and newlines)

1. Create the object:
```
    filecmp files("file_1_name", "file_2_name");
```

2. Call the method (in this case we output the result):
```
    std::cout << files.compareNumbers();
```
Example of code: 
```
#include "filecmp.hpp" // change .cpp if you install the one-file library

int main(){
    filecmp files("file_1_name", "file_2_name");

    std::cout << files.compareCharacters();
};

```
TESTS:
```
file_1_name:
abc
file_2_name:
abc
output:
1
```
```
file_1_name:
a b c

file_2_name:
a b c
output:
1
```
```
file_1_name:
a
b
c
file_2_name:
a b c
output:
0
```
```
file_1_name:
a  b  c
file_2_name:
a b c
output:
0
```

### compareCharacters(const char * marked)

This method compares two files which contains characters. 
WARNING: it will only return TRUE if the diferences between the files are because of the characters in the marked array

1. Create the object:
```
    filecmp files("file_1_name", "file_2_name");
```

2. Call the method (in this case we output the result):
```
    std::cout << files.compareCharaters(" /n");
```
Example of code: 
```
#include "filecmp.hpp" // change .cpp if you install the one-file library

int main(){
    filecmp files("file_1_name", "file_2_name");

    std::cout << files.compareCharaters(" /n"); // if the only differences are because of the blankspaces or newlines it will return 1
};

```
TESTS:
```
file_1_name:
abc
file_2_name:
abc
output:
1
```
```
file_1_name:
abc

file_2_name:
a b c
output:
1
```
```
file_1_name:
a
b
c
file_2_name:
a b c
output:
1
```
```
file_1_name:
a  b  c
file_2_name:
a b c d
output:
0
```

## Authors

* **Nedelcescu Radu-Costin** - *Initial work* 

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details
