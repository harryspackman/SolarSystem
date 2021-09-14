#pragma once
#include <array>
#include <vector>

#define TIMESTEP 8640
#define G 6.6708e-11 //kgms-2


using namespace std;


//declaring class of type Body, all members are public

class Body {


	friend class Printdata;
	friend class System;

private:

	double m_mass;
	std::array<double, 3> pos;
	std::array<double, 3> vel;
	std::array<double, 3> acc;

	
public:

	//constructor function for a body
	Body(double, std::array<double, 3>, std::array<double, 3>, std::array<double, 3>);

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


};

