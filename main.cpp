#pragma once
#include <iostream>
#include "Node.h"
#include "Edge.h"
// Project Properties ~> C/C++ ~> General ~> Additional Include 
// Directories, try to set there path relative to the directory -> worked
int main()
{
	std::cout << "GTF OUT OF ME" << std::endl;
	Node n1("eins");
	Node n2("zwei");
	Edge e1(n1,n2);

	std::cout << e1.toString();

	return 0;
}


/* 2DO

- graph fkt
- edge fkt
- statische Bibliothek graphlib.lib
- 

*/