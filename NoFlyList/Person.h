#pragma once

class Person
{
public:
	Person() : terrorist(false)
	{
	}
	void markAsTerrorist()
	{
		terrorist = true;
	}
	bool isTerrorist() const
	{
		return terrorist;
	}
private:
	bool terrorist;
};