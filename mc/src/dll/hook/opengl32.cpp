#include "opengl32.h"
#include "../../menu/menu.h"
#include "../dll.h"
#include "../../classes/minecraft/world/world.h"
#include "../../menu/font.h"
#include "../../cheat/cheat.h"


bool __stdcall Opengl32::OriginalFunctionSwapBuffer(HDC hdc){
    if(!ImGui_Local::init_imgui){
        jni_mc = (JNI_T*)malloc(sizeof(JNI_T));

        if(JNI_GetCreatedJavaVMs(&jni_mc->vm,1,0) != JNI_OK)
            return FALSE;
            
        jni_mc->vm->AttachCurrentThread((void**)&jni_mc->env,0);
        ImGui::CreateContext();
		ImGui::StyleColorsDark();
		ImGui_ImplWin32_Init(Dll::hwnd_local_window);
		ImGui_ImplOpenGL3_Init();
			
		ImGuiIO& io = ImGui::GetIO(); (void)io;

        io.Fonts->AddFontFromMemoryTTF(font_verdana_mem,sizeof(font_verdana_mem),10);
        ImGui_Local::Menu::Font::verdana_font = io.Fonts->AddFontFromMemoryTTF(font_verdana_mem,sizeof(font_verdana_mem),15);

        io.Fonts->AddFontFromMemoryTTF(font_verdana_small_mem,sizeof(font_verdana_small_mem),10);
        ImGui_Local::Menu::Font::verdana_small_font = io.Fonts->AddFontFromMemoryTTF(font_verdana_small_mem,sizeof(font_verdana_small_mem),15);

        io.Fonts->AddFontFromMemoryTTF(font_verdana_boldtalic,sizeof(font_verdana_boldtalic),10);
        ImGui_Local::Menu::Font::verdana_boldtlic_font = io.Fonts->AddFontFromMemoryTTF(font_verdana_boldtalic,sizeof(font_verdana_boldtalic),19);

        ImGui_Local::init_imgui = TRUE;


    }
    ImGui_Local::Menu::Start();
    //init menu
    ImGui_Local::Menu::Menu();

    Cheat::start();
    
    ImGui_Local::Menu::End();

    


    return Opengl32::buffer(hdc);
}


