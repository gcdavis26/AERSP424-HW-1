#pragma once
#include <map>
#include <string>



#ifndef PLANE_H
#define PLANE_H
class Plane {
public:
	Plane(std::string, std::string);
	~Plane();
	void operate(double);
	double get_pos();
	std::string get_origin();
	std::string get_destination();
	bool get_SCE();
	double get_vel();
	void set_vel(double);


private:
	double pos, vel, distance;
	bool at_SCE;
	std::string origin, destination;
	std::map<std::string, double> flights;

};
#endif