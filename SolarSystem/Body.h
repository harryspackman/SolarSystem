#pragma once
#include <array>
#include <vector>

#define TIMESTEP 0.1
#define G 6.6708e-11 //kgms-2


using namespace std;


//declaring class of type Body, all members are public

class Body {


	friend class Printdata;
	friend class System;

private:

	static int count;
	double m_mass;
	std::vector<double> pos;
	std::vector<double> vel;
	std::vector<double> acc;

	
public:

	//constructor function for a body
	Body(double, std::vector<double>, std::vector<double>, std::vector<double>);

	void updatePosition(void);
	void updateVelocity(void);
	void calculateAcceleration(std::vector<Body>& Allbodies);
	void clearAcceleration(void);




	void updatePhysics(std::vector<Body> &Allbodies)
	{
		void updatePosition(void);
		void updateVelocity(void);
		void calculateAcceleration(std::vector<Body>& Allbodies);

	}

	static int totalObjects(void) {

		return count;
	}

};

