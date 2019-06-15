#pragma once
#include "UI.h"
#include <list>
#include <windows.h>

void UI::printMenu()const {	

	/*void slow_print(const std::string& str, int delay_time) {              -> maybe
		for (size_t i = 0; i != str.size(); ++i) {
			std::cout << str[i];
			Sleep(delay_time);
		}
	} */
	Sleep(500);
	std::cout << "\n\t\t\t    ->  [             Taxiprogramm v 2.0             ]  <- \n" << std::endl;
	Sleep(500);
	std::cout << "\n\t\t\t    ->  [    Bitte Aktion via Nummerierung waehlen   ]  <- \n\n" << "\t\t\t[1] ->  [        Fahrt mit Fahrgast verbuchen        ]  <-\n";
	Sleep(500);
	std::cout << "\t\t\t[2] ->  [        Fahrt ohne Fahrgast verbuchen       ]  <-\n" << "\t\t\t[3] ->  [                   Tanken                   ]  <-\n";
	Sleep(500);					
	std::cout << "\t\t\t[4] ->  [             Taxistatus ausgeben            ]  <-\n" << "\t\t\t[5] ->  [                   Beenden                  ]  <-\n";
	Sleep(500);				
	std::cout << "\t\t\t[6] ->  [ Bildschirm bereinigen & Menu erneut zeigen ]  <-\n" << std::endl;
}								
int UI::chooseTaxi(std::list<Taxi*>& Taxis) {													
	int choose;

	std::cout << "\t\t\tBitte Taxi waehlen: ( 1 oder 2 )" << std::endl;
	while (1) {
		std::cout << "\tEingabe: ";
		std::cin >> choose;
		choose = checkInput(choose);
		if (choose == 1) {
			std::cout << "\t\t\tTaxi-Bez: " << Taxis.front()->getName() << std::endl;		// 1 d)
			return choose;
		}
		else if(choose == 2) {
			std::cout << "\t\t\tTaxi-Bez: " << Taxis.back()->getName() << std::endl;		// 1 d)
			return choose;
		}
		else {
			std::cerr << "\t\t\tFehler: Bitte 1 oder 2 waehlen!" << std::endl;
		}
	}
}
void UI::menu(Graph* bGraph) {								
	int choose;
	double distance;
	int start, end;
	std::list<Taxi*> Taxis;
	Node* nStart = nullptr;
	Node* nEnd = nullptr;													//  pointer !!
	std::deque<Node*> path;													//  path filled in dijkstra

	listofTaxi(&Taxis);
	printMenu();
	while (1) {
		std::cout << "\tEingabe: ";
		std::cin >> choose;
		choose = checkInput(choose);
		switch (choose) {
		case 1:
			std::cout << "\n\t\t\tBitte Startort waehlen: ( 1 bis 8 ) \n" << std::endl;		// alles in eine fkt ? void setRoute(Graph* bGraph,int start,int end, Node& nStart,Node& nEnd,)
			printLocation(*bGraph);
			std::cout << "\tEingabe: ";
			std::cin >> start;
			start = checkInput(start);
			nStart = setLocation(start, bGraph);						
			std::cout << "\n\t\t\tBitte Zielort waehlen: ( 1 bis 8 ) \n" << std::endl;
			printLocation(*bGraph);
			std::cout << "\tEingabe: ";
			std::cin >> end;
			end = checkInput(end,start);
			nEnd = setLocation(end, bGraph);					// ...
			if (chooseTaxi(Taxis) == 1) {						
				distance = bGraph->findShortestPathDijkstra(path,*nStart,*nEnd);
				Taxis.front()->bookTrip(1, distance);			
				printRoute(path,distance, *nEnd);
				
				deleteRoute(path);								
			}													
			else{
				distance = bGraph->findShortestPathDijkstra(path, *nStart, *nEnd);
				Taxis.back()->bookTrip(1, distance);			
				printRoute(path,distance, *nEnd);
				deleteRoute(path);
			}
			break;
		case 2:
			std::cout << "\n\t\t\tBitte Startort waehlen: ( 1 bis 8 )\n" << std::endl;		// alles in eine fkt ?
			printLocation(*bGraph);
			std::cout << "\tEingabe: ";
			std::cin >> start;
			start = checkInput(start);
			nStart = setLocation(start, bGraph);
			std::cout << "\n\t\t\tBitte Zielort waehlen: ( 1 bis 8 )\n" << std::endl;
			printLocation(*bGraph);
			std::cout << "\tEingabe: ";
			std::cin >> end;
			end = checkInput(end,start);
			nEnd = setLocation(end, bGraph);

			if (chooseTaxi(Taxis) == 1) {						
				distance = bGraph->findShortestPathDijkstra(path, *nStart, *nEnd);
				Taxis.front()->bookTrip(0, distance);
				printRoute(path,distance,*nEnd);
				deleteRoute(path);
			}
			else {												
				distance = bGraph->findShortestPathDijkstra(path, *nStart, *nEnd);
				Taxis.back()->bookTrip(0, distance);
				printRoute(path,distance,*nEnd);
				deleteRoute(path);
			}
			break;
		case 3:
			if (chooseTaxi(Taxis) == 1) {
				Taxis.front()->fillUp();
			}
			else{
				Taxis.back()->fillUp();
			}
			break;
		case 4:
			if (chooseTaxi(Taxis) == 1) {
				std::cout << Taxis.front()->getState() << std::endl;		// 2 b)
			}
			else {
				std::cout << Taxis.back()->getState() << std::endl;			// 2 b)
			}
			break;
		case 5:
			DELETElistofTaxi(&Taxis);							// hier delete taxis ! 
																// hier auch delete graph ?
			std::cout << "\n\t\t\t\t\t\tBeende Programm!" << std::endl;
			return;
		case 6:		
			system("cls");			
			std::cout << "\n\n\t\t\tBildschrim bereinigt! ( Taxidaten sind gespeichert )\n\n" << std::endl;
			UI::printMenu();
			break;
		default:
			std::cerr << "\t\t\tFehler: Bitte 1-6 waehlen!" << std::endl;
			break;
		}
	}
}
void UI::listofTaxi(std::list<Taxi*>* Taxis) {
	Taxi *car3 = new Taxi(75, 7.2, 0.7);
	Taxis->push_back(car3);
	Taxi *car4 = new Taxi(90, 12.5, 0.95);
	Taxis->push_back(car4);
	//std::cout << "\t\t\t Taxi 1 hat den Bezeichner: " << car3->getName() << std::endl << "\t\t\t Taxi 2 hat den Bezeichner: " << car4->getName() << std::endl;
}
void UI::DELETElistofTaxi(std::list<Taxi*>* Taxis) {
	int i = 1;
	while ((Taxis->size()) != 0) {
		delete(Taxis->front());
		Taxis->pop_front();
		std::cout << "\t\t\tInfo: Listenelement "<< i++ << " geloescht via \"delete\" !" << std::endl;
	}
}
int UI::checkInput(int choose, int compare)const {
	while (std::cin.fail() || choose < 1 || choose > 8 || choose == compare) {
		std::cin.clear();
		std::cin.ignore(30, '\n');
		if (choose == compare) {
			std::cerr << "\t\t\tFehler: Sie befinden sich bereits an diesem Ort - bitte nochmal! " << std::endl;
			std::cout << "\tEingabe: ";
		}
		else {
			std::cerr << "\t\t\tFehler: Bitte eine valide Ziffer eingeben: " << std::endl;
			std::cout << "\tEingabe: ";
		}
		std::cin >> choose;
		
	}
	return choose;
};
double UI::checkDist(double distance)const {
	while ((distance < 0) || (std::cin.fail())) {
		std::cin.clear();
		std::cin.ignore(30, '\n');
		std::cerr << "\t\t\tFehler: Bitte eine positive Zahl eingeben: " << std::endl;
		std::cout << "\tEingabe: ";
		std::cin >> distance;
	}
	return distance;
}
void UI::printLocation(Graph& bGraph) const{
	int i = 1;
	for (auto node : bGraph.getNodes())std::cout << "\t\t\t"<< i++ << ": " << node->getID() << std::endl;
	std::cout << "\n";
}
Node* UI::setLocation(int& location, Graph* bGraph){
/*
"Zitadelle Spandau"			1
"Funkturm"					2
"Grenzallee"				3
"Alexanderplatz"			4
"Regattastrecke Gruenau"	5
"Ostkreuz"					6
"Brandenburger Tor"			7
"Strandbad Wannsee"			8
*/
	Node* loc;
	auto it2 = std::next(bGraph->getNodes().begin(), location - 1); // sync nodes to position
	return loc = *it2;
}
void UI::printRoute(std::deque<Node*>& actualRoute, double distance, Node& dest){
	std::cout << "\n\t\t\tRoute: ";
	for (auto node : actualRoute) { 
		if (dest.getID() == node->getID()) {
			std::cout << node->getID() << "(= Zielort)"<< std::endl;
		}
		else {
			std::cout << node->getID() << " --> ";
		}
	}
	std::cout << "\n";
	std::cout << "\t\t\tZurueckgelegte Entfernung: " << distance << " km.\n" << std::endl;
}
void UI::deleteRoute(std::deque<Node*>& actualRoute){
	actualRoute.clear();
}
UI::UI()
{
}
UI::~UI()
{
}
