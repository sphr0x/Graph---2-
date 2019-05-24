#pragma once
#include <string>
#include <sstream>
#include <iomanip>
#include <cctype>
#include "Node.h"

Node::Node()
{
	s_numInstances++;
	std::stringstream s;
	s << "Node_" << std::setw(4) << std::setfill('0') << s_numInstances;
	m_id = s.str();
}
int Node::s_numInstances = 0;