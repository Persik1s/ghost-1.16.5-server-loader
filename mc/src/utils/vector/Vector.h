#ifndef VECTOR
#define VECTOR
#include "../../complement/glm/glm.hpp"
class Vector2 {
public:
    double x;
    double y;

    Vector2(double x, double y);
    
    Vector2 operator+ (Vector2 vec);
    Vector2 operator+ (int number);
    Vector2 operator- (Vector2 vec);
    Vector2 operator- (int number);
    Vector2 operator* (Vector2 vec);
    Vector2 operator* (int number);
};

class Vector3 {
public:
    double x;
    double y;
    double z;
    Vector3(double x, double y,double z);

    Vector3 operator+ (Vector3 vec);
    Vector3 operator+ (int number);
    Vector3 operator- (Vector3 vec);
    Vector3 operator- (int number);
    Vector3 operator* (Vector3 vec);
    Vector3 operator* (int number);
};


class Matrix {
public:
    float m00;
    float m01;
    float m02;
    float m03;
    float m10;
    float m11;
    float m12;
    float m13;
    float m20;
    float m21;
    float m22;
    float m23;
    float m30;
    float m31;
    float m32;
    float m33;

    Matrix(
        float m00,
        float m01,
        float m02,
        float m03,
        float m10,
        float m11,
        float m12,
        float m13,
        float m20,
        float m21,
        float m22,
        float m23,
        float m30,
        float m31,
        float m32,
        float m33){
        

        this->m00 = m00;
        this->m01 = m01;
        this->m02 = m02;
        this->m03 = m03;
        this->m10 = m10;
        this->m11 = m11;
        this->m12 = m12;
        this->m13 = m13;
        this->m20 = m20;
        this->m21 = m21;
        this->m22 = m22;
        this->m23 = m23;
        this->m30 = m30;
        this->m31 = m31;
        this->m32 = m32;
        this->m33 = m33;
    
    }
};

class Vector4 {
public:
    double x;
    double y;
    double z;
    double w;

    Vector4(double x,double y, double z,double w){
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = w;
    }
};
#endif

