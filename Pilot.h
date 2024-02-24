#pragma once
#include <string>
#include "Plane.h"
#include <memory>

#ifndef PILOT_H
#define PILOT_H

class Pilot {
public:
	Pilot(std::string);
	~Pilot();
	std::string getName();
	Plane* myPlane; //question 7
	std::shared_ptr<Plane> myPlaneSmart; //question 8


private:
	std::string name;

};

#endif
