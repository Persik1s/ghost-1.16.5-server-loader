#include "matrixstack.h"





Matrix MatrixStack::GetMatrix(Vector3 pos){
    jclass matrix_class = jni_mc->FindClass("dfm");
    jclass matrix_entry_class = jni_mc->FindClass("dfm$a");
    jclass matrix_4_f = jni_mc->FindClass("b");

    jmethodID constructor1 = jni_mc->env->GetMethodID(matrix_class,"<init>","()V");
    jobject new_object = jni_mc->env->NewObject(matrix_class,constructor1);


    jmethodID methode_push_matrix = jni_mc->env->GetMethodID(matrix_class,"a","()V");
    jmethodID methode_pop_matrix = jni_mc->env->GetMethodID(matrix_class,"b","()V");
    jmethodID methode_scale_matrix = jni_mc->env->GetMethodID(matrix_class,"a","(FFF)V");
    
    jni_mc->env->CallVoidMethod(new_object,methode_push_matrix);
    jni_mc->env->CallVoidMethod(new_object,methode_scale_matrix,pos.x, pos.y, pos.z);
   

    jmethodID methode_get_last  = jni_mc->env->GetMethodID(matrix_class,"c","()Ldfm$a;");
    jobject stack_object =  jni_mc->env->CallObjectMethod(new_object,methode_get_last);


    jmethodID methode_get_matrix = jni_mc->env->GetMethodID(matrix_entry_class,"a","()Lb;");
    jobject matrix_object = jni_mc->env->CallObjectMethod(stack_object,methode_get_matrix);

    // jclass matrix_entry_class = jni_mc->FindClass("dfm$a");
    // jmethodID constructor = jni_mc->env->GetMethodID(matrix_entry_class,"<init>","(Lb;La;)V");

    // jclass matrix_4_f = jni_mc->FindClass("b");
    // jclass matrix_3_f = jni_mc->FindClass("a");

    // jmethodID constructor_4f = jni_mc->env->GetMethodID(matrix_4_f,"<init>","()V");
    // jmethodID constructor_3f= jni_mc->env->GetMethodID(matrix_3_f,"<init>","()V");

    // jobject matrix4fObj = jni_mc->env->NewObject(matrix_4_f, constructor_4f);
    // jobject matrix3fObj = jni_mc->env->NewObject(matrix_3_f, constructor_3f);

    // jobject entryObj = jni_mc->env->NewObject(matrix_entry_class, constructor, matrix4fObj, matrix3fObj);

    // jmethodID methode_get_matrix = jni_mc->env->GetMethodID(matrix_entry_class,"a","()Lb;");
    // jobject matrix_object = jni_mc->env->CallObjectMethod(entryObj,methode_get_matrix);

    

    jfieldID field_m00 = jni_mc->env->GetFieldID(matrix_4_f,"a","F");
    jfieldID field_m01 = jni_mc->env->GetFieldID(matrix_4_f,"b","F");

    jfieldID field_m02 = jni_mc->env->GetFieldID(matrix_4_f,"c","F");

    jfieldID field_m03 = jni_mc->env->GetFieldID(matrix_4_f,"d","F");
    jfieldID field_m10 = jni_mc->env->GetFieldID(matrix_4_f,"e","F");
    jfieldID field_m11 = jni_mc->env->GetFieldID(matrix_4_f,"f","F");
    jfieldID field_m12 = jni_mc->env->GetFieldID(matrix_4_f,"g","F");
    jfieldID field_m13 = jni_mc->env->GetFieldID(matrix_4_f,"h","F");

    jfieldID field_m20 = jni_mc->env->GetFieldID(matrix_4_f,"i","F");
    jfieldID field_m21 = jni_mc->env->GetFieldID(matrix_4_f,"j","F");
    jfieldID field_m22 = jni_mc->env->GetFieldID(matrix_4_f,"k","F");
    jfieldID field_m23 = jni_mc->env->GetFieldID(matrix_4_f,"l","F");
    jfieldID field_m30 = jni_mc->env->GetFieldID(matrix_4_f,"m","F");
    jfieldID field_m31 = jni_mc->env->GetFieldID(matrix_4_f,"n","F");
    jfieldID field_m32 = jni_mc->env->GetFieldID(matrix_4_f,"o","F");
    jfieldID field_m33 = jni_mc->env->GetFieldID(matrix_4_f,"p","F");

    float m00 = jni_mc->env->GetFloatField(matrix_object,field_m00);
    float m01 = jni_mc->env->GetFloatField(matrix_object,field_m01);
    float m02 = jni_mc->env->GetFloatField(matrix_object,field_m02);
    float m03 = jni_mc->env->GetFloatField(matrix_object,field_m03);
    float m10 = jni_mc->env->GetFloatField(matrix_object,field_m10);
    float m11 = jni_mc->env->GetFloatField(matrix_object,field_m11);
    float m12 = jni_mc->env->GetFloatField(matrix_object,field_m12);
    float m13 = jni_mc->env->GetFloatField(matrix_object,field_m13);

    float m20 = jni_mc->env->GetFloatField(matrix_object,field_m20);
    float m21 = jni_mc->env->GetFloatField(matrix_object,field_m21);
    float m22 = jni_mc->env->GetFloatField(matrix_object,field_m22);
    float m23 = jni_mc->env->GetFloatField(matrix_object,field_m23);
    float m30 = jni_mc->env->GetFloatField(matrix_object,field_m30);
    float m31 = jni_mc->env->GetFloatField(matrix_object,field_m31);
    float m32 = jni_mc->env->GetFloatField(matrix_object,field_m32);
    float m33 = jni_mc->env->GetFloatField(matrix_object,field_m33);

    jni_mc->env->CallVoidMethod(new_object,methode_pop_matrix);
    Matrix matrix = {
        m00,m01,m02,m03,
        m10,m11,m12,m13,
        m20,m21,m22,m23,
        m30,m31,m32,m33
    };

    return matrix;
   
}