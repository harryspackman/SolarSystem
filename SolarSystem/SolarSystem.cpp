
#include "pch.h"
#include <iostream>
#include <math.h>
#include "header.h"


#define G 6.6708e-11

using namespace std;

//function declarations
void calculate_acceleration(int dt, Body &body1, Body &body2);

void update_position(int dt, Body &body1, Body &body2);

void update_velocity(int dt, Body &body1, Body &body2);


int main()
{

	//initialising objects
	Body sun(1.989e30, 0, 0);
	Body earth(5.972e24, 100, 0);

	
	//initialising initial positions, velocities and accelerations of two bodies
	sun.pos[0] = 5;
	sun.pos[1] = 5;
	sun.pos[2] = 5;

	sun.vel[0] = 0.1;
	sun.vel[1] = 0.1;
	sun.vel[2] = 0.2;
	
	sun.acc[0] = 0.02;
	sun.acc[1] = 0.02;
	sun.acc[2] = 0.03;

	earth.pos[0] = 100e5;
	earth.pos[1] = 100e5;
	earth.pos[2] = 100e5;

	earth.vel[0] = 0.5;
	earth.vel[1] = 0.8;
	earth.vel[2] = 0.9;

	earth.acc[0] = 0.01;
	earth.acc[1] = 0.02;
	earth.acc[2] = 0.03;

	for (int dt = 0; dt < 5; dt++) {
		calculate_acceleration(dt, sun, earth);
		update_position(dt, sun, earth);
		update_velocity(dt, sun, earth);
	}


}


//passing into function time increment, and the two objects by reference
void calculate_acceleration(int dt, Body &body1, Body &body2) {

	double squar[3];

	//calculating distance between body1 and body2
	for (int i = 0; i < 3; i++) {
		squar[i] = pow((body1.pos[i] - body2.pos[i]), 2);

	}
	
	double r = sqrt(squar[0] + squar[1] + squar[2]);

	//calculating gravitational accelerations of bodies for each direction
	for (int j = 0; j < 3; j++) {

		body1.new_acc[j] = G * body2.mass * (body1.pos[j] - body2.pos[j]) / pow(r, 3);
		body2.new_acc[j] = G * body1.mass * (body2.pos[j] - body1.pos[j]) / pow(r, 3);
		
	}

	
}

//calculates new position
void update_position(int dt, Body &body1, Body &body2) {

	for (int i = 0; i < 3; i++) {
		body1.new_pos[i] = body1.pos[i] + body1.vel[i] * dt + body1.acc[i] * (dt*dt*0.5);
		body1.pos[i] = body1.new_pos[i];

		body2.new_pos[i] = body2.pos[i] + body2.vel[i] * dt + body2.acc[i] * (dt*dt*0.5);
		body2.pos[i] = body2.new_pos[i];

	}

	printf("%f %f %f\n", body1.pos[0], body1.pos[1], body1.pos[2]);
	printf("%f %f %f\n", body2.pos[0], body2.pos[1], body2.pos[2]);
}

//calculates new velocity
void update_velocity(int dt, Body &body1, Body &body2) {

	for (int i = 0; i < 3; i++) {
		body1.new_vel[i] = body1.vel[i] + (body1.acc[i] + body1.new_acc[i])*(dt*0.5);
		body1.vel[i] = body1.new_vel[i];

		body2.new_vel[i] = body2.vel[i] + (body2.acc[i] + body2.new_acc[i])*(dt*0.5);
		body2.vel[i] = body2.new_vel[i];
	}

}
