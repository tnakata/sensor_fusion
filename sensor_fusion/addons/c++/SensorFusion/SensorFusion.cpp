/*
 * SensorFusion.cpp
 *
 *  Created on: 2016/03/22
 *      Author: glidingsheep
 */

#include "SensorFusion.hpp"

SensorFusion::SensorFusion() : TS_GYRO(M_PI/180.0f/760.0f), ACC_WEIGHT(0.01) {
	sensor = new upm::LSM9DS0();
	sensor->init();
	sensor->setAccelerometerODR(sensor->XM_AODR_1000);
	sensor->setGyroscopeODR(sensor->G_ODR_760_100);
	updateAccelorometer();
	accAngleEstimate = accRaw;
	sensor->update();
}

SensorFusion::~SensorFusion() {
}

void SensorFusion::updateAccelorometer() {
	if(sensor->getAccelerometerStatus() & sensor->STATUS_REG_A_ZYXADA)
	{
		sensor->updateAccelerometer();
		sensor->getAccelerometer(&(this->accRaw.x), &(this->accRaw.y), &(this->accRaw.z));
	}
}

void SensorFusion::computeAccCalibrated() {

	this->accZeroOffset.x = this->accRaw.x + 0.1063;
	this->accZeroOffset.y = this->accRaw.y - 0.0163;
	this->accZeroOffset.z = this->accRaw.z + 0.0857;
	this->accCalibrated.x = -(1.0119*this->accZeroOffset.x - 0.0063*this->accZeroOffset.y - 0.0038*this->accZeroOffset.z);
	this->accCalibrated.y = 0.0152*this->accZeroOffset.x + 1.0111*this->accZeroOffset.y - 0.0036*this->accZeroOffset.z;
	this->accCalibrated.z = -0.0333*this->accZeroOffset.x + 0.0433*this->accZeroOffset.y + 0.9797*this->accZeroOffset.z;
}

void SensorFusion::computeAccAngleEstimate() {
	Vector3D accAdj2;
	accAdj2 = accCalibrated*accCalibrated;
	this->accAngleEstimate.y = atan2(accCalibrated.x, sqrt(accAdj2.y+accAdj2.z));
	this->accAngleEstimate.x = atan2(accCalibrated.y, sqrt(accAdj2.x+accAdj2.z));
	this->accAngleEstimate.z = 0.0f;
}

void SensorFusion::updateGyroscope() {
	if(sensor->getGyroscopeStatus() & sensor->STATUS_REG_G_ZYXDA)
	  {
		  sensor->updateGyroscope();
		  sensor->getGyroscope(&(this->gyroRaw.x), &(this->gyroRaw.y), &(this->gyroRaw.z));
	  }
}

void SensorFusion::computeGyroCalibrated() {
	this->gyroCalibrated.x = this->gyroRaw.x - 1.11078;
	this->gyroCalibrated.y = this->gyroRaw.y - 0.0233049;
	this->gyroCalibrated.z = this->gyroRaw.z + 0.454668;
}

void SensorFusion::computeGyroRotation() {
	this->gyroRotation = this->gyroCalibrated*TS_GYRO;
}

void SensorFusion::computeGyroAngleEstimate() {
	this->gyroAngleEstimate = this->fusedAngleEstimate + this->gyroRotation;
	this->gyroAngleEstimate.z = 0.0f;
}

void SensorFusion::computeFusedAngleEstimate() {
	this->fusedAngleEstimate = accAngleEstimate*ACC_WEIGHT + gyroAngleEstimate*(1.0f-ACC_WEIGHT);
}

void SensorFusion::updateParameters() {
	updateAccelorometer();
	computeAccCalibrated();
	computeAccAngleEstimate();

	updateGyroscope();
	computeGyroCalibrated();
	computeGyroRotation();
	computeGyroAngleEstimate();

	computeFusedAngleEstimate();
}

Vector3D SensorFusion::getRawAcc() {
	return this->accRaw;
}

Vector3D SensorFusion::getRawGyro() {
	return this->gyroRaw;
}

Vector3D SensorFusion::getGVector() {
	return this->accCalibrated;
}

Vector3D SensorFusion::getGyroRotation(){
	return this->gyroRotation;
}

Vector3D SensorFusion::getAccAngleEstimate() {
	return this->accAngleEstimate;
}

Vector3D SensorFusion::getGyroAngleEstimate() {
	return this->gyroAngleEstimate;
}

Vector3D SensorFusion::getFusedAngleEstimate() {
	return this->fusedAngleEstimate;
}
