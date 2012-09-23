#pragma once
#include <string>
#include <ostream>

struct Destination
{
	Destination(std::string name, unsigned int nofHumanRights) : name(name), nofHumanRights(nofHumanRights) {}
	const std::string name;
	const unsigned int nofHumanRights;
};