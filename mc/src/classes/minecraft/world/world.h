#ifndef WORLD_CLASS 
#define WORLD_CLASS
#include "../../../main/jni.h" 
#include "../entity/entity.h"


class World { 
public:
    jobject theObject();

    std::vector<Entity> playerEntities();

    void SetWorldTime(int time);
};
#endif
