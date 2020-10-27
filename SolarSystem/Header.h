#pragma once
#include <vector>

using namespace std;

//declaring class of type Body, all members are public
class Body {

public:
	int mass;
	float r, theta;

	vector <double> pos {0, 0, 0};
	vector <double> vel {0, 0, 0};
	vector <double> acc {0, 0, 0};

	Body(int, float, float);

};


//constuctor function for body
Body::Body(int a, float b, float c) {
	mass = a;
	r = b;
	theta = c;

}

