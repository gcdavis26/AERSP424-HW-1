#include "Pilot.h"
#include "Plane.h"
#include <string>
#include <iostream>
#include <memory>

Pilot::Pilot(std::string name)
{
	this->name = name;
	std::cout << "Pilot " << this->name << " with certification " << this << "is ready for boarding at the gate." << std::endl;
	this->myPlane = NULL; //for question 7 
	this->myPlaneSmart = NULL; //for question 8
	//pointers originally null because we don't know what kind of plane to put there yet 
}

Pilot::~Pilot()
{
	std::cout << "Pilot " << this->name << " has landed and is out of the plane." << std::endl;
}

std::string Pilot::getName()
{
	return this->name;
}




