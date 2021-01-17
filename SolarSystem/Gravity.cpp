#pragma once
#include "Gravity.h"
#include <vector>

#define G 6.6708e-11


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


	//wanting to calculate the total angular momentum of the planets not including the sun
	Allbodies.erase(Allbodies.begin());

	
	for (Body ThisBody : Allbodies) {

		angularMomentum += ThisBody.mass * ThisBody.vel[1] * ThisBody.pos[0];

	}
	
	return angularMomentum;
}



//passing into function time increment, and the two objects by reference
//calculates gravitational acceleration between the two bodies
void calculateAcceleration(Body &body1, Body &body2) {

	double squar[3];


	//calculating distance between body1 and body2
	for (int i = 0; i < 3; i++) {
		squar[i] = pow((body1.pos[i] - body2.pos[i]), 2);

	}

	double r = sqrt(squar[0] + squar[1] + squar[2]);

	double normal[3];

	for (int i = 0; i < 3; i++) {

		normal[i] = (body1.pos[i] - body2.pos[i]) / r;
	}

	//calculating gravitational accelerations of bodies for each direction
	for (int j = 0; j < 3; j++) {

		body1.new_acc[j] += -G * body2.mass * normal[j] / pow(r, 2);

	}


}

//calculates new position
void updatePosition(Body &body) {

	int dt = 0.1;

	for (int i = 0; i < 3; i++) {
		body.new_pos[i] = body.pos[i] + body.vel[i] * dt;
		body.pos[i] = body.new_pos[i];


	}



}


//calculates new velocity
void updateVelocity(Body &body) {

	int dt = 0.1;

	for (int i = 0; i < 3; i++) {
		body.new_vel[i] = body.vel[i] + body.new_acc[i] * dt;
		body.vel[i] = body.new_vel[i];

	}


}
