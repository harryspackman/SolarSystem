
#include "pch.h"
#include <iostream>
#include <fstream>
#include <math.h>
#include "Body.h"
#include "Gravity.cpp"


using namespace std;

int main()
{

	//initialising objects
	Body sun(1.989e30, { 5, 5, 5 }, { 0.1, 0.1, 0.1 }, { 0.0, 0.0, 0.0 });// mass, position vector, velocity vector, acceleration vector
	Body mercury(3.285e23, { 6.98e9, 0.0, 0.0 }, { 0.0, 3.5e4, 0.0 }, { 0.0, 0.0, 0.0 }); //currently using mercury's mass and distance to the sun

	enum coords{X, Y, Z};



	//initialising initial positions, velocities and accelerations of two bodies


	for (int dt = 0; dt < 5; dt++) {
		calculate_acceleration(sun, mercury);
		update_position(sun, mercury);
		update_velocity(sun, mercury);
	}


}

