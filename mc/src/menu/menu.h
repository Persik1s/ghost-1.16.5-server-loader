#ifndef MENU 
#define MENU

#include "../complement/imgui/imgui_impl_opengl3.h"
#include "../complement/imgui/imgui_impl_win32.h"
#include "../complement/imgui/imgui.h"
#include "../complement/imgui/imgui_internal.h"
#include "../main/include.h"

namespace ImGui_Local {
    namespace Menu
    {
        void Start();

        void Menu();
        
        void End();

        inline bool is_open_menu = FALSE;

        namespace Font {
            inline ImFont* verdana_font;
            inline ImFont* verdana_small_font;
            inline ImFont* verdana_boldtlic_font;
        }

        inline ImColor color_theam = {1,136,208,255};
        
    } // namespace Menu
    inline bool init_imgui = FALSE;
  

    inline WNDPROC wndProc_process = nullptr;
    LRESULT __stdcall WndProc_Imgui(HWND hwnd, UINT uInt, WPARAM wParam, LPARAM lpParam);
}
#endif