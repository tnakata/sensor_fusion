/*
 * Vector3D.cpp
 *
 *  Created on: 2015/09/22
 *      Author: glidingsheep
 */
#include "Vector3D.hpp"

Vector3D::Vector3D()
{
	this->x = this->y = this->z = 0.0f;
}

Vector3D Vector3D::operator+(Vector3D const& vec)
{
	Vector3D ret_vec;
	ret_vec.x = this->x + vec.x;
	ret_vec.y = this->y + vec.y;
	ret_vec.z = this->z + vec.z;

	return ret_vec;
}

Vector3D Vector3D::operator-(Vector3D const& vec)
{
	Vector3D ret_vec;
	ret_vec.x = this->x - vec.x;
	ret_vec.y = this->y - vec.y;
	ret_vec.z = this->z - vec.z;

	return ret_vec;
}

Vector3D Vector3D::operator*(Vector3D const& vec)
{
	Vector3D ret_vec;
	ret_vec.x = this->x * vec.x;
	ret_vec.y = this->y * vec.y;
	ret_vec.z = this->z * vec.z;

	return ret_vec;
}

Vector3D Vector3D::operator/(Vector3D const& vec)
{
	Vector3D ret_vec;
	ret_vec.x = this->x / vec.x;
	ret_vec.y = this->y / vec.y;
	ret_vec.z = this->z / vec.z;

	return ret_vec;
}

void Vector3D::operator+=(Vector3D const& vec)
{
	this->x += vec.x;
	this->y += vec.y;
	this->z += vec.z;
}

void Vector3D::operator-=(Vector3D const& vec)
{
	this->x -= vec.x;
	this->y -= vec.y;
	this->z -= vec.z;
}

void Vector3D::operator*=(Vector3D const& vec)
{
	this->x *= vec.x;
	this->y *= vec.y;
	this->z *= vec.z;
}

void Vector3D::operator/=(Vector3D const& vec)
{
	this->x /= vec.x;
	this->y /= vec.y;
	this->z /= vec.z;
}

Vector3D Vector3D::operator+(float const& value)
{
	Vector3D ret_vec;
	ret_vec.x = this->x + value;
	ret_vec.y = this->y + value;
	ret_vec.z = this->z + value;

	return ret_vec;
}

Vector3D Vector3D::operator-(float const& value)
{
	Vector3D ret_vec;
	ret_vec.x = this->x - value;
	ret_vec.y = this->y - value;
	ret_vec.z = this->z - value;

	return ret_vec;
}

Vector3D Vector3D::operator*(float const& value)
{
	Vector3D ret_vec;
	ret_vec.x = this->x * value;
	ret_vec.y = this->y * value;
	ret_vec.z = this->z * value;

	return ret_vec;
}

Vector3D Vector3D::operator/(float const& value)
{
	Vector3D ret_vec;
	ret_vec.x = this->x / value;
	ret_vec.y = this->y / value;
	ret_vec.z = this->z / value;

	return ret_vec;
}

void Vector3D::operator+=(float const& value)
{
	this->x += value;
	this->y += value;
	this->z += value;
}

void Vector3D::operator-=(float const& value)
{
	this->x -= value;
	this->y -= value;
	this->z -= value;
}

void Vector3D::operator*=(float const& value)
{
	this->x *= value;
	this->y *= value;
	this->z *= value;
}

void Vector3D::operator/=(float const& value)
{
	this->x /= value;
	this->y /= value;
	this->z /= value;
}

void Vector3D::operator=(float const& value)
{
	this->x = value;
	this->y = value;
	this->z = value;
}


