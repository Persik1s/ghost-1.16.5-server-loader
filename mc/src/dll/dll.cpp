#include "dll.h"
#include "../menu/menu.h"
#include "../main/jni.h"
#include "hook/opengl32.h"

#include "../complement/minhook/MinHook.h"
#include "../classes/minecraft/minecraft.h"
#include "../cheat/settings.h"

bool InitJVM();
bool InitHook();
BOOL __stdcall EnumWindowCallBack(HWND hwnd,LPARAM lp);


JNI_T* jni_mc;

bool Dll::Load(){
    EnumWindows((WNDENUMPROC)EnumWindowCallBack,0);
    ImGui_Local::wndProc_process = (WNDPROC)SetWindowLongPtrW(Dll::hwnd_local_window, GWLP_WNDPROC,(LONG_PTR)ImGui_Local::WndProc_Imgui);

    if(!InitHook())
        return FALSE;

    return TRUE;
}

bool Dll::UnLoad(){
    if(jni_mc != NULL)
        free(jni_mc);

    Dll::UnLoad_b = !Dll::UnLoad_b;
    Sleep(1000);
    MH_DisableHook(MH_ALL_HOOKS);
    
    return TRUE;
}


BOOL __stdcall EnumWindowCallBack(HWND hwnd,LPARAM lp){
    int size = GetWindowTextLengthA(hwnd);
    if(size == NULL)    
        return TRUE;

    std::string name_window;
    name_window.reserve(size);

    GetWindowTextA(hwnd,name_window.data(),size + 1);
    if(strstr(name_window.c_str(),"Minecraft* 1.16.5") || strstr(name_window.c_str(),"Minecraft 1.16.5 | LabyMod")){
        Dll::hwnd_local_window = hwnd;
        Dll::number_window  =  0;
        return TRUE;
    }

    if(strstr(name_window.c_str(),"Minecraft 1.16.5")){
        Dll::hwnd_local_window = hwnd;
        Dll::number_window  =  1;
        return TRUE;
    }
   
    return TRUE;
}

bool InitHook(){
    if(MH_Initialize() != MH_OK)
        return FALSE;

    void* point_swapBuffer = (void*)GetProcAddress(GetModuleHandleA("Gdi32.dll"),"SwapBuffers");
    
    if(MH_CreateHook(point_swapBuffer,&Opengl32::OriginalFunctionSwapBuffer,(LPVOID*)&Opengl32::buffer) != MH_OK)
        return FALSE;

    if(MH_EnableHook(point_swapBuffer) != MH_OK)    
        return FALSE;

    // if(MH_CreateHook(Dll::point_renader_hook,&Opengl32::OriginalFunctionRender,(LPVOID*)&Opengl32::render) != MH_OK)
    //     return FALSE;

    // if(MH_EnableHook(Dll::point_renader_hook) != MH_OK)    
    //     return FALSE;
    // void* point_glortho = (void*)GetProcAddress(GetModuleHandleA("opengl32.dll"),"glOrtho");

    // if(MH_CreateHook(point_glortho,&Opengl32::OriginalFunctionGlOrtho,(LPVOID*)&Opengl32::ortho) != MH_OK)
    //     return FALSE;

    // if(MH_EnableHook(point_glortho) != MH_OK)    
    //     return FALSE;
    return TRUE;
}












bool Dll::InitBind(){
    while(1){
        if(GetAsyncKeyState(VK_INSERT) & 1)
            ImGui_Local::Menu::is_open_menu = ! ImGui_Local::Menu::is_open_menu;
        if(GetAsyncKeyState(Settings::Cheat::AimBot::bind) & 1)
            Settings::Cheat::isAimBot = !Settings::Cheat::isAimBot;
    }
    
    return FALSE;
}



