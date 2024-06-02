#ifndef SYSTEM_CLASS
#define SYSTEM_CLASS
#include "../include.h"
namespace System { 
    namespace Web { 
        std::string Get(const char* ip,const char* name,int port);
        std::string DecodeRequest(std::string req);
    }
    
    namespace File {
        std::string ReadString(const char* nameFile);
        bool IsFile(const char* name);
        void CFile(const char* name);
        bool WriteString(const char* name,const char* );
    }
 

    namespace Process {
        bool Inecjet(std::string nameProcess );
    }
    std::string GetHwid();
}
#endif