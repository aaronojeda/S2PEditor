#pragma once
#include <math.h>

class Vector2D
{
	float m_x;
	float m_y;

public:
	Vector2D() : m_x{ 0 }, m_y{ 0 } {}
	Vector2D(float x, float y) : m_x(x), m_y(y) {}

	float x() { return m_x; };
	void x(float x) { m_x = x; };
	float y() { return m_y; };
	void y(float y) { m_y = y; };
	float length();
	void normalize();

	Vector2D operator+(const Vector2D& v2) const;
	Vector2D operator*(float scalar);
	Vector2D& operator*=(float scalar);
	Vector2D operator-(const Vector2D& v2) const;
	Vector2D operator/(float scalar);
	Vector2D& operator/=(float scalar);

	// Free functions
	friend Vector2D& operator+=(Vector2D& v1, const Vector2D& v2);
	friend Vector2D& operator-=(Vector2D& v1, const Vector2D& v2);
};

