#ifndef ENTITY_CLASS 
#define ENTITY_CLASS
#include "../../../main/jni.h"
#include "../../../utils/Vector/Vector.h"
extern JNI_T* jni_mc;
class Entity {
private:
    jobject __memory = NULL;
public:
    Entity(jobject point){
        this->__memory = point;
    }

    jobject GetMemory(){
        return this->__memory;
    }
    jobject AxisAlignedBB(double x, double y, double z, double x1, double y1, double z1);
    jobject GetBoundingBox();

    void SetGlowing(bool esp);
    void SetBoundingBox(jobject allib);

    int GetID();

    double MinY();
    double MaxY();
    double Distance(jobject entity);
    double GetEyeHeight();
    bool IsLocalPlayer();

    Vector3 Position();
    Vector3 LastTickPosition();
    
    const char* GetName();

    float GetHealth();
    
};
#endif 




