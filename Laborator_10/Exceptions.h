#pragma once
#include<iostream>
#include <exception>


class OutOfBoundsException :public _exception {
public:
	virtual const char* what() const throw()
	{
		return "Indexul is out of bounds!";
	}
};

class NoCapacity : public _exception {
public:
	virtual const char* what() const throw()
	{
		return "No capacity left!";
	}
};