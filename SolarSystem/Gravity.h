#pragma once
#include <vector>

using namespace std;

//function declarations

double findBarycenter(const vector<Body> Allbodies);

double findplanetangularMomentum(vector<Body> Allbodies);

void calculateAcceleration(Body &body1, Body &body2);

void updatePosition(Body &body);

void printData(void);

void updateVelocity(Body &body);