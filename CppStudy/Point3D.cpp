#include "Point3D.h"

Point3D::Point3D(float x, float y, float z)
	: m_x{x}, m_y{y}, m_z{z}
{
}

float Point3D::getX() const
{
	return m_x;
}

void Point3D::setX(float x)
{
	m_x = x;
}

float Point3D::getY() const
{
	return m_y;
}

void Point3D::setY(float y)
{
	m_y = y;
}

float Point3D::getZ() const
{
	return m_z;
}

void Point3D::setZ(float z)
{
	m_z = z;
}
