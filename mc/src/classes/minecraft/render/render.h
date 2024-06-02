#ifndef RENDER_CLASS
#define RENDER_CLASS
#include "../../../main/jni.h"
#include "../../../utils/vector/Vector.h"
extern JNI_T* jni_mc;
class Render {
public:
    jobject objectTimer();
    float RenderPartialTicks();

    double* ProjectionMatrix();
    double* ModelViewMatrix();
    int* ViewMatrix();

    void DrawBox(Matrix matrix,Vector3 position,Vector3 entity_pos);
    Vector2 WorldToScrean(Vector3 position,Matrix matrix,Vector2 size_window);
};
#endif


