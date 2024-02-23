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
	Plane* myPlane;



private:
	std::string name;

};

#endif
