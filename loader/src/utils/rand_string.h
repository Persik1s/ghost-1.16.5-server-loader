#ifndef RAMDSTRING
#define RNADSTRING
#include <stdlib.h>
#include <time.h>
#include <string>
std::string rand_string(int size){ 
    char symbols[] = {'A','B','C','D','E','F','G','H','I','1','2','3','4','5','6','7'};
    srand(time(NULL)); 
    std::string string;
    

    for(int i = 0; i < size ;i++)
       string += symbols[rand() % 16];
    return string;
}

#endif 