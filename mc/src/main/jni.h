#ifndef JNI_STRUCT
#define JNI_STRUCT
#include "include.h"

typedef class JNI {
public:
    JNIEnv* env;
    JavaVM* vm;
    jclass FindClass(const char* nameClass);
private:
    jobject GetClassLoader();
} JNI_T;
#endif 