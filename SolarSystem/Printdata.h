#pragma once
#include "Body.h"



class Printdata {

	std::vector<double> positions;

public:
	
	//adds position of body entered into a std::vector of positions to then be printed out
	void addPosition(Body& body);
	void printPosition(void);

};