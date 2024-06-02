#include "include.h"
#include "../dll/dll.h"
#include "../system/system.h"
#include "../utils/crypt/crypt.h"
bool load = FALSE;
bool MainThraed(HMODULE hModule){
#ifdef _WIN32
    #ifdef _WIN64
        // if(!System::File::IsFile(xorstr("C:\\key.txt")))
        //     return 0;
        // std::string key = System::File::ReadString(xorstr("C:\\key.txt"));
        // std::string responeKey  = decode(System::Web::DecodeRequest(System::Web::Get(xorstr("176.215.254.123"), ((const char*)xorstr("key/") + key + (const char*)xorstr("/")+ decode(System::GetHwid().c_str())).c_str()    ,2000)).c_str());    
        // if(strstr(responeKey.c_str(),xorstr("ENTRANCE"))){
            AllocConsole();
            freopen("CONOUT$","w",stdout);
            
            do {
                if(!load){
                    Dll::Load();
                    
                    load = TRUE;
                }
            } while(!GetAsyncKeyState(VK_DELETE) & 1);


            Dll::UnLoad();

            FreeLibraryAndExitThread(hModule,-1);
            return FALSE;
        //}
        DeleteFileA(xorstr("C:\\key.txt"));
        return FALSE;
    #else
        return FALSE;
    #endif
#else 
    return FALSE;
#endif

}


BOOL WINAPI DllMain(HINSTANCE hInstance,DWORD dword,LPVOID lpVoid){
    switch (dword)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(0,0,(LPTHREAD_START_ROUTINE)MainThraed,0,0,0);
        
        CreateThread(0,0,(LPTHREAD_START_ROUTINE)Dll::InitBind,0,0,0);
    }
    return TRUE;
}