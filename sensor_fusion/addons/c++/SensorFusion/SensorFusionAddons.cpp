#include <iostream>

#include "SensorFusion.hpp"
#include "Vector3D.hpp"
using namespace std;

int main() {
	SensorFusion sensfus;
	Vector3D eval,eval2;
	unsigned int count = 0;

	for (;;) {
		sensfus.updateParameters();
		eval = sensfus.getFusedAngleEstimate();
		eval2 = sensfus.getAccAngleEstimate();

		if(count++ > 0xFF)
		{
			cout << "Fused" << endl;
			cout << "X: " << eval.x << " Y: " << eval.y << " Z: " << eval.z << endl;
			count = 0;

			cout << "Acc Angle" << endl;
			cout << "X: " << eval2.x << " Y: " << eval2.y << " Z: " << eval2.z << endl;
			count = 0;
		}
	}

	return 0;
}
