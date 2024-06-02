#ifndef FIND_STRING
#define FIND_STRING
#include "../include.h"

bool FindString(std::vector<std::string> vec,const char* str){
    for(int i = 0;i < vec.size(); i++){
        if(strstr(str, vec[i].c_str()))
            return TRUE;
    }
    return FALSE;
}

#endif