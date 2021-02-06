#pragma once
#include <array>
#include <vector>

#define TIMESTEP 0.1
#define G 6.6708e-11 //kgms-2


using namespace std;


//declaring class of type Body, all members are public

class Body {


	friend class Printdata;

private:

	static int count;
	double mass;
	array <double,3> pos;
	array <double, 3> vel;
	array <double, 3> acc;

	
public:

	//constructor function for a body
	Body(double, array <double, 3>, array <double, 3>, array <double, 3>);
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

