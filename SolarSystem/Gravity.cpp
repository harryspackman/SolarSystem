#pragma once
#include "Gravity.h"

#define G 6.6708e-11

//adapted verlet integrals and vectors from "https://en.wikipedia.org/wiki/Verlet_integration"



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
		//body2.new_acc[j] = -G * body1.mass * (body2.pos[j] - body1.pos[j]) / pow(r, 3);


	}


}

//calculates new position
void update_position(Body &body1) {

	int dt = 1000;

	for (int i = 0; i < 3; i++) {
		body1.new_pos[i] = body1.pos[i] + body1.vel[i] * dt + body1.acc[i] * (dt*dt*0.5);
		body1.pos[i] = body1.new_pos[i];

		//body2.new_pos[i] = body2.pos[i] + body2.vel[i] * dt + body2.acc[i] * (dt*dt*0.5);
		//body2.pos[i] = body2.new_pos[i];


	}

	fstream myfile("mercury16.txt", fstream::trunc);
	if (myfile.is_open()) {

		myfile << body1.pos[0] << "\t" << body1.pos[1] << "\t" << body2.pos[0] << "\t" << body2.pos[1] << endl;

	}

	myfile.close();

}

void printData(void) {


}


//calculates new velocity
void update_velocity(Body &body1) {

	int dt = 1000;

	for (int i = 0; i < 3; i++) {
		body1.new_vel[i] = body1.vel[i] + (body1.acc[i] + body1.new_acc[i])*(dt*0.5);
		body1.vel[i] = body1.new_vel[i];


		//body2.new_vel[i] = body2.vel[i] + (body2.acc[i] + body2.new_acc[i])*(dt*0.5);
		//body2.vel[i] = body2.new_vel[i];

	}


}
