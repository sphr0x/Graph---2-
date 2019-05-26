#include <iostream>
#include "Node.h"
#include "Edge.h"
#include "Graph.h"



int main()
{
	Node n1("eins");
	Node n2("zwei");
	Node n3("drei");
	Edge *e1 = new Edge(n1, n2);
	Edge *e2 = new Edge(n2, n1);
	Edge *e3 = new Edge(n1, n1);
	Edge *e4 = new Edge(n2, n3);

	std::cout << e1->toString() <<std::endl;				 // just check if n1/n2 are in e1 -> still not in list
	std::cout << e2->toString() << std::endl;
	std::cout << e3->toString() << std::endl;

	// check what in/out Edges are in list
	for (std::list<Edge*>::iterator it = n1.getOutEdges().begin();it != n1.getOutEdges().end();++it) {
		std::cout << (*it)->toString() << " node1 out edges"<<std::endl;
	};
	for (std::list<Edge*>::iterator it = n1.getInEdges().begin();it != n1.getInEdges().end();++it) {
		std::cout << (*it)->toString() << " node1 in edges" << std::endl;
	};
	for (std::list<Edge*>::iterator it = n2.getOutEdges().begin();it != n2.getOutEdges().end();++it) {
		std::cout << (*it)->toString() << " node2 out edges" << std::endl;
	};
	for (std::list<Edge*>::iterator it = n2.getInEdges().begin();it != n2.getInEdges().end();++it) {
		std::cout << (*it)->toString() << " node2 in edges" << std::endl;
	};
	
	delete e1,e2,e3,e4;

	for (std::list<Edge*>::iterator it = n1.getOutEdges().begin();it != n1.getOutEdges().end();++it) {
		std::cout << (*it)->toString() << " node1 out edges" << std::endl;
	};
	for (std::list<Edge*>::iterator it = n1.getInEdges().begin();it != n1.getInEdges().end();++it) {
		std::cout << (*it)->toString() << " node1 in edges" << std::endl;
	};
	for (std::list<Edge*>::iterator it = n2.getOutEdges().begin();it != n2.getOutEdges().end();++it) {
		std::cout << (*it)->toString() << " node2 out edges" << std::endl;
	};
	for (std::list<Edge*>::iterator it = n2.getInEdges().begin();it != n2.getInEdges().end();++it) {
		std::cout << (*it)->toString() << " node2 in edges" << std::endl;
	};
	/*
	e1->~Edge();
	e2->~Edge();							// not...
	e3->~Edge();
	e4->~Edge();
	*/
	std::cin.ignore();
	return 0;
}
