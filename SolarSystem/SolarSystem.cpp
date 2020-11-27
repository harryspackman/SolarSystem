
#include "pch.h"
#include <iostream>
#include <fstream>
#include <math.h>
#include "Body.h"
#include "Prototypes.h"
#include "Gravity.h"


using namespace std;

int main()
{

	//initialising objects
	Body sun(1.989e30);
	Body earth(3.285e23); //currently using mercury's mass and distance to the sun

	
	//initialising initial positions, velocities and accelerations of two bodies
	sun.pos[0] = 5;
	sun.pos[1] = 5;
	sun.pos[2] = 5;

	sun.vel[0] = 0.1;
	sun.vel[1] = 0.1;
	sun.vel[2] = 0.2;
	
	sun.acc[0] = 0.00;
	sun.acc[1] = 0.00;
	sun.acc[2] = 0.00;

	earth.pos[0] = 6.98e9;
	earth.pos[1] = 0;
	earth.pos[2] = 0;

	earth.vel[0] = 0.0;
	earth.vel[1] = 3.5e4;
	earth.vel[2] = 0.0;

	earth.acc[0] = 0.00;
	earth.acc[1] = 0.00;
	earth.acc[2] = 0.00;

	for (int dt = 0; dt < 5; dt++) {
		calculate_acceleration(sun, earth);
		update_position(sun, earth);
		update_velocity(sun, earth);
	}


}

