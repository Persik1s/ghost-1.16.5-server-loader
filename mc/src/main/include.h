#define _CRT_SECURE_NO_WARNINGS

#include <winsock.h>
#include <unordered_map>
#include <windows.h>
#include <vector> 
#include <string>

#include <GL/gl.h>
#include <GL/glu.h>

// GLM 
#include "../complement/glm/gtc/type_ptr.hpp"
#include "../complement/glm/glm.hpp"

#include <math.h>

#include <iostream>

//Java Developer Kit include
#include "../complement/java/jdk/include/jni.h"
#include "../complement/java/jdk/include/win32/jni_md.h"
#include "../utils/xorstr.h"

#define MINECRAFT_VERSION 1

#pragma comment(lib,"ws2_32.lib")
#pragma comment(lib,"opengl32.lib")
#pragma comment(lib, "glu32.lib")


typedef int (
    __stdcall* WglsawpBuffer
)(HDC hdc);

//typedef void(__stdcall* McRender)(float f, float f2, float f3, float f4, int i);
//typedef void(__stdcall* GlOrtho)(GLdouble left,GLdouble right,GLdouble bottom,GLdouble top,GLdouble zNear,GLdouble zFar);