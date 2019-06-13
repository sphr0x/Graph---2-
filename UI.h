#pragma once
#include "Taxi.h"
#include <list>
#include "Graph.h"

class UI											
{
public:
	void printMenu()const;							
	int chooseTaxi(std::list<Taxi*>& Taxis);
	void menu(Graph* bGraph);
	void listofTaxi(std::list<Taxi*>* Taxis);				// 4 a)
	void DELETElistofTaxi(std::list<Taxi*>* Taxis);			// 4 a) -> free RAM
	int checkInput(int choose)const;
	double checkDist(double distance)const;
	void printLocation(Graph& bGraph)const;
	Node* setLocation(int& location, Graph* bGraph);
	void printRoute(std::deque<Node*>& actualRoute);
	void deleteRoute(std::deque<Node*>& actualRoute);
	UI();
	~UI();
};

