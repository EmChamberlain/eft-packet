#pragma once

#include <cstdint>
#include <mutex>
#include <vector>
#include <algorithm>

extern std::mutex g_world_lock;

std::vector<uint8_t> decompress_zlib(uint8_t* data, int len);

struct Quaternion
{
    float x;
    float y;
    float z;
    float w;
};

class Vector3
{
public:
    float x;
    float y;
    float z;

	Vector3(float _x, float _y, float _z)
	{
		x = _x;
		y = _y;
		z = _z;
	}

	Vector3(float _x, float _y)
	{
		x = _x;
		y = _y;
		z = 0.0f;
	}

	Vector3()
	{
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
	}

	Vector3& operator+=(const Vector3& other)
	{
		x += other.x;
		y += other.y;
		z += other.z;

		return *this;
	}

	Vector3& operator+(const Vector3 other)
	{
		return Vector3(x + other.x, y + other.y, z + other.z);
	}

	Vector3& operator-=(const Vector3& other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;

		return *this;
	}

	Vector3& operator-(const Vector3 other)
	{
		return Vector3(x - other.x, y - other.y, z - other.z);
	}

	Vector3& operator*=(float other)
	{
		x *= other;
		y *= other;
		z *= other;

		return *this;
	}

	Vector3& operator*(float other)
	{
		return Vector3(x * other, y * other, z * other);
	}

	Vector3& operator/=(float other)
	{
		x /= other;
		y /= other;
		z /= other;

		return *this;
	}

	Vector3& operator/(float other)
	{
		return Vector3(x / other, y / other, z / other);
	}

	void clamp(Vector3 max)
	{
		x = std::clamp(x, 0.0f, max.x);
		y = std::clamp(y, 0.0f, max.y);
		z = std::clamp(z, 0.0f, max.z);
	}

	void clamp(Vector3 min, Vector3 max)
	{
		x = std::clamp(x, min.x, max.x);
		y = std::clamp(y, min.y, max.y);
		z = std::clamp(z, min.z, max.z);
	}
};

Vector3 to_euler(Quaternion& quat);
