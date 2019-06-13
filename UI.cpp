#pragma once
#include "UI.h"
#include <list>

void UI::printMenu()const {												
	std::cout << "\n\t\t\t__/ Bitte Aktion via Nummerierung waehlen : \n\n" << "\t\t\t1 : Fahrt mit Fahrgast verbuchen\n";
	std::cout << "\t\t\t2 : Fahrt ohne Fahrgast verbuchen\n" << "\t\t\t3 : Tanken\n";
	std::cout << "\t\t\t4 : Taxistatus ausgeben\n" << "\t\t\t5 : Beenden\n";
	std::cout << "\t\t\t6 : Bildschirm bereinigen & Menu erneut zeigen\n" << std::endl;
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
	Node nStart, nEnd;													// evtl pointer ?
	std::deque<Node*> path;												// path füllen

	listofTaxi(&Taxis);
	printMenu();
	while (1) {
		std::cout << "\tEingabe: ";
		std::cin >> choose;
		choose = checkInput(choose);
		switch (choose) {
		case 1:
			/* hier distance raus und dafür start&ziel printfkt + eingabe */
		/*	std::cout << "\t\t\tGewuenschte Reisestrecke eingeben ( in km ):" << std::endl;
			std::cout << "\tEingabe: ";
			std::cin >> distance;
			distance = checkDist(distance);		*/
			std::cout << "Startort wählen: " << std::endl;		// alles in eine fkt ?
			printLocation(*bGraph);
			std::cin >> start;
			start = checkInput(start);
			nStart = setLocation(start, bGraph);						// setLoc schreiben
			std::cout << "Zielort wählen: " << std::endl;
			printLocation(*bGraph);
			std::cin >> end;
			end = checkInput(end);
			nEnd = setLocation(end, bGraph);

			if (chooseTaxi(Taxis) == 1) {						
				distance = bGraph->findShortestPathDijkstra(path,nStart,nEnd);	// distance = dijkstra( start, end , DQ path )
				Taxis.front()->bookTrip(1, distance);			// if distance >= pathlength -> not || sollte booktrip bereits machen
				printRoute(path);								// printRoute schreiben
				deleteRoute(path);								// delroute schreiben
			}													// printroute( DQ path )
					// ...
			else{
				distance = bGraph->findShortestPathDijkstra(path, nStart, nEnd);
				Taxis.back()->bookTrip(1, distance);			// hier das selbe
				printRoute(path);
				deleteRoute(path);
			}
			break;
		case 2:
			/* hier distance raus und dafür start&ziel print fkt + eingabe */
		/*	std::cout << "\t\t\tGewuenschte Reisestrecke eingeben ( in km ):" << std::endl;
			std::cout << "\tEingabe: ";
			std::cin >> distance;
			distance = checkDist(distance);		*/
			std::cout << "Startort wählen: " << std::endl;		// alles in eine fkt ?
			printLocation(*bGraph);
			std::cin >> start;
			start = checkInput(start);
			nStart = setLocation(start, bGraph);
			std::cout << "Zielort wählen: " << std::endl;
			printLocation(*bGraph);
			std::cin >> end;
			end = checkInput(end);
			nEnd = setLocation(end, bGraph);

			if (chooseTaxi(Taxis) == 1) {						//  hier wie ab line 60
				distance = bGraph->findShortestPathDijkstra(path, nStart, nEnd);
				Taxis.front()->bookTrip(0, distance);
				printRoute(path);
				deleteRoute(path);
			}
			else {												// hier auch
				distance = bGraph->findShortestPathDijkstra(path, nStart, nEnd);
				Taxis.back()->bookTrip(0, distance);
				printRoute(path);
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
	std::cout << "\t\t\t Taxi 1 hat den Bezeichner: " << car3->getName() << std::endl << "\t\t\t Taxi 2 hat den Bezeichner: " << car4->getName() << std::endl;

	//std::list<Taxi*>::iterator it = Taxis.begin(); it != Taxis.end(); ++it;		// zugriff auf n-tes element
}
void UI::DELETElistofTaxi(std::list<Taxi*>* Taxis) {
	int i = 1;
	while ((Taxis->size()) != 0) {
		delete(Taxis->front());
		Taxis->pop_front();
		std::cout << "\t\t\tInfo: Listenelement "<< i++ << " geloescht via \"delete\" !" << std::endl;
	}
}
int UI::checkInput(int choose)const {
	while (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(30, '\n');
		std::cerr << "\t\t\tFehler: Bitte eine Ziffer eingeben: " << std::endl;
		std::cout << "\tEingabe: ";
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
	for (auto node : bGraph.getNodes())std::cout << i++ << ": " << node->getID() << std::endl;
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
	std::list<Node*>::iterator it = bGraph->getNodes().begin();			// ???
	std::advance(it, location - 1);
	//return loc = *it;					// richtig ?
	//oder 

	auto it2 = std::next(bGraph->getNodes().begin(), location - 1);
	return loc = *it2;

}
void UI::printRoute(std::deque<Node*>& actualRoute){

}
void UI::deleteRoute(std::deque<Node*>& actualRoute){

}
UI::UI()
{
}
UI::~UI()
{
}
