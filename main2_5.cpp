#include "Plane.h"
#include <iostream>
#include <string>

int main()
{
	double velocity = 450;
	Plane airplane("SCE", "ORD");
	airplane.set_vel(velocity);

	int timestep = 55;
	int iter = 1500;
	int time = 0;

	for (int x = 0; x < iter; x++)
	{
		time = x * timestep;
		std::cout << "Time: " << time << " seconds, Position:" << airplane.get_pos() << " miles." << std::endl;
		airplane.operate(timestep);
	}

	return 0;
}