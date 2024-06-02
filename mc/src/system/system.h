#ifndef SOCKET_F
#define SOCKET_F
#include "../main/include.h"
namespace System {
    namespace Web {
        std::string Get(const char* ip,const char* name,int port);
        std::string DecodeRequest(std::string req);
    }
    namespace File {
        std::string ReadString(const char* nameFile);
        bool IsFile(const char* name);
    }
    std::string GetHwid();
}
#endif
