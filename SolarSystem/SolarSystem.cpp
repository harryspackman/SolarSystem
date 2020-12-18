#include "pch.h"
#include <iostream>
#include <fstream>
#include <math.h>
#include "Body.h"
#include "Gravity.cpp"


int Body::count;

//initialising objects all data taken from NASA planetary factsheets eg. https://nssdc.gsfc.nasa.gov/planetary/factsheet/mercuryfact.html 
Body Sun(1.989e30, { 0.0, 0.0, 0.0 }, { 0.0, 0.0, 0.0 }, { 0.0, 0.0, 0.0 });// mass, position vector, velocity vector, acceleration vector
Body Mercury(3.285e23, { 69.817e9, 0.0, 0.0 }, { 0.0, 40e3, 0.0 }, { 0.0, 0.0, 0.0 }); //currently using mercury's mass and distance to the sun
//Body Venus(4.867e24, { 108.939e9, 0.0, 0.0 }, { 0.0, 34.79e3, 0.0 }, { 0.0, 0.0, 0.0 }); //distance is the aphelion, using minimum orbital speed
//Body Earth(5.972e24, { 152.099e9, 0.0, 0.0 }, { 0.0, 29.29e3, 0.0 }, { 0.0, 0.0, 0.0 });
//Body Mars(6.417e23, { 249.229e9, 0.0, 0.0 }, { 0.0, 21.97e3, 0.0 }, { 0.0, 0.0, 0.0 });
//Body Jupiter(1898.19e24, { 816.618e9, 0.0, 0.0 }, { 0.0, 12.44e3, 0.0 }, { 0.0, 0.0, 0.0 });

Body Bodies[2] = { Sun,  Mercury/*, Venus, Earth, Mars, Jupiter*/ };

int main()
{
	//for each time step
	for (int dt = 0; dt < 760000; dt++) {


		for (int i = 0; i < Bodies[0].totalObjects(); i++) {

			for (int j = 0; j < Bodies[0].totalObjects(); j++) {

				if (i != j) {

					calculate_acceleration(Bodies[i], Bodies[j]);

				}

			}

			update_velocity(Bodies[i]);

			update_position(Bodies[i]);

		}
		
		printData();

	}

	return 0;
}



void printData(void) {

	fstream myfile("system.txt", fstream::app);
	if (myfile.is_open()) {


		for (int l = 0; l < Bodies[0].totalObjects(); l++) {

			if (l < (Bodies[0].totalObjects() - 1)) {

				for (int m = 0; m < 3; m++) {

					myfile << Bodies[l].pos[m] << "\t";

				}

			}

			else {

				for (int n = 0; n < 3; n++) {

					if (n < 2) {

						myfile << Bodies[l].pos[n] << "\t";


					}

					else {

						myfile << Bodies[l].pos[n] << endl;

					}
				}

			}



		}


	}

	else {

		cout << "myfile did not open" << endl;

	}

	myfile.close();
}