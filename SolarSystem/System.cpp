#include "pch.h"
#pragma once
#include "System.h"
#include "Body.h"
#include <iostream>

double System::calculateangMomentum(const vector<Body>& Allbodies) {

	double angularMomentum = 0;
	vector<Body> Thesebodies = Allbodies;
	Thesebodies.erase(Thesebodies.begin());

	for (Body ThisBody : Thesebodies) {

		angularMomentum += ThisBody.mass * ThisBody.vel[1] * ThisBody.pos[0];

	}

	return angularMomentum;
}

double System::findBarycenter(const vector<Body>& AllBodies) {

	double numerator = 0, totalMass = 0;

	int i = 0;


	for (Body ThisBody : AllBodies) {

		numerator += ThisBody.mass * ThisBody.pos[0];

		totalMass += ThisBody.mass;


	}

	double barycenter = numerator / totalMass;

	return barycenter;
}

void System::shiftPosition(double centreofMass, std::vector<Body> &Allbodies) {

	for (Body& ThisBody : Allbodies) {

		ThisBody.pos[0] += -centreofMass;

	}

}

void System::setsunVelocity(double angMom, Body& body) {

	body.vel[1] = angMom / (body.mass * body.pos[0]);
	cout << body.vel[1] << endl;
}