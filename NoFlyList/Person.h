#pragma once

#include "Twitter.h"
#include <memory>

class Person
{
public:
	enum nationality_t { FRENCH, AMERICAN };
	enum political_view_t { CONSERVATIVE, LIBERAL };

	Person(nationality_t nationality, political_view_t political_view) :
	terrorist(false), nationality(nationality), political_view(political_view) {}

	void markAsTerrorist()
	{
		terrorist = true;
	}
	bool isTerrorist() const
	{
		return terrorist;
	}

	nationality_t getNationality() const
	{ 
		return nationality; 
	}
	political_view_t getPoliticalView() const
	{
		return political_view; 
	}
	
	void connectTwitterAccount(std::shared_ptr<Twitter> twitter_) { twitter = twitter_; }
	Tweets getTweets() const
	{
		if (twitter)
		{
			return twitter->getTweets();
		}
		else
		{
			return Tweets();
		}
	}
private:
	bool terrorist;
	nationality_t nationality;
	political_view_t political_view;
	std::shared_ptr<Twitter> twitter;
};