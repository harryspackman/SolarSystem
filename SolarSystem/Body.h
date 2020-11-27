#pragma once
#include <vector>



using namespace std;


//declaring class of type Body, all members are public

class Body {

public:

	double mass;
	double pos[3];
	double vel[3];
	double acc[3];
	double new_pos[3];
	double new_vel[3];
	double new_acc[3];

	
	Body(double);

	
};


//constuctor function for body
Body::Body(double a) {
	mass = a;

}

