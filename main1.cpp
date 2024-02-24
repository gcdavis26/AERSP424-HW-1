#include <iostream>
#include <vector>
#include <iomanip>

const int max_weight = 2950; //lb
const double forward_limit = 82.1; //lb
const double aft_limit = 84.7; //lb

//Purpose: Find the amount of fuel required for the center of gravity fo the plane to be good
//Inputs: Total weight of system before calibration, total moment of system, current weight (passed by reference), and target weight
//Outputs: Return the change in amount of fuel required, change all other variables accordingly
//Other info: Target variable will either be the aft or forward limit, depending on scenario

//Math:
/*
target c_g = (total moment + fuel change * moment arm) / (Total weight + fuel change)

target c_g * total_weight + target c_g * fuel change = total moment + fuel change * moment arm

target c_g * total_weight - total moment = fuel change * moment arm - target c_g * fuel change

(target c_g * total weight - total moment) / (moment arm - target c_g) = fuel change
*/

double calibrateFuel(double& total_weight, double& total_moment, double& fuel_weight, double moment_arm, double target)
{
	double delta = (target * total_weight - total_moment) / (moment_arm - target);
	fuel_weight += delta;
	total_weight += delta;
	total_moment += delta * moment_arm;
	return delta;
}
int main()
{
	//These variables will be populated by user
	double empty_weight;
	double weight_moment;

	int frontseats, front_moment; //# of seats, moment arm
	std::vector<int> front_weight; //weights of each passenger
	double backseats, back_moment; //# of seats, moment arm
	std::vector<int> back_weight; //weights of each passenger

	double fuel_volume, fuel_heaviness, fuel_moment;
	double baggage, bag_moment;
	/////////////////////////////////////////
	//These variables will be calculated

	double front_total = 0;
	double back_total = 0;
	double fuel_weight;

	double total_moment;
	double total_weight;

	double c_g; //center of gravity
	/////////////////////////////////////////

	//Inputs

	std::cout << "Enter airplane empty weight (lb): ";
	std::cin >> empty_weight;
	std::cout << "Enter airplane empty-weight moment (lb-in): ";
	std::cin >> weight_moment;
	
	std::cout << "Enter the number of front seat occupants: ";
	std::cin >> frontseats;
	for (int passenger = 1; passenger <= frontseats; passenger++) //loop to add each passenger weight
	{
		int weight;
		std::cout << "Enter the weight of front seat occupant " << passenger << ": ";
		std::cin >> weight;
		front_weight.push_back(weight); //add each weight to the vector
	}
	std::cout << "Enter the moment of arm for the front seats: ";
	std::cin >> front_moment;
	

	std::cout << "Enter the number of back seat occupants: ";
	std::cin >> backseats;
	for (int passenger = 1; passenger <= backseats; passenger++) //loop to add each passenger weight
	{
		int weight;
		std::cout << "Enter the weight of back seat occupant " << passenger << ": ";
		std::cin >> weight;
		back_weight.push_back(weight); //add each weight to the vector
	}
	std::cout << "Enter the moment of arm for the back seats: ";
	std::cin >> back_moment;

	std::cout << "Enter the number of gallons of fuel: ";
	std::cin >> fuel_volume;
	std::cout << "Enter the weight of the fuel per gallon: ";
	std::cin >> fuel_heaviness;
	std::cout << "Enter the fuel tank moment arm length (in): ";
	std::cin >> fuel_moment;

	std::cout << "Enter the total baggage weight (lb): ";
	std::cin >> baggage;
	std::cout << "Enter the baggage moment arm (in): ";
	std::cin >> bag_moment;

	// Done with data entry, calculations below
	//Plan: To find center of gravity, find total moment, then divide by total weight

	for (auto person : front_weight)
	{
		front_total += person;
	}

	for (auto person : back_weight)
	{
		back_total += person;
	}
	
	fuel_weight = fuel_volume * fuel_heaviness;

	total_weight = empty_weight + front_total + back_total + baggage + fuel_weight;
	total_moment = weight_moment + front_total * front_moment + back_total * back_moment + baggage * bag_moment + fuel_weight * fuel_moment;

	c_g = total_moment / total_weight;

	std::cout << "Total weight: " << total_weight << "\n" << "Center of gravity: " << c_g << std::endl;
	//Done with initial plane calculations, time to balance it out
	/////////////

	double delta_fuel; //amount needed to be drained/added

	if (c_g < forward_limit) //fuel needs to be drained. Using 2 decimal precision on all new values
	{
		delta_fuel = calibrateFuel(total_weight, total_moment, fuel_weight, fuel_moment, forward_limit) / fuel_heaviness;
		c_g = total_moment / total_weight;
		std::cout << std::setprecision(2) << std::fixed << abs(delta_fuel) << " gallons of fuel have been drained" << std::endl;
		std::cout << "New plane weight: " << std::setprecision(2) << std::fixed << total_weight << std::endl;
		std::cout << "New center of gravity: " << std::setprecision(2) << std::fixed << c_g << std::endl;
	}
	else if (c_g > aft_limit) //fuel needs to be added. Using 2 decimal precision on all new values
	{
		delta_fuel = calibrateFuel(total_weight, total_moment, fuel_weight, fuel_moment, aft_limit) / fuel_heaviness;
		c_g = total_moment / total_weight;
		std::cout << std::setprecision(2) << std::fixed << abs(delta_fuel) << " gallons of fuel have been added" << std::endl;
		std::cout << "New plane weight: " << std::setprecision(2) << std::fixed << total_weight << std::endl;
		std::cout << "New center of gravity: " << std::setprecision(2) << std::fixed << c_g << std::endl;
	}

	std::cout << "The plane meets all requirements" << std::endl;

	







	return 0;
}

