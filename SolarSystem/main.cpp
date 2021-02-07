#include "pch.h"
#include <iostream>
#include <fstream>
#include <math.h>
#include "Body.h"
#include "System.h"
#include "Printdata.h"


int Body::count;

//initialising objects all data taken from NASA planetary factsheets eg. https://nssdc.gsfc.nasa.gov/planetary/factsheet/mercuryfact.html 
Body Sun(333000, { 0, 0.0, 0.0 }, { 0.0, 0.0, 0.0 }, { 0.0, 0.0, 0.0 });// mass, position vector, velocity vector, acceleration vector
Body Mercury(0.75, { 0.387, 0.0, 0.0 }, { 0.0, 1.59, 0.0 }, { 0.0, 0.0, 0.0 }); //currently using mercury's mass and distance to the sun
//Body Venus(4.867e24, { 108.939e9, 0.0, 0.0 }, { 0.0, 34.79e3, 0.0 }, { 0.0, 0.0, 0.0 }); //distance is the aphelion, using minimum orbital speed
Body Earth(1.00, { 1, 0.0, 0.0 }, { 0.0, 1.0, 0.0 }, { 0.0, 0.0, 0.0 });
//Body Mars(6.417e23, { 249.229e9, 0.0, 0.0 }, { 0.0, 21.97e3, 0.0 }, { 0.0, 0.0, 0.0 });
//Body Jupiter(1898.19e24, { 816.618e9, 0.0, 0.0 }, { 0.0, 12.44e3, 0.0 }, { 0.0, 0.0, 0.0 });

vector<Body> Bodies = { Sun, Mercury, Earth};

int main()
{

	Printdata printdata;
	System system;

	//initialise bodies function
	//TO DO

	double centreofMass = system.findBarycenter(Bodies);


	system.shiftPosition(centreofMass, Bodies);
			
	//angular momentum is mass * vel * radius, returns combined starting angular momentum of the planets only
	double angMom = system.calculateangMomentum(Bodies);
	
	system.setsunVelocity(angMom, Bodies[0]);

	
	//for each time step
	for (int dt = 0; dt < 250000; dt++) {

		for (Body& ThisBody : Bodies)
		{

			ThisBody.calculateAcceleration(Bodies);

		}

		for (Body& ThisBody : Bodies)
		{
			ThisBody.updateVelocity();
			ThisBody.updatePosition();
			ThisBody.clearAcceleration();

			if (dt % 100 == 0) {

				printdata.addPosition(ThisBody);
				printdata.printPosition();

			}
			
		}

		
	}
	
	return 0;
}