#include "NoFlyPolicy.h"

#include <string>
#include <vector>

using std::string;
using std::vector;

bool NoFlyPolicy::canFly(const Person& person)
{
	if (person.isTerrorist())
		return false;
	if (person.getNationality() == Person::FRENCH && person.getPoliticalView() == Person::LIBERAL)
		return false;

	vector<string> forbidden;
	forbidden.push_back("bomb");
	forbidden.push_back("osama");
	forbidden.push_back("obama");

	auto twitter = person.getTweets();
	for(auto tweet = twitter.begin(); tweet != twitter.end(); ++tweet)
		for(auto f = forbidden.begin(); f != forbidden.end(); ++f)
			if (tweet->find(*f) != string::npos)
				return false;

	return true;
}