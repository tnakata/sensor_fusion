/*
 * SensorFusion.h
 *
 *  Created on: 2016/03/22
 *      Author: glidingsheep
 */

#ifndef SENSORFUSION_HPP_
#include <mraa.hpp>
#include <lsm9ds0.h>
#include "Vector3D.hpp"
#define SENSORFUSION_HPP_

class SensorFusion {
public:
	SensorFusion();
	virtual ~SensorFusion();
	void getGVector(Vector3D& acc);

private:
	Vector3D accRaw;
	Vector3D accZeroOffset;
	Vector3D accAdjusted;
	upm::LSM9DS0 *sensor;

	void updateAccelorometer();
};

#endif /* SENSORFUSION_H_ */
