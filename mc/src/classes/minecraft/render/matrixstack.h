#ifndef MATRIXSTACK
#define MATRIXSTACK
#include "../../../utils/vector/Vector.h"
#include "../../../main/jni.h"
extern JNI* jni_mc;

class MatrixStack {
public:
    Matrix GetMatrix(Vector3 pos);
};
#endif 
