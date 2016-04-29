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
#include <cmath>
#define SENSORFUSION_HPP_

class SensorFusion {
public:
	SensorFusion();
	virtual ~SensorFusion();
	void updateParameters();
	Vector3D getRawAcc();
	Vector3D getRawGyro();
	Vector3D getGVector();
	Vector3D getGyroRotation();
	Vector3D getAccAngleEstimate();
	Vector3D getGyroAngleEstimate();
	Vector3D getFusedAngleEstimate();

private:
	const float TS_GYRO;
	const float ACC_WEIGHT;

	Vector3D accRaw;
	Vector3D accZeroOffset;
	Vector3D accCalibrated;
	Vector3D gyroRaw;
	Vector3D gyroCalibrated;
	Vector3D gyroRotation;
	Vector3D accAngleEstimate;
	Vector3D gyroAngleEstimate;
	Vector3D fusedAngleEstimate;

	upm::LSM9DS0 *sensor;

	void updateAccelorometer();
	void computeAccCalibrated();
	void computeAccAngleEstimate();
	void updateGyroscope();
	void computeGyroCalibrated();
	void computeGyroRotation();
	void computeGyroAngleEstimate();
	void computeFusedAngleEstimate();
};

#endif /* SENSORFUSION_H_ */
