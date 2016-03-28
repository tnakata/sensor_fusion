/*
 * SensorFusion.cpp
 *
 *  Created on: 2016/03/22
 *      Author: glidingsheep
 */

#include "SensorFusion.hpp"

SensorFusion::SensorFusion() {
	sensor = new upm::LSM9DS0();
	sensor->init();
	sensor->setAccelerometerODR(sensor->XM_AODR_1000);
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

void SensorFusion::getGVector(Vector3D& acc) {

	this->updateAccelorometer();
	this->accZeroOffset.x = this->accRaw.x + 0.1063;
	this->accZeroOffset.y = this->accRaw.y - 0.0163;
	this->accZeroOffset.z = this->accRaw.z + 0.0857;
	this->accAdjusted.x = 1.0119*this->accZeroOffset.x - 0.0063*this->accZeroOffset.y - 0.0038*this->accZeroOffset.z;
	this->accAdjusted.y = 0.0152*this->accZeroOffset.x + 1.0111*this->accZeroOffset.y - 0.0036*this->accZeroOffset.z;
	this->accAdjusted.z = -0.0333*this->accZeroOffset.x + 0.0433*this->accZeroOffset.y + 0.9797*this->accZeroOffset.z;

	acc = accAdjusted;
}

