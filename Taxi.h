#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <list>
#include "Graph.h"

class Taxi																			
{
private:
	double m_mileageDAY;
	double m_fuelACT;
	const double m_fuelMAX;															
	const double m_consumpKM;														
	const double m_costKM;															
	double m_balance;

	static int m_count;												// 5 a) + please check increment/decrement of every constructor/deconstructor
	static int m_countEver;											// 5 c)
	std::string m_number;											// 1 a)
public:
	// void initialize(double fuelM, double consump, double price = 0.0);			
	void bookTrip(bool guest, double distance = 0.0);
	void fillUp(double fPrice = std::rand() % 35 + 130);
	std::string toString()const;													
	Taxi(double fuelMax, double consump, double price, std::string name = "dummy", double balance = 0.0);	// 3 a)
	Taxi();
	Taxi(const Taxi &input);														
	~Taxi();

	void setName();													// 1 b)
	std::string getName()const;										// 1 b)
	std::string getState()const;									// 2 a)
	std::string getCountofTaxis()const;
	std::string staticName();
};

