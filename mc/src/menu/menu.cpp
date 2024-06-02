#include "menu.h"
#include "../cheat/settings.h"

#define RGB(r,g,b) r / 255.f, g / 255.f, b / 255.f
void ImGui_Local::Menu::Start(){
    ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();
}
// setttings menu
int tab_menu = 0;


void ImGui_Local::Menu::Menu(){
    // settings 
	ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_NoMouseCursorChange;

    ImGuiStyle* style = &ImGui::GetStyle();

    style->WindowRounding = 5.5f;
    style->WindowPadding  = {0,0};
    style->Colors[ImGuiCol_WindowBg] = ImVec4(RGB(31,31,31),1.f);
    style->Colors[ImGuiCol_Border] = ImVec4(RGB(31,31,31),1.f);

    style->Colors[ImGuiCol_Button] = ImVec4(RGB(20,20,20),1.f);
    style->Colors[ImGuiCol_ButtonActive] = ImVec4(RGB(20,20,20),1.f);
    style->Colors[ImGuiCol_ButtonHovered] = ImVec4(RGB(20,20,20),1.f);

    if(ImGui_Local::Menu::is_open_menu){
        ImGui::SetNextWindowSize({400,250});

        ImGui::Begin(xorstr("OSPW"),&ImGui_Local::Menu::is_open_menu,ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar);
        	{
                ImGui::PushStyleColor(ImGuiCol_ChildBg, {RGB(20,20,20),1.0f });
			    ImGui::BeginChild("##titleBar", { 400,30 });

               
                    ImGui::SetCursorPos({ 20,5 });
                    
                    ImGui::PushFont(ImGui_Local::Menu::Font::verdana_boldtlic_font);
                    ImGui::TextColored(ImGui_Local::Menu::color_theam,xorstr("OS"));
                    ImGui::PopFont();


                    ImGui::PushFont(ImGui_Local::Menu::Font::verdana_small_font);
                    ImGui::SetCursorPos({ 65,5 });
                    if (ImGui::Button(xorstr("Combat"), { 70.f,20.f }))
                        tab_menu = 0;

                    ImGui::SetCursorPos({ 130,5 });
                    if (ImGui::Button(xorstr("Visual"), { 70.f,20.f }))
                        tab_menu = 1;

                    ImGui::SetCursorPos({ 197,5 });
                    if (ImGui::Button(xorstr("Misc"), { 70.f,20.f }))
                        tab_menu = 2;

                    ImGui::SetCursorPos({ 265,5 });
                    if (ImGui::Button(xorstr("Style"), { 70.f,20.f }))
                        tab_menu = 3;

                    // ImGui::SetCursorPos({ 335,5 });
                    // if (ImGui::Button(("Theam"), { 70.f,20.f }))
                    //     tab_menu = 4;

                    ImGui::PopFont();
                ImGui::EndChild();
                ImGui::PopStyleColor();
   
            }


       
           switch (tab_menu)
           {
            case 0:
                ImGui::SetCursorPosX(5);
                ImGui::BlockStart(xorstr("HitBox"),{ 150.f,Settings::Cheat::isHitBox? 100.f : 70.f},ImGui_Local::Menu::Font::verdana_small_font);
                
                ImGui::Checkbox_Custom(Settings::Cheat::isHitBox? xorstr("Disable").decrypt() : xorstr("Enable").decrypt(),&Settings::Cheat::isHitBox,ImGui_Local::Menu::Font::verdana_small_font);
                
                if(Settings::Cheat::isHitBox)
                    ImGui::SliderFloatCustom(xorstr("Size"),&Settings::Cheat::size_hit_box,0.3f,3.0f, "%.3f",0);
                
                ImGui::BlockEnd();

                
                ImGui::SetCursorPos({160,35});

                ImGui::BlockStart(xorstr("AimBot"),{ 150.f, Settings::Cheat::isAimBot? 130.f : 100.f},ImGui_Local::Menu::Font::verdana_small_font);
            
                ImGui::Checkbox_Custom(Settings::Cheat::isWorldTime? xorstr("Disable").decrypt() : xorstr("Enable").decrypt(),&Settings::Cheat::isAimBot,ImGui_Local::Menu::Font::verdana_small_font);
                if(Settings::Cheat::isAimBot)
                {
                    ImGui::SliderFloatCustom(xorstr("Distance"),&Settings::Cheat::distance_aim_bot,2,150, "%.3f",0);
                    ImGui::SetCursorPosY(90);
                }
                    
                    
                ImGui::Checkbox_Custom(xorstr("HUD"),&Settings::Cheat::AimBot::isHud,ImGui_Local::Menu::Font::verdana_small_font);
                
                ImGui::SetCursorPos({85,25});
                ImGui::Hotkey(" ",Settings::Cheat::AimBot::bind,{60.f,0.f});

                ImGui::BlockEnd();

                break;

            case 1:
                ImGui::SetCursorPosX(5);

                ImGui::BlockStart(xorstr("ESP"),{ 150.f, 70.f},ImGui_Local::Menu::Font::verdana_small_font);
            
                ImGui::Checkbox_Custom(xorstr("Glow Esp"),&Settings::Cheat::isGlowEsp,ImGui_Local::Menu::Font::verdana_small_font);
                
                ImGui::BlockEnd();

                ImGui::SetCursorPos({160,35});

                ImGui::BlockStart(xorstr("WorldTime"),{ 150.f, Settings::Cheat::isWorldTime? 100.f : 70.f},ImGui_Local::Menu::Font::verdana_small_font);
            
                ImGui::Checkbox_Custom(Settings::Cheat::isWorldTime? xorstr("Disable").decrypt() : xorstr("Enable").decrypt(),&Settings::Cheat::isWorldTime,ImGui_Local::Menu::Font::verdana_small_font);
                if(Settings::Cheat::isWorldTime)
                    ImGui::SliderFloatCustom(xorstr("Size"),&Settings::Cheat::time_world,0,24000, "%.3f",0);

                ImGui::BlockEnd();

                break;
            
            case 2:
                ImGui::SetCursorPosX(5);

                ImGui::BlockStart(xorstr("Auto Sprint"),{ 150.f, 70.f},ImGui_Local::Menu::Font::verdana_small_font);
            
                ImGui::Checkbox_Custom(Settings::Cheat::isSprint? xorstr("Disable").decrypt() : xorstr("Enable").decrypt(),&Settings::Cheat::isSprint,ImGui_Local::Menu::Font::verdana_small_font);
                
                ImGui::BlockEnd();
                break;
            case 3:
                ImGui::SetCursorPosX(5);

                ImGui::BlockStart(xorstr("WaterMark"),{ 150.f, 70.f},ImGui_Local::Menu::Font::verdana_small_font);
            
                ImGui::Checkbox_Custom(Settings::Cheat::isSprint? xorstr("Disable").decrypt() : xorstr("Enable").decrypt(),&Settings::Cheat::isWaterMark,ImGui_Local::Menu::Font::verdana_small_font);
                
                ImGui::BlockEnd();

                ImGui::SetCursorPos({160,35});

                ImGui::BlockStart(xorstr("ArrayList"),{ 150.f, 70.f},ImGui_Local::Menu::Font::verdana_small_font);
            
                ImGui::Checkbox_Custom(Settings::Cheat::isArrayList? xorstr("Disable").decrypt() : xorstr("Enable").decrypt(),&Settings::Cheat::isArrayList,ImGui_Local::Menu::Font::verdana_small_font);
                
                ImGui::BlockEnd();
                break;
            case 4:
                if(ImGui::Button(" ",{100.f,0.f}))
                    ImGui_Local::Menu::color_theam = ImColor(21,21,21,255);

                if(ImGui::Button("  ",{100.f,0.f}))
                    ImGui_Local::Menu::color_theam = ImColor(213,3,231,255);
           }

        ImGui::End();  
    }


   if(Settings::Cheat::isWaterMark){
            ImGui::GetForegroundDrawList()->AddText(ImGui_Local::Menu::Font::verdana_font,24,{10,22},ImColor(ImGui_Local::Menu::color_theam),"OSPW");
    }

     if(Settings::Cheat::isArrayList){
        int y = 0;
            
        if(Settings::Cheat::isWaterMark)
            y = 70;
        else
                y = 20;
            
         for(int i = 0; i < Settings::Cheat::list_module.Size();i++){
            if(!Settings::Cheat::list_module.IsBool(i))
            continue;
             ImGui::GetForegroundDrawList()->AddText(ImGui_Local::Menu::Font::verdana_font,12,{10,(float)y},ImColor(255,255,255,255),Settings::Cheat::list_module.GetName(i));
            y+= 20;
        }
    }
}

void ImGui_Local::Menu::End(){
	ImGui::EndFrame();
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hwnd, UINT uInt, WPARAM wParam, LPARAM lpParam);
LRESULT __stdcall ImGui_Local:: WndProc_Imgui(HWND hwnd, UINT uInt, WPARAM wParam, LPARAM lpParam){
    if(ImGui_ImplWin32_WndProcHandler(hwnd,uInt,wParam,lpParam))
        return TRUE;
        
    return CallWindowProcA(ImGui_Local::wndProc_process,hwnd,uInt,wParam,lpParam);
}   