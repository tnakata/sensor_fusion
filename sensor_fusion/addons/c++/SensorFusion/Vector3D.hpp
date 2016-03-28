/*
 * Vector3D.hpp
 *
 *  Created on: 2015/09/22
 *      Author: glidingsheep
 */

#ifndef SENSORFUSIONTEST_SRC_VECTOR3D_HPP_
#define SENSORFUSIONTEST_SRC_VECTOR3D_HPP_

class Vector3D
{
public:
	float x;
	float y;
	float z;

	Vector3D();
	Vector3D operator+(Vector3D const& vec);
	Vector3D operator-(Vector3D const& vec);
	Vector3D operator*(Vector3D const& vec);
	Vector3D operator/(Vector3D const& vec);
	void operator+=(Vector3D const& vec);
	void operator-=(Vector3D const& vec);
	void operator*=(Vector3D const& vec);
	void operator/=(Vector3D const& vec);
	Vector3D operator+(float const& value);
	Vector3D operator-(float const& value);
	Vector3D operator*(float const& value);
	Vector3D operator/(float const& value);
	void operator+=(float const& value);
	void operator-=(float const& value);
	void operator*=(float const& value);
	void operator/=(float const& value);
	void operator=(float const& value);
};

#endif /* SENSORFUSIONTEST_SRC_VECTOR3D_HPP_ */
