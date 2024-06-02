#include "jni.h"
#include "../dll/dll.h"



jobject JNI::GetClassLoader() {
	jclass launch = this->env->FindClass("net/minecraft/launchwrapper/Launch");

	jfieldID sfid = this->env->GetStaticFieldID(launch, "classLoader", "Lnet/minecraft/launchwrapper/LaunchClassLoader;");
	this->env->DeleteLocalRef(launch);
	return this->env->GetStaticObjectField(launch, sfid);
}


jclass JNI::FindClass(const char* nameClass){
    jclass obejctClass = nullptr;
    switch (Dll::number_window)
    {
        case 0:
        {
            jstring nameString = env->NewStringUTF(nameClass);
            jobject classLoader = this->GetClassLoader();
            jclass objectLoader = env->GetObjectClass(classLoader);

            jmethodID mid = env->GetMethodID(objectLoader, "findClass", "(Ljava/lang/String;)Ljava/lang/Class;");
            jobject getClass = env->CallObjectMethod(classLoader, mid, nameString);

            this->env->DeleteLocalRef(nameString);
            this->env->DeleteLocalRef(classLoader);
            this->env->DeleteLocalRef(objectLoader);
            obejctClass = (jclass)getClass;
            break;
        }  
        case 1:
        {
           obejctClass = this->env->FindClass(nameClass);
        }

    }
    return obejctClass;
} 