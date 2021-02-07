#pragma once
#include "Body.h"

class System {

private:

	double angularmomentum;

public:

	double calculateangMomentum(const std::vector<Body>& Allbodies);
	double findBarycenter(const vector<Body>& Allbodies);
	void shiftPosition(double, std::vector<Body> &Allbodies);
	void setsunVelocity(double, Body&);

};
