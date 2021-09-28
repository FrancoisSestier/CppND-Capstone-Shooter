#pragma once
#include <math.h>

struct vec2
{
    float x;
    float y;
};

inline vec2 &operator+=(vec2 &lhs, const vec2 &rhs)
{
    lhs.x += rhs.x;
    lhs.y += rhs.y;
    return lhs;
}

inline vec2 operator+(const vec2 &lhs, const vec2 &rhs)
{
    return vec2{lhs.x + rhs.x, lhs.y + rhs.y};
}

inline vec2 operator*(const vec2 &lhs, int rhs)
{
    return vec2{lhs.x * rhs, lhs.y * rhs};
}

inline vec2 operator/(const vec2 &lhs, int rhs)
{
    return vec2{lhs.x / rhs, lhs.y / rhs};
}

inline vec2 operator-(const vec2 &lhs, const vec2 &rhs)
{
    return vec2{lhs.x - rhs.x, lhs.y - rhs.y};
}

inline vec2 &operator-(vec2 &v)
{
    v.x = -v.x;
    v.y = -v.y;
    return v;
}

namespace vec2_helper
{

    inline float magnitude(const vec2 &v)
    {
        return sqrt(pow(v.x, 2) + pow(v.y, 2));
    }

    inline float distance(const vec2& a, const vec2& b) {
        return magnitude(a-b);
    }

    inline vec2 normalize(const vec2& a) {
        vec2 norm = a/magnitude(a);
        if(norm.x >= 1.f) {
            norm.x =1.f;
        }
        if(norm.y >= 1.f) {
            norm.y = 1.f;
        }
        if(norm.x <= -1.f) {
            norm.x = -1.f;
        }
        if(norm.y <= -1.f) {
            norm.y = -1.f;
        }
        return norm;
    }

}