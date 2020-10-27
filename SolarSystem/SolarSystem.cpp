
#include "pch.h"
#include <iostream>
#include "header.h"


#define G 6.6708e-11

using namespace std;

int main()
{

	//initialising objects
	Body sun(100000000, 0, 0);
	Body earth(1, 100, 0);


	//calculating orbital velocity
	float v = sqrt((G * sun.mass) / earth.r);


	//calculating time period of orbit
	float cap_t = 2 * 3.1415 * earth.r / v;


	//looping and calculating angular position of earth as a function of time in seconds printing time and angular position to terminal
	for (int t = 0; t < cap_t; t += 10) 
	{

		//angular position in radians
		earth.theta = v * t / earth.r;

		cout << t << '\t' << earth.theta << endl;

	}


}
