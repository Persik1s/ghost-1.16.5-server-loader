#ifndef MATH
#define MATH
#define PI 3.141592653589793238462643383279502884
#include "Vector/Vector.h"
#include <math.h>
inline Vector2 rotation(Vector3 vec1,Vector3 vec2,float eye){
    double x = vec1.x - vec2.x;
	double y = vec1.y - (vec2.y + eye) + 1.5;
	double z = vec1.z - vec2.z;

	double sq = sqrt(x * x + z * z);


	float u2 = (float)(atan2(z, x) * (180 / PI) - 90.0F);
	float u3 = (float)(-atan2(y, sq) * (180 / PI));

    return {u2,u3};
}   
inline double RadToDeg(double number ){
	return number * 180.0 / PI;
}

inline double Direction(double x1, double y1, double x2, double y2) {
     return RadToDeg(atan2(y2 - y1, x2 - x1));
}
#endif