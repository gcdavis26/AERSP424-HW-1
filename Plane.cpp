#include "Plane.h"
#include <iostream>
#include <map>
#include <string>



Plane::Plane(std::string from, std::string to) {
	origin = from;
	destination = to;
	flights;
	flights.insert({ "PHL", 160 });
	flights.insert({ "ORD", 640 });
	flights.insert({ "EWR", 220 });
	distance = flights[destination];
	pos = 0;
	vel = 0;
	at_SCE = 0;
	std::cout << "Plane created at " << this << std::endl;
}
Plane::~Plane()
{
	std::cout << "Plane destroyed" << std::endl;
}

void Plane::operate(double dt)
{
	if (pos < distance)
	{
		pos += vel/3600 * dt;
		at_SCE = 0;
	}
	else
	{
		if (destination == "SCE")
		{
			at_SCE = 1;
		}
		//std::cout << "Arrived at " << destination << "!" << std::endl; //for testing

		std::string temp = origin;
		origin = destination;
		destination = temp; 
		pos = 0.0;
	}
}

double Plane::get_pos()
{
	return pos;
}
std::string Plane::get_origin()
{
	return origin;
}

std::string Plane::get_destination()
{
	return destination;
}

bool Plane::get_SCE()
{
	return at_SCE;
}

double Plane::get_vel()
{
	return vel;
}

void Plane::set_vel(double speed)
{
	vel = speed;
}



