#ifndef SETTINGS
#define SETTINGS
#include "../utils/ListModule.h"
namespace Settings {
    namespace Cheat {
        inline bool isGlowEsp = false;
        inline bool isHitBox = false;
        inline bool isSprint = false;
        inline bool isWorldTime = false;
        inline bool isAimBot = false;  


        inline bool isWaterMark = true;
        inline bool isArrayList = false;

        inline float distance_aim_bot = 100;
        inline float time_world = 10000.f;
        inline float size_hit_box = 0.3f;

        inline ListModule list_module;

        namespace AimBot {
            inline bool isHud = false;
            inline int bind = 0;
        }
    }
}

#endif