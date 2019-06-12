#pragma once
#include <iostream>
#include "Taxi.h"
#include <cstdlib>													// std::rand() 
#include <string>													// std::to_string
#include <iomanip>													// std::setw(), std::fixed() etc...
#include <sstream>													// std::ostringstream
#include <list>														// std::list<typ> bezeichner
/*
void Taxi::initialize(double fuelM, double consump, double price) {		
	m_consumpKM = consump/100;
	m_costKM = price;
	m_fuelMAX = fuelM;
	m_mileageDAY = 0.0;
	m_fuelACT = m_fuelMAX;
	m_balance = 0.0;
}
*/
void Taxi::bookTrip(bool guest, double distance) {						
	double fuelR = std::rand() % 35 + 130;								
														
	if ((m_fuelACT >= (m_consumpKM*distance)) && (distance >= 0)){
		m_mileageDAY += distance;
		m_fuelACT -= (m_consumpKM*distance);
		if (guest == 1) {
			m_balance += (distance * m_costKM);
			std::cout << "\t\t\tGebucht mit Fahrgast!" << std::endl;
		}
		else if (guest == 0) {
			std::cout << "\t\t\tGebucht ohne Fahrgast!" << std::endl;
		}
	}
	else if (distance < 0) {
		std::cerr << "\t\t\tFehler: Reisestrecke im negativen Bereich !" << std::endl;
		std::cout << "\t\t\tAchtung: Bitte neue Aktion waehlen !" << std::endl;
		return;
	}
	else {
		std::cerr << "\t\t\tFehler: Tankfuellung nicht ausreichend!" << std::endl;
		std::cout << "\t\t\tAchtung: Bitte neue Aktion waehlen !" << std::endl;
		return;
	}
}
void Taxi::fillUp(double fPrice ) {										
	if (m_fuelACT == m_fuelMAX) {
		std::cerr << "\t\t\tFehler: Tank voll!" << std::endl;
	}
	else if ((m_balance >= ((fPrice/100)*(m_fuelMAX - m_fuelACT)))) {
		m_balance -= (fPrice/100) * (m_fuelMAX - m_fuelACT);
		m_fuelACT = m_fuelMAX;
		std::cout << "\t\t\tAufgetankt!" << std::endl;
	}
	else {
		std::cerr << "\t\t\tFehler: Unzureichende Finanzmittel!" << std::endl;
	}
}
std::string Taxi::toString()const {										
	return "\t\t\tTageskilometerstand: " + std::to_string(m_mileageDAY) + "\n\t\t\tTankinhalt: " + std::to_string(m_fuelACT)
		+ "\n\t\t\tGeldbilanz: " + std::to_string(m_balance);
}
Taxi::Taxi(double fuelMax, double consump, double price, std::string name, double balance )
	: m_number(name), m_consumpKM(consump / 100), m_costKM(price), m_fuelMAX(fuelMax), m_mileageDAY(0.0), m_fuelACT(fuelMax),
	m_balance(balance) {
	setName();													// 1 c)
	++m_count;
	++m_countEver;
	m_number = staticName();
	std::cout << "(Taxi-Counter bei " << m_count << ")" << std::endl;
}
Taxi::Taxi(const Taxi &input) 
	: m_number(input.m_number), m_consumpKM(input.m_consumpKM), m_costKM(input.m_costKM), m_fuelMAX(input.m_fuelMAX), m_mileageDAY(0.0), m_fuelACT(input.m_fuelMAX),
	m_balance(0.0) {
	setName();													// 1 c)
	++m_count;
	++m_countEver;
	std::cout << "(Taxi-Counter bei " << m_count << ")" << std::endl;
}																							
Taxi::Taxi()													// 3 c)													
	: m_number("Taxi_001"), m_consumpKM(7.2 / 100), m_costKM(0.7), m_fuelMAX(75), m_mileageDAY(0.0), m_fuelACT(75),
	m_balance(0.0) {
	++m_count;
	++m_countEver;
	std::cout << "(Taxi-Counter bei " << m_count << ")" << std::endl;
}
Taxi::~Taxi(){
	std::cout << "(Taxi-Counter bei " << m_count << ")" << std::endl;
	--m_count;
}
void Taxi::setName() {
	std::string name;
	if (m_number.length() > 8) {
		std::cerr << "\t\t\tFehler: Die Eingabe darf nicht mehr als 8 Zeichen beinhalten!" << std::endl;
		std::cout << "\t\t\tBitte eine Taxibezeichnung eingeben: " << std::endl << "\tEingabe:";
		while (1) {
			std::cin >> name;
			if (name.length() <= 8) {
				m_number = name;
				return;
			}
			else {
				std::cerr << "\t\t\tFehler: Die Eingabe darf nicht mehr als 8 Zeichen beinhalten!" << std::endl << "\tEingabe:";
			}
		}
	}
}
std::string Taxi::getName()const {
	return m_number;
}
std::string Taxi::getState()const {
	const char seperate = ' ';
	const int widthNum = 8;
	std::ostringstream out;
	
	out << "\t\t\t" << std::left << std::setw(widthNum) << std::setfill(seperate) << m_number << " >>" <<
	std::right << std::setw(widthNum) << std::setfill(seperate) << std::fixed << std::setprecision(2) << m_mileageDAY << " km," <<
	std::right << std::setw(widthNum) << std::setfill(seperate) << std::fixed << std::setprecision(2) << m_fuelACT << " l," <<
	std::right << std::setw(widthNum) << std::setfill(seperate) << std::fixed << std::setprecision(2) << m_balance << " Euro" << std::endl;
	return out.str();
}
std::string Taxi::getCountofTaxis()const {
	const char seperate = '0';
	const int widthNum = 3;
	std::ostringstream out;

	out << "Taxi_" << std::right << std::setw(widthNum) << std::setfill(seperate) << m_countEver << std::endl;
	return out.str();
}
std::string Taxi::staticName() {
	const char seperate = '0';
	const int widthNum = 3;
	std::ostringstream out;

	out << "Taxi_" << std::right << std::setw(widthNum) << std::setfill(seperate) << m_count;
	return out.str();
};

int Taxi::m_count = 0;			// def from static NOT in .h !!
int Taxi::m_countEver = 0;