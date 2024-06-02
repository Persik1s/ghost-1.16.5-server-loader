#include "../include.h"

#ifndef PROCESS
#define PROCESS

enum class ProcessEnum {
    DLL,
    NAME
};

class Process {    
private:
    std::vector<std::string> __vec; 
    ProcessEnum __process_enum;
public:
    Process(std::vector<std::string> vec, ProcessEnum process_enum);
    bool Init();
};



#endif

                    