#include <iostream> 
#include "math/crypt.h"
#include "dbg/dbg.h"

#include "utils/rand_string.h"
#include "utils/system.h"
#include "math/crypt.h"
#include "utils/xorstr.h"



int main(int argc, char *argv[]){
#ifdef _WIN32
    #ifdef _WIN64
        std::vector<std::string> vec_dll = {
            //IDA
            (const char*)xorstr("ida64.dll"),

            //HttpDebuger
            (const char*)xorstr("HTTPDebuggerBrowser.dll"),
            (const char*)xorstr("cximagecrt.dll"),
            (const char*)xorstr("Office2016.dll"),

            //ProcessHacker
            (const char*)xorstr("ExtendedNotifications.dll"),
            (const char*)xorstr("ExtendedTools.dll"),
            (const char*)xorstr("ExtendedServices.dll"),
            (const char*)xorstr("DotNetTools.dll"),

            //dbg
            (const char*)xorstr("x64bridge.dll"),
            (const char*)xorstr("x64dbg.dll"),
            (const char*)xorstr("x64gui.dll"),

            (const char*)xorstr("x32bridge.dll"),
            (const char*)xorstr("x32dbg.dll"),
            (const char*)xorstr("x32gui.dll"),
        };

        std::vector<std::string> vec_process = {
            (const char*)xorstr("ida64.exe"),
            (const char*)xorstr("ProcessHacker.exe"),
            (const char*)xorstr("HTTPDebuggerUI.exe"),
            (const char*)xorstr("HTTPDebuggerSvc.exe"),
            (const char*)xorstr("cheatengine-x86_64.exe"),
            (const char*)xorstr("x64dbg.exe"),
            (const char*)xorstr("x32dbg.exe"),

        };


        Process(vec_dll,ProcessEnum::DLL).Init();
        Process(vec_process,ProcessEnum::NAME).Init();

        if(LI_FN(IsDebuggerPresent)()){
            return 0;
        }

    
        LI_FN(SetConsoleTitleA)(rand_string(12).c_str());
        std::string responeHwid  = decode(System::Web::DecodeRequest(System::Web::Get(xorstr("127.0.0.1"), ((const char*)xorstr("status/") + decode(System::GetHwid().c_str())).c_str()    ,2000)).c_str());
        if(strstr(responeHwid.c_str(),xorstr("TRUE"))){
            return 0;
        }

        std::cout << xorstr("        OOOOOOOOO        SSSSSSSSSSSSSSS PPPPPPPPPPPPPPPPP   WWWWWWWW                           WWWWWWWW") << std::endl;
        std::cout << xorstr("      OO:::::::::OO    SS:::::::::::::::SP::::::::::::::::P  W::::::W                           W::::::W") << std::endl;
        std::cout << xorstr("    OO:::::::::::::OO S:::::SSSSSS::::::SP::::::PPPPPP:::::P W::::::W                           W::::::W") << std::endl;
        std::cout << xorstr("   O:::::::OOO:::::::OS:::::S     SSSSSSSPP:::::P     P:::::PW::::::W                           W::::::W") << std::endl;
        std::cout << xorstr("   O::::::O   O::::::OS:::::S              P::::P     P:::::P W:::::W           WWWWW           W:::::W ") << std::endl;
        std::cout << xorstr("   O:::::O     O:::::OS:::::S              P::::P     P:::::P  W:::::W         W:::::W         W:::::W  ") << std::endl;
        std::cout << xorstr("   O:::::O     O:::::O S::::SSSS           P::::PPPPPP:::::P    W:::::W       W:::::::W       W:::::W   ") << std::endl;
        std::cout << xorstr("   O:::::O     O:::::O  SS::::::SSSSS      P:::::::::::::PP      W:::::W     W:::::::::W     W:::::W    ") << std::endl;
        std::cout << xorstr("   O:::::O     O:::::O    SSS::::::::SS    P::::PPPPPPPPP         W:::::W   W:::::W:::::W   W:::::W     ") << std::endl;
        std::cout << xorstr("   O:::::O     O:::::O       SSSSSS::::S   P::::P                  W:::::W W:::::W W:::::W W:::::W      ") << std::endl;
        std::cout << xorstr("   O:::::O     O:::::O            S:::::S  P::::P                   W:::::W:::::W   W:::::W:::::W      ") << std::endl;
        std::cout << xorstr("   O::::::O   O::::::O            S:::::S  P::::P                    W:::::::::W     W:::::::::W        ") << std::endl;
        std::cout << xorstr("   O:::::::OOO:::::::OSSSSSSS     S:::::SPP::::::PP                   W:::::::W       W:::::::W         ") << std::endl;
        std::cout << xorstr("   OO:::::::::::::OO S::::::SSSSSS:::::SP::::::::P                    W:::::W         W:::::W          ") << std::endl;
        std::cout << xorstr("      OO:::::::::OO   S:::::::::::::::SS P::::::::P                     W:::W           W:::W           ") << std::endl;
        std::cout << xorstr("        OOOOOOOOO      SSSSSSSSSSSSSSS   PPPPPPPPPP                      WWW             WWW            ") << std::endl;

        bool status = System::File::IsFile(xorstr("C:\\key.txt"));
        switch (status)
        {
            case 0:
            {
                std::string key;
                std::cout << xorstr("\n\n\n[KEY] >> ");
                std::cin>>key;
                std::string responeKey  = decode(System::Web::DecodeRequest(System::Web::Get(xorstr("127.0.0.1"), ((const char*)xorstr("key/") + key + (const char*)xorstr("/")+ decode(System::GetHwid().c_str())).c_str()    ,2000)).c_str());    
                if(strstr(responeKey.c_str(),xorstr("ENTRANCE").decrypt())){
                    System::File::CFile(xorstr("C:\\key.txt"));
                    System::File::WriteString(xorstr("C:\\key.txt"),key.c_str());
                    System::Process::Inecjet(xorstr("javaw.exe").decrypt());
                }
                break;
            }
            case 1:
            {
                std::string readKey = System::File::ReadString(xorstr("C:\\key.txt"));
                std::string responeKey =  decode(System::Web::DecodeRequest(System::Web::Get(xorstr("127.0.0.1"),((const char*)xorstr("key/") + readKey + (const char*)xorstr("/") + decode(System::GetHwid().c_str())).c_str()   ,2000)).c_str());
                if(strstr(responeKey.c_str(),xorstr("ENTRANCE"))){
                    System::Process::Inecjet(xorstr("javaw.exe").decrypt());
                    break;
                }
                DeleteFileA(xorstr("C:\\key.txt"));
                break;
            }
           
        }

      
        return 0;

    #else 
        return 0;
    #endif

#else
    return 0;
#endif  
   
}