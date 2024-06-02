#ifndef OPENGL32
#define OPENGL32
#include "../../main/include.h"

namespace Opengl32 {
    inline WglsawpBuffer buffer;
    //inline McRender render;
   // inline GlOrtho ortho;
    bool __stdcall OriginalFunctionSwapBuffer(HDC hdc);
   // void OriginalFunctionRender(float f, float f2, float f3, float f4, int i);
    //void __stdcall OriginalFunctionGlOrtho( GLdouble left,GLdouble right,GLdouble bottom,GLdouble top,GLdouble zNear,GLdouble zFar);
}
#endif