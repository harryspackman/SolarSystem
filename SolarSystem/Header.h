#pragma once
#include <vector>
#include "functions.h"


using namespace std;


//declaring class of type Body, all members are public
//taken verlet integrals and vectors from "https://en.wikipedia.org/wiki/Verlet_integration"
class Body {

public:
	double mass;
	double r, theta;

	double pos[3];
	double vel[3];
	double acc[3];
	double new_pos[3];
	double new_vel[3];
	double new_acc[3];

	
	Body(double, double, double);

	
};


//constuctor function for body
Body::Body(double a, double b, double c) {
	mass = a;
	r = b;
	theta = c;

}

