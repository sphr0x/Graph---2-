#pragma once
#include "Taxi.h"
#include <list>
#include "Graph.h"
#include "Route.h"

class UI											
{
public:
	void printMenu()const;							
	int chooseTaxi(std::list<Taxi*>& Taxis);
	void menu();
	void listofTaxi(std::list<Taxi*>* Taxis);				
	void DELETElistofTaxi(std::list<Taxi*>* Taxis);			
	int checkInput(int choose, int compare = 10)const;
	double checkDist(double distance)const;
	void printLocation(Graph& bGraph)const;
	Node* setLocation(int& location, Graph* bGraph);
	void printRoute(std::deque<Node*>& actualRoute, double distance,Node& dest);
	void deleteRoute(std::deque<Node*>& actualRoute);
	void setMap(Graph& berlin);
	UI();
	~UI();
};

