#pragma once
#include <string>
#include "Plane.h"

#ifndef PILOT_H
#define PILOT_H

class Pilot {
public:
	Pilot(std::string);
	~Pilot();
	std::string getName();

private:
	std::string name;
	Plane* myPlane;

};

#endif
