#include "dbg.h"

#include "../utils/find_string.h"


 Process::Process(std::vector<std::string> vec, ProcessEnum process_enum){
        this->__process_enum = process_enum;
        this->__vec = vec;
    }

bool Process::Init(){
        PROCESSENTRY32 entry = {sizeof(PROCESSENTRY32)};


        HANDLE snapShot  = LI_FN(CreateToolhelp32Snapshot)(TH32CS_SNAPPROCESS,0);
        if(!Process32First(snapShot,&entry)){
            // ...
            return FALSE;
        }
        while(LI_FN(Process32Next)(snapShot,&entry)){
            if(this->__process_enum == ProcessEnum::DLL){
                MODULEENTRY32 module_entry = { sizeof(MODULEENTRY32) };
               
                HANDLE snapShot_module = LI_FN(CreateToolhelp32Snapshot)(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32,entry.th32ProcessID);


                while(LI_FN(Module32Next)(snapShot_module,&module_entry)){
                    if(FindString(this->__vec,module_entry.szModule)){

                        return TRUE;
                    }
                        
                }

                LI_FN(CloseHandle)(snapShot_module);
            } else {
                if(FindString(this->__vec,entry.szExeFile)){
                    return TRUE;
                }
                   
            }
        }
        LI_FN(CloseHandle)(snapShot);
        return FALSE;
}

