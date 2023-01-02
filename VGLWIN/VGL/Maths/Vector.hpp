#ifndef VECTOR_HPP_INCLUDED
#define VECTOR_HPP_INCLUDED

#include "math.h"
#include "VGL/Maths/Point.hpp"

class Vector{
public:
    Vector(){}
    Vector(float X,float Y){
        x = X;
        y = Y;
    }
    Vector operator*(float s) const;
    Vector operator/(float s) const;
    Vector operator+(const Vector &v) const;
    Vector operator-(const Vector &v) const;
    Vector Normalized() const;
    float Length() const;
    float LengthSqr() const;
    float x,y,z;
};

Vector Vector ::operator+(const Vector &v) const {
    Vector r;
    r.x = x + v.x;
    r.y = y + v.y;
    return r;
}

Vector Vector ::operator-(const Vector &v) const {
    return Vector(x - v.x,x - v.y);
}

Vector Vector ::Normalized() const {
    Vector normalized;
    normalized = (*this) / Length();
    return normalized;
}

Vector Vector ::operator*(float s) const {
    Vector scaled;
    scaled.x = x*s;
    scaled.y = y*s;

    return scaled;
}

Vector Vector ::operator/(float s) const {
    Vector scaled;
    scaled.x = x/s;
    scaled.y = y/s;

    return scaled;
}

float Vector ::LengthSqr() const {
    float length;
    length = (x*x+y*y);
    return length;
}

float Vector ::Length() const {
    float length;
    length = sqrt(x*x+y*y);

    return length;
}

Vector operator-(Point a,Point b){
    Vector v;
    v.x = a.x - b.x;
    v.y = a.y - b.y;
    return v;
}

#endif // VECTOR_HPP_INCLUDED
