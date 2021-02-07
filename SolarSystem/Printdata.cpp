#include "pch.h"
#include "Printdata.h"
#include "Body.h"
#include <fstream>
#include <iostream>

void Printdata::addPosition(Body& body) {

	for (int i = 0; i < 3; i++)
	{		
		positions.push_back(body.pos[i]);
		
	}


}

void Printdata::printPosition(void) {

	fstream myfile("system1.txt", fstream::app);

	if (myfile.is_open())
	{
		for (int i = 0; i < positions.size(); i++)
		{
			if (i < positions.size()-1)
			{

				myfile << positions[i] << "\t";
			}
			
			else
			{
				myfile << positions[i] << endl;
			}
		}


	}

}

void Printdata::deletePosition() 
{
	positions.erase(positions.begin(), positions.end());

}