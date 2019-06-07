#ifndef EDGE_H
#define EDGE_H

#include "Node.h"

// not complete - def all functions in cpp
class Edge
{
public:
	Edge(Node& rSrc, Node& rDst);
	Edge(const Edge& rOther);
	virtual ~Edge();

	bool isConnectedTo(const Node& rNode) const;
	Node& getSrcNode() { return m_rSrc; }
	Node& getDstNode() { return m_rDst; }
	std::string toString() const;
	virtual double getWeight() { return 1; }
	virtual std::string getID() { return ""; }
private:
	Node& m_rSrc;
	Node& m_rDst;
};

#endif
