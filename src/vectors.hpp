#ifndef VECTORS_HPP
#define VECTORS_HPP

#include <cmath>
#include <ostream>

struct float3
{
	float3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
	float3(float _x, float _y, float _z, float _w) : x(_x), y(_y), z(_z) {}
	float3(float val) : x(val), y(val), z(val) {}

	float length() { return sqrt(x*x + y*y + z*z); }
	float3 normalize() { return float3(x / length(), y / length(), z / length()); }

	// Scalar operators
	float3 operator+ (float scalar) { return float3(x + scalar, y + scalar, z + scalar); }
	float3 operator- (float scalar) { return float3(x - scalar, y - scalar, z - scalar); }
	float3 operator* (float scalar) { return float3(x * scalar, y * scalar, z * scalar); }
	float3 operator/ (float scalar) { return float3(x / scalar, y / scalar, z / scalar); }

	// Vector operators
	float3 operator+ (const float3 &other) { return float3(x + other.x, y + other.y, z + other.z); }
	float3 operator- (const float3 &other) { return float3(x - other.x, y - other.y, z - other.z); }
	friend float3 operator- (const float3 &lhs, const float3 &rhs) { return float3(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z); }

	float3 operator+= (const float3 &other) { x += other.x; y += other.y; z += other.z; return *this; }
	float3 operator*= (const float  &other) { x *= other;   y *= other;   z *= other;   return *this; }
	float3 operator-= (const float3 &other) { x -= other.x; y -= other.y; z -= other.z; return *this; }

	float3 operator- () { return float3(-x, -y, -z); }

	float operator[] (size_t i) const { return i == 0 ? x : (i == 1 ? y : z); }
	float& operator[] (size_t i) { return i == 0 ? x : (i == 1 ? y : z); }
    friend std::ostream& operator<< (std::ostream &os, const float3 &vec) { return os << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")"; }	
    
	float x, y, z;

private:
	// Used for align to 4 bytes
	float w;

};

inline float3 cross(float3 a, float3 b)
{
    return float3(a.y * b.z - a.z * b.y, a.z * b.z - a.x * b.z, a.x * b.y - a.y * b.x);
}

inline float dot(float3 a, float3 b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

#endif // VECTORS_HPP
