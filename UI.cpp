#pragma once
#include "UI.h"
#include <list>
#include <windows.h>

void UI::printMenu()const {	
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
			std::cout << "\t\t\tTaxi-Bez: " << Taxis.front()->getName() << std::endl;		
			return choose;
		}
		else if(choose == 2) {
			std::cout << "\t\t\tTaxi-Bez: " << Taxis.back()->getName() << std::endl;		
			return choose;
		}
		else {
			std::cerr << "\t\t\tFehler: Bitte 1 oder 2 waehlen!" << std::endl;
		}
	}
}
void UI::menu() {		
	Graph* bRoute = new Graph;
	int choose;
	double distance;
	int start, end;
	std::list<Taxi*> Taxis;
	Node* nStart = nullptr;
	Node* nEnd = nullptr;													
	std::deque<Node*> path;													//  path filled in dijkstra

	setMap(*bRoute);
	listofTaxi(&Taxis);

	while (1) {
		system("cls");
		printMenu();
		std::cout << "\tEingabe: ";
		std::cin >> choose;
		choose = checkInput(choose);
		switch (choose) {
		case 1:
			std::cout << "\n\t\t\tBitte Startort waehlen: ( 1 bis 8 ) \n" << std::endl;		// 6 a)
			printLocation(*bRoute);
			std::cout << "\tEingabe: ";
			std::cin >> start;
			start = checkInput(start);
			nStart = setLocation(start, bRoute);
			std::cout << "\n\t\t\tBitte Zielort waehlen: ( 1 bis 8 ) \n" << std::endl;
			printLocation(*bRoute);
			std::cout << "\tEingabe: ";
			std::cin >> end;
			end = checkInput(end,start);
			nEnd = setLocation(end, bRoute);					
			if (chooseTaxi(Taxis) == 1) {						
				distance = bRoute->findShortestPathDijkstra(path,*nStart,*nEnd);
				Taxis.front()->bookTrip(1, distance);			
				printRoute(path,distance, *nEnd);											// 6 b)
				deleteRoute(path);								
			}													
			else{
				distance = bRoute->findShortestPathDijkstra(path, *nStart, *nEnd);
				Taxis.back()->bookTrip(1, distance);			
				printRoute(path,distance, *nEnd);											// 6 b)
				deleteRoute(path);
			}
			system("pause");
			break;
		case 2:
			std::cout << "\n\t\t\tBitte Startort waehlen: ( 1 bis 8 )\n" << std::endl;		// 6 a)
			printLocation(*bRoute);
			std::cout << "\tEingabe: ";
			std::cin >> start;
			start = checkInput(start);
			nStart = setLocation(start, bRoute);
			std::cout << "\n\t\t\tBitte Zielort waehlen: ( 1 bis 8 )\n" << std::endl;
			printLocation(*bRoute);
			std::cout << "\tEingabe: ";
			std::cin >> end;
			end = checkInput(end,start);
			nEnd = setLocation(end, bRoute);
			if (chooseTaxi(Taxis) == 1) {						
				distance = bRoute->findShortestPathDijkstra(path, *nStart, *nEnd);
				Taxis.front()->bookTrip(0, distance);
				printRoute(path,distance,*nEnd);											// 6 b)
				deleteRoute(path);
			}
			else {												
				distance = bRoute->findShortestPathDijkstra(path, *nStart, *nEnd);
				Taxis.back()->bookTrip(0, distance);
				printRoute(path,distance,*nEnd);											// 6 b)
				deleteRoute(path);
			}
			system("pause");
			break;
		case 3:
			if (chooseTaxi(Taxis) == 1) {
				Taxis.front()->fillUp();
			}
			else{
				Taxis.back()->fillUp();
			}
			system("pause");
			break;
		case 4:
			if (chooseTaxi(Taxis) == 1) {
				std::cout << Taxis.front()->getState() << std::endl;		// 2 b)
			}
			else {
				std::cout << Taxis.back()->getState() << std::endl;			// 2 b)
			}
			system("pause");
			break;
		case 5:
			DELETElistofTaxi(&Taxis);									// delete taxis ! 
			delete bRoute;												// delete graph 
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
	auto it2 = std::next(bGraph->getNodes().begin(), location - 1);			 // sync nodes to position
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
void UI::setMap(Graph& berlin){													// 5 b)

	Node *n1 = new Node("Zitadelle Spandau");
	Node *n2 = new Node("Funkturm");
	Node* n3 = new Node("Grenzallee");
	Node* n4 = new Node("Alexanderplatz");
	Node* n5 = new Node("Regattastrecke Gruenau");
	Node* n6 = new Node("Ostkreuz");
	Node* n7 = new Node("Brandenburger Tor");
	Node* n8 = new Node("Strandbad Wannsee");

	Route* r1 = new Route(*n1, *n2, 8.5);
	Route* r2 = new Route(*n4, *n7, 3.2);
	Route* r3 = new Route(*n7, *n8, 18.0);
	Route* r4 = new Route(*n8, *n2, 11.2);
	Route* r5 = new Route(*n2, *n4, 10.2);
	Route* r6 = new Route(*n4, *n6, 6.2);
	Route* r7 = new Route(*n6, *n5, 14.6);
	Route* r8 = new Route(*n5, *n3, 12.8);
	Route* r9 = new Route(*n3, *n4, 11.2);
	Route* r10 = new Route(*n3, *n2, 14.9);
	Route* r11 = new Route(*n2, *n1, 8.5);
	Route* r12 = new Route(*n7, *n4, 3.2);
	Route* r13 = new Route(*n8, *n7, 18.0);
	Route* r14 = new Route(*n2, *n8, 11.2);
	Route* r15 = new Route(*n4, *n2, 10.2);
	Route* r16 = new Route(*n6, *n4, 6.2);
	Route* r17 = new Route(*n5, *n6, 14.6);
	Route* r18 = new Route(*n3, *n5, 12.8);
	Route* r19 = new Route(*n4, *n3, 11.2);
	Route* r20 = new Route(*n2, *n3, 14.9);

	berlin.addNode(n1);
	berlin.addNode(n2);
	berlin.addNode(n3);
	berlin.addNode(n4);
	berlin.addNode(n5);
	berlin.addNode(n6);
	berlin.addNode(n7);
	berlin.addNode(n8);

	berlin.addEdge(r1);
	berlin.addEdge(r2);
	berlin.addEdge(r3);
	berlin.addEdge(r4);
	berlin.addEdge(r5);
	berlin.addEdge(r6);
	berlin.addEdge(r7);
	berlin.addEdge(r8);
	berlin.addEdge(r9);
	berlin.addEdge(r11);
	berlin.addEdge(r12);
	berlin.addEdge(r13);
	berlin.addEdge(r14);
	berlin.addEdge(r15);
	berlin.addEdge(r16);
	berlin.addEdge(r17);
	berlin.addEdge(r18);
	berlin.addEdge(r19);
	berlin.addEdge(r20);
}
UI::UI()
{
}
UI::~UI()
{
}
