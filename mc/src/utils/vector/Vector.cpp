#include "Vector.h"


Vector2::Vector2(double x, double y){
    this->x = x;
    this->y = y;
}

Vector2 Vector2::operator+ (Vector2 vec){
        return {this->x + vec.x, this->y + vec.y};
}
Vector2 Vector2::operator+ (int number){
        return {this->x + number, this->y + number};
}

Vector2 Vector2::operator- (Vector2 vec){
        return {this->x - vec.x, this->y - vec.y};
}
Vector2 Vector2::operator- (int number){
        return {this->x - number, this->y - number};
}

Vector2 Vector2::operator* (Vector2 vec){
        return {this->x * vec.x, this->y * vec.y};
}
Vector2 Vector2::operator* (int number){
    return {this->x * number, this->y * number};
}


Vector3::Vector3(double x, double y,double z){
    this->x = x;
    this->y = y;
    this->z = z;
}



Vector3 Vector3::operator+ (Vector3 vec){
        return {this->x + vec.x, this->y + vec.y,this->z + vec.z};
}
Vector3 Vector3::operator+ (int number){
        return {this->x + number, this->y + number,this->z + number};
}

Vector3 Vector3::operator- (Vector3 vec){
         return {this->x - vec.x, this->y - vec.y,this->z - vec.z};
}

Vector3 Vector3::operator- (int number){
        return {this->x - number, this->y - number,this->z - number};
}

Vector3 Vector3::operator* (Vector3 vec){
    return {this->x * vec.x, this->y * vec.y,this->z * vec.z};
}

Vector3 Vector3::operator* (int number){
       return {this->x * number, this->y * number,this->z * number};
}