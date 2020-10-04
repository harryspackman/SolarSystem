#pragma once


//declaring class of type Body
class Body {

public:
	int mass;
	float r, theta;

	Body(int, float, float);

};


//constuctor function for body
Body::Body(int a, float b, float c) {
	mass = a;
	r = b;
	theta = c;

}