#include "Pilot.h"
#include "Plane.h"
#include <iostream>

//swaps pointers of pilot and copilot once landed at SCE
void swap(Pilot &pilot, Pilot &copilot) //Pilot is pilot before swap, copilot becomes pilot in the code
{
	Plane *temp = copilot.myPlane; 
	copilot.myPlane = pilot.myPlane;
	pilot.myPlane = temp;
	free(temp);
	//std::cout << "Pilot " << copilot.getName() << " with certification number " << &copilot << " is in control of plane " << copilot.myPlane << std::endl;
}

int main()
{
	Pilot pilot1("Alpha");
	Pilot pilot2("Bravo");
	Plane blackbird("SCE", "ORD");

	pilot1.myPlane = &blackbird;


	double velocity = 450;
	blackbird.set_vel(velocity);

	int timestep = 55;
	int iter = 1500;
	int time = 0;
	std::cout << "Pilot " << pilot1.getName() << " with certification " << &pilot1 << " is in control of plane " << pilot1.myPlane << std::endl;
	std::cout << "Pilot " << pilot2.getName() << " with certification " << &pilot2 << " is in control of plane " << pilot2.myPlane << std::endl;
	std::cout << std::endl;
	for (int x = 0; x < iter; x++)
	{
		time = x * timestep;
		//std::cout << "Time: " << time << " seconds, Position:" << blackbird.get_pos() << " miles." << std::endl;

		blackbird.operate(timestep);

		if (blackbird.get_SCE())
		{
			std::cout << "The plane " << &blackbird << " is at SCE" << std::endl;
			if (pilot1.myPlane == &blackbird) //determining who is pilot
			{
				swap(pilot1, pilot2); 
				std::cout << "Pilot " << pilot2.getName() << " with certification " << &pilot2 << " is in control of plane " << pilot2.myPlane << std::endl;
				std::cout << "Pilot " << pilot1.getName() << " with certification " << &pilot1 << " is in control of plane " << pilot1.myPlane << std::endl;
				std::cout << std::endl;
			}
			else //if pilot1 not pilot, then pilot2 is pilot
			{
				swap(pilot2, pilot1); 
				std::cout << "Pilot " << pilot1.getName() << " with certification " << &pilot1 << " is in control of plane " << pilot1.myPlane << std::endl;
				std::cout << "Pilot " << pilot2.getName() << " with certification " << &pilot2 << " is in control of plane " << pilot2.myPlane << std::endl;
				std::cout << std::endl;
			}

		
		}
	}

	return 0;
}
