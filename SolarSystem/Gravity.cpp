#pragma once
#include "Gravity.h"

#define G 6.6708e-11


//passing into function time increment, and the two objects by reference
//calculates gravitational acceleration between the two bodies
void calculate_acceleration(Body &body1, Body &body2) {

	double squar[3];


	//calculating distance between body1 and body2
	for (int i = 0; i < 3; i++) {
		squar[i] = pow((body1.pos[i] - body2.pos[i]), 2);

	}

	double r = sqrt(squar[0] + squar[1] + squar[2]);

	//calculating gravitational accelerations of bodies for each direction
	for (int j = 0; j < 3; j++) {

		body1.new_acc[j] += -G * body2.mass * (body1.pos[j] - body2.pos[j]) / pow(r, 3);

	}


}

//calculates new position
void update_position(Body &body1) {

	int dt = 10;

	for (int i = 0; i < 3; i++) {
		body1.new_pos[i] = body1.pos[i] + body1.vel[i] * dt;
		body1.pos[i] = body1.new_pos[i];


	}



}

//calculates new velocity
void update_velocity(Body &body1) {

	int dt = 10;

	for (int i = 0; i < 3; i++) {
		body1.new_vel[i] = body1.vel[i] + body1.new_acc[i]*dt*0.5;
		body1.vel[i] = body1.new_vel[i];

	}


}
