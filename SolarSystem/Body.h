#pragma once
#include <array>



using namespace std;


//declaring class of type Body, all members are public

class Body {

private:

	static int count;

public:

	double mass;
	array <double,3> pos;
	array <double, 3> vel;
	array <double, 3> acc;
	array <double, 3> new_pos;
	array <double, 3> new_vel;
	array <double, 3> new_acc;

	
	Body(double, array <double, 3>, array <double, 3>, array <double, 3>);

	static int totalObjects(void) {

		return count;
	}

};


//constuctor function for body
Body::Body(double a, array<double, 3> b, array <double, 3> c, array <double, 3> d) {
	
	mass = a;
	pos = b;
	vel = c;
	acc = d;
	
	count++;

}

