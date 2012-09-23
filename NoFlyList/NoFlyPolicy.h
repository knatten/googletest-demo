#pragma once
#include "Person.h"
#include "Destination.h"

class NoFlyPolicy
{
public:
	bool canFly(const Person& person);
	Destination terroristDestination() { return Destination("Guantanamo", 1); }
};

