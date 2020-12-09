
#include "pch.h"
#include <iostream>
#include <fstream>
#include <math.h>
#include "Body.h"
#include "Gravity.cpp"

int Body::count;

int main()
{

	//initialising objects all data taken from NASA planetary factsheets eg. https://nssdc.gsfc.nasa.gov/planetary/factsheet/mercuryfact.html 
	Body Sun(1.989e30, { 0.0, 0.0, 0.0 }, { 0.1, 0.1, 0.1 }, { 0.0, 0.0, 0.0 });// mass, position vector, velocity vector, acceleration vector
	Body Mercury(3.285e23, { 69.817e9, 0.0, 0.0 }, { 0.0, 38.86e4, 0.0 }, { 0.0, 0.0, 0.0 }); //currently using mercury's mass and distance to the sun
	Body Venus(4.867e24, { 108.939e9, 0.0, 0.0 }, { 0.0, 34.79e3, 0.0 }, { 0.0, 0.0, 0.0 }); //distance is the aphelion, using minimum orbital speed
	Body Earth(5.972e24, { 152.099e9, 0.0, 0.0 }, { 0.0, 29.29e3, 0.0 }, { 0.0, 0.0, 0.0 });
	Body Mars(6.417e23, { 249.229e9, 0.0, 0.0 }, { 0.0, 21.97e3, 0.0 }, { 0.0, 0.0, 0.0 });
	Body Jupiter(1898.19e24, { 816.618e9, 0.0, 0.0 }, { 0.0, 12.44e3, 0.0 }, { 0.0, 0.0, 0.0 });
	
	Body Bodies[6] = { Sun, Mercury, Venus, Earth, Mars, Jupiter };


	for (int dt = 0; dt < 5; dt++) {

		for (int i = 0; i < Bodies[0].totalObjects(); i++) {

			for (int j = 0; j < Bodies[0].totalObjects(); j++) {

				if (i != j) {

					calculate_acceleration(Bodies[i], Bodies[j]);

				}

			}

		}
		
		for (int k = 0; k < Bodies[0].totalObjects(); k++) {

			update_position(Bodies[k]);

			update_velocity(Bodies[k]);
		}

	}

	return 0;
	
}

