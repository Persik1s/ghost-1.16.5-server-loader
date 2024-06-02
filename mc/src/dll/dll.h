#ifndef DLL
#define DLL 
#include <windows.h>
// INIT DLL FUNCTION
namespace Dll
{
    bool Load();   
    bool UnLoad();

    inline bool UnLoad_b = false;

    inline HWND hwnd_local_window = nullptr;
    
    // Bind
    bool InitBind();
    inline int number_window = 0;

    inline void* point_renader_hook = nullptr;

} // namespace DLL


#endif