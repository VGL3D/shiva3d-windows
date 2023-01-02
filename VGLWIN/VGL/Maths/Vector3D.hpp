#ifndef Vector3D_HPP_INCLUDED
#define Vector3D_HPP_INCLUDED

#include "math.h"

class Vector3D{
public:
    Vector3D(){}
    Vector3D(float X,float Y,float Z){
        x = X;
        y = Y;
        z = Z;
    }
    Vector3D operator*(float s) const;
    Vector3D operator/(float s) const;
    Vector3D operator+(const Vector3D &v) const;
    Vector3D operator-(const Vector3D &v) const;
    Vector3D Normalized() const;
    float Length() const;
    float LengthSqr() const;
    float x,y,z;
};

class Point {
public:
    Point(){}
    Point(float X,float Y,float Z){
        x = X;
        y = Y;
        z = Z;
    }
    Point addVector(Vector3D v);
    float x,y,z;
};

Vector3D Vector3D ::operator+(const Vector3D &v) const {
    Vector3D r;
    r.x = x + v.x;
    r.y = y + v.y;
    r.z = z + v.z;
    return r;
}

Vector3D Vector3D ::operator-(const Vector3D &v) const {
    return Vector3D(x - v.x,x - v.y,z-v.z);
}

Vector3D Vector3D ::Normalized() const {
    Vector3D normalized;
    normalized = (*this) / Length();
    return normalized;
}

Vector3D Vector3D ::operator*(float s) const {
    Vector3D scaled;
    scaled.x = x*s;
    scaled.y = y*s;
    scaled.z = z*s;

    return scaled;
}

Vector3D Vector3D ::operator/(float s) const {
    Vector3D scaled;
    scaled.x = x/s;
    scaled.y = y/s;
    scaled.z = z/s;

    return scaled;
}

float Vector3D ::LengthSqr() const {
    float length;
    length = (x*x + y*y + z*z);
    return length;
}

float Vector3D ::Length() const {
    float length;
    length = sqrt(x*x+y*y+z*z);

    return length;
}

Vector3D operator-(Point a,Point b){
    Vector3D v;
    v.x = a.x - b.x;
    v.y = a.y - b.y;
    v.z = a.z - b.z;
    return v;
}

Point Point :: addVector(Vector3D v){
    Point p2;
    p2.x = x + v.x;
    p2.y = y + v.y;
    p2.z = z + v.z;

    return p2;
}

#endif // Vector3D3D_HPP_INCLUDED
