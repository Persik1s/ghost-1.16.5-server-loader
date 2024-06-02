#ifndef LOCAL
#define LOCAL
#include "../entity/entity.h"
class Local {
public:
    jobject objectPlayer();

    void SetSprint(bool sprint);

    void SetRotationYaw(float yaw);
    void SetRotationPitch(float pitch);

    Vector3 GetStaticPosition();
};
#endif