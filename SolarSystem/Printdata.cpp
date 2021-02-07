#include "pch.h"
#include "Printdata.h"
#include "Body.h"
#include <fstream>
#include <iostream>

void Printdata::addPosition(Body& body) {

	for (int i = 0; i < 3; i++)
	{
		//cout << body.pos[0];
		positions.push_back(body.pos[i]);
		//cout << positions[i] << endl;
	}


}

void Printdata::printPosition(void) {

	fstream myfile("system.txt", fstream::app);

	if (myfile.is_open())
	{

		for (auto it = positions.begin(); it != positions.end(); it++)
		{
			if (it != positions.end()-1)
			{
				//myfile << positions[*it] << "\t";
				//std::cout << positions[*it] << "\t";
			}

			else 
			{
				//myfile << positions[*it] << endl;

			}
		}


	}

}