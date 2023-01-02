#include "stdio.h"
#include "iostream"
#include "math.h"
#include "VGL/Maths/Vector3D.hpp"

int main()
{
    Point i(3,4,5);
    Point p(1,2,3);

    Vector3D pi = i - p;
    Vector3D normalized = pi.Normalized();

    std::cout<<"Pac man's view vector:("<<normalized.x<<","<<normalized.y<<","<<normalized.z<<")\n";
    std::cout<<"Pac man's view vector length:"<<normalized.Length();
    return 0;
}
