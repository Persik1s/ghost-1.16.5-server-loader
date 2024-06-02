#ifndef MINECRAFT
#define MINECRAFT
#include "../../main/jni.h"
#include "world/world.h"
#include "render/render.h"
#include "render/matrixstack.h"
#include "local/local.h"
extern JNI_T* jni_mc;
namespace Minecraft
{
    inline jobject GetMinecraft(){
        jclass mc = jni_mc->FindClass("djz");
        jfieldID field_mc = jni_mc->env->GetStaticFieldID(mc,"F","Ldjz;");

        jobject field_object = jni_mc->env->GetStaticObjectField(mc,field_mc);

        jni_mc->env->DeleteLocalRef(mc);
        
        return field_object;
    }
    inline Vector2 WindowSize(){
        jclass mc = jni_mc->FindClass("djz");
        jobject object_minecraft = Minecraft::GetMinecraft();

        jclass main_window_field = jni_mc->FindClass("dez");
        jobject obeject_window = jni_mc->env->GetObjectField(object_minecraft,jni_mc->env->GetFieldID(mc,"O","Ldez;"));


        jmethodID method_width = jni_mc->env->GetMethodID(main_window_field,"m","()I");
        jmethodID method_height = jni_mc->env->GetMethodID(main_window_field,"n","()I");

        Vector2 size = {
            (double)jni_mc->env->CallIntMethod(obeject_window,method_width),
            (double)jni_mc->env->CallIntMethod(obeject_window,method_height)
        };

        jni_mc->env->DeleteLocalRef(mc);
        jni_mc->env->DeleteLocalRef(object_minecraft);
        jni_mc->env->DeleteLocalRef(main_window_field);
        jni_mc->env->DeleteLocalRef(obeject_window);
        return size;
    }
    
    inline Local local;
    inline Render render;
    inline World world;
    inline MatrixStack stack;
} // namespace Minecraft

#endif