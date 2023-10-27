#pragma once

class Point3D
{
	float m_x { .0f };
	float m_y { .0f };
	float m_z { .0f };

public:

	Point3D(float x, float y, float z);
	~Point3D() = default;
	Point3D(const Point3D& other) = default;
	Point3D& operator= (const Point3D& other) = default;
	Point3D(Point3D&& other) = default;
	Point3D& operator= (Point3D&& other) = default;

	float getX() const;
	void setX(float x);

	float getY() const;
	void setY(float y);

	float getZ() const;
	void setZ(float z);
};