#include <iostream>
#include "Node.h"
#include "Edge.h"
#include "Graph.h"
#include "Taxi.h" 
#include "UI.h"
#include "Route.h"

void setGraph(Graph& berlin);

int main()
				//graph tests
{
	/*try {
		Node *n1 = new Node("A");
		Node *n2 = new Node("B");
		Node* n3 = new Node("C");
		Node* n4 = new Node("D");
		Node* n5 = new Node("E");
		Node* n6 = new Node("F");
		Edge* e1 = new Edge(*n1, *n2);
		Edge* e2 = new Edge(*n1, *n3);
		Edge* e3 = new Edge(*n1, *n4);
		Edge* e4 = new Edge(*n4, *n5);
		Edge* e5 = new Edge(*n2, *n5);
		Graph* p = new Graph;

		p->addEdge(e1);
		p->addEdge(e2);
		p->addEdge(e3);
		p->addEdge(e4);
		//for (auto node : p->getNodes())std::cout << node->getID() << std::endl;
		std::deque<Node*> bla;
		std::cout << p->findShortestPathDijkstra(bla, *n1, *n5);
		for (auto x : bla)
			std::cout << x->getID() << std::endl;
		//    test    
		p->findNode("A");
		p->addNode(n6);
		p->addEdge(e5);
		// ok
		p->remove(*e5);
		p->remove(*n6);
		//test removed
		for (auto edge : p->getEdges()) {
			std::cout << edge->toString() << std::endl;
		}
		for (auto node : p->getNodes()) {
			std::cout << node->getID() << std::endl;
		}
		// ok
		std::vector<Edge*> testfind = p->findEdges(*n1, *n4);
		for (auto edge:testfind) {
			std::cout << edge->toString() << std::endl;
		}
		//ok
		p->~Graph();
		//std::cout << n1->getID();
		//std::cout << e1->getDstNode().getID();
		//n1->~Node();
	*/
					// taxi prog
	UI programm;
	Graph* bRoute = new Graph;

	setGraph(*bRoute);
	
	//for (auto node : bRoute->getNodes())std::cout << node->getID() << std::endl;
	for (auto edge : bRoute->getEdges())std::cout << edge->getWeight() << std::endl; // works, nice, everything added right
	programm.menu(bRoute);

	delete bRoute;			// delete besser
	//bRoute->~Graph(); 
/*	}
	catch (const char*) {
		std::cerr << "Exception: same node id" << std::endl;
	}*/
	system("PAUSE");
	return 0;
}

void setGraph(Graph& berlin) {			// fkt später in UI

	Node *n1 = new Node("Zitadelle Spandau");
	Node *n2 = new Node("Funkturm");
	Node* n3 = new Node("Grenzallee");
	Node* n4 = new Node("Alexanderplatz");
	Node* n5 = new Node("Regattastrecke Gruenau");
	Node* n6 = new Node("Ostkreuz");
	Node* n7 = new Node("Brandenburger Tor");
	Node* n8 = new Node("Strandbad Wannsee");
	/*
	"Zitadelle Spandau"
	"Funkturm"
	"Grenzallee"
	"Alexanderplatz"
	"Regattastrecke Gruenau"
	"Ostkreuz"
	"Brandenburger Tor"
	"Strandbad Wannsee"
	*/
	Route* r1 = new Route(*n1, *n2, 10.2);
	Route* r2 = new Route(*n4, *n7, 11.2);
	Route* r3 = new Route(*n7, *n8, 18.0);
	Route* r4 = new Route(*n8, *n2, 2.3);
	Route* r5 = new Route(*n2, *n4, 6.2);
	Route* r6 = new Route(*n4, *n6, 14.6);
	Route* r7 = new Route(*n6, *n5, 12.8);
	Route* r8 = new Route(*n5, *n3, 11.2);
	Route* r9 = new Route(*n3, *n4, 14.9);
	Route* r10 = new Route(*n3, *n2, 8.5);
	Route* r11 = new Route(*n2, *n1, 10.2);
	Route* r12 = new Route(*n7, *n4, 11.2);
	Route* r13 = new Route(*n8, *n7, 18.0);
	Route* r14 = new Route(*n2, *n8, 2.3);
	Route* r15 = new Route(*n4, *n2, 6.2);
	Route* r16 = new Route(*n6, *n4, 14.6);
	Route* r17 = new Route(*n5, *n6, 12.8);
	Route* r18 = new Route(*n3, *n5, 11.2);
	Route* r19 = new Route(*n4, *n3, 14.9);
	Route* r20 = new Route(*n2, *n3, 8.5);
	
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
	std::cout << r20->toString2() << std::endl;
}
