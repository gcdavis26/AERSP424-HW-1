#include "Pilot.h"
#include "Plane.cpp"
#include <string>

Pilot::Pilot(std::string name)
{
	this->name = name;
	std::cout << "Pilot " << this->name << " with certification " << this << "is ready for boarding at the gate." << std::endl;
}

Pilot::~Pilot()
{
	std::cout << "Pilot " << this->name << " has landed and is out of the plane." << std::endl;
}

std::string Pilot::getName()
{
	return this->name;
}

