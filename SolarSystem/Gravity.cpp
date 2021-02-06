#pragma once
#include "Gravity.h"
#include <vector>
#include "Body.h"

#define G 6.6708e-11 //kgms-2


//finds centre of mass of system, all objects orbit around this point. this is set as position zero.

double findBarycenter(const vector<Body> AllBodies) {

	double numerator = 0, totalMass = 0;

	int i = 0;


	for (Body ThisBody : AllBodies) {

		numerator += ThisBody.mass * ThisBody.pos[0];
		
		totalMass += ThisBody.mass;


	}

	double barycenter = numerator / totalMass;

	return barycenter;
}



double findplanetangularMomentum(vector<Body> Allbodies) {

	double angularMomentum = 0;

	
	for (Body ThisBody : Allbodies) {

		angularMomentum += ThisBody.mass * ThisBody.vel[1] * ThisBody.pos[0];

	}
	
	return angularMomentum;
}

