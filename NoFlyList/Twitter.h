#pragma once
#include <string>
#include <vector>

typedef std::vector<std::string> Tweets;

class Twitter
{
public:
	Twitter() {}
	Tweets getTweets() const
	{
		return tweets;
	}
	void tweet(std::string message)
	{
		tweets.push_back(message);
	}
private:
	Tweets tweets;
};