#include "Body.h"

//constuctor function for body
Body::Body(double mass, array<double, 3> pos, array <double, 3> vel, array <double, 3> acc) {

	this->mass = mass;
	this->pos = pos;
	this->vel = vel;
	this->acc = acc;

	count++;

}

void Body::updatePosition(void) {


	for (int i = 0; i < 3; i++) {
		pos[i] += vel[i] * TIMESTEP;
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