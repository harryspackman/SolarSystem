#include "pch.h"
#pragma once
#include "System.h"
#include "Body.h"
#include <iostream>

double System::calculateangMomentum(const vector<Body>& Allbodies) {

	double Momentum = 0;
	vector<Body> Thesebodies = Allbodies;
	Thesebodies.erase(Thesebodies.begin());

	for (Body ThisBody : Thesebodies) {

		Momentum += ThisBody.m_mass * ThisBody.vel[1];

	}

	return Momentum;
}

double System::findBarycenter(const vector<Body>& AllBodies) {

	double numerator = 0, totalMass = 0;

	int i = 0;


	for (Body ThisBody : AllBodies) {

		numerator += ThisBody.m_mass * ThisBody.pos[0];

		totalMass += ThisBody.m_mass;


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

	body.vel[1] = angMom / (body.m_mass);

}