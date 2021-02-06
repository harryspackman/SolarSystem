#include "Printdata.h"
#include "Body.h"
#include <fstream>

void Printdata::addPosition(Body& body) {

	for (int i = 0; i < 3; i++)
	{
		positions.push_back(body.pos[i]);

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
				myfile << positions[*it] << "\t";

			}

			else 
			{
				myfile << positions[*it] << endl;

			}
		}


	}

}