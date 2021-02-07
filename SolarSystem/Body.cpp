#include "pch.h"
#include "Body.h"
#include <iostream>


//constuctor function for body
Body::Body(double mass, array<double, 3> position, array <double, 3> velocity, array <double, 3> acceleration) {

	this->mass = mass;
	pos = position;
	vel = velocity;
	acc = acceleration;

	count++;

}

void Body::updatePosition(void) {


	for (int i = 0; i < 3; i++) {
		pos[i] += vel[i] * TIMESTEP;
		//cout << pos[i] << endl;
	}

	//print position

}

void Body::updateVelocity(void) {

	for (int i = 0; i < 3; i++) {

		vel[i] += acc[i] * TIMESTEP;

	}


}

void Body::calculateAcceleration(std::vector<Body> &Allbodies) {


	for (Body& thisBody : Allbodies)
	{
		
		double squar[3];
		double normal[3];

		for (int i = 0; i < 3; i++)
		{
			squar[i] = pow(pos[i] - thisBody.pos[i], 2);

		}

		double r = sqrt(squar[0] + squar[1] + squar[2]);

		for (int i = 0; i < 3; i++) {

			normal[i] = (pos[i] - thisBody.pos[i]) / r;
		}


		// calc acceleration on current body
		for (int i = 0; i < 3; i++) {
			acc[i] += -thisBody.mass * G * normal[i] / pow(r, 2);

		}



	}

}

void Body::clearAcceleration(void) {

	for (int i = 0; i < 3; i++) {
		acc[i] = 0;

	}


}

