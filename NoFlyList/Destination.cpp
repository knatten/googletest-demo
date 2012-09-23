#include "Destination.h"

std::ostream& operator<<(std::ostream& os, const Destination& d)
{
	os << d.name << " (" << d.nofHumanRights << ")";
	return os;
}
