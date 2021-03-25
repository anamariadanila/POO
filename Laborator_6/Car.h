#pragma once
#include<iostream>
#include<cstring>
#include"Weather.h"

class Car {

protected: 
	float fuelCapacity;
	float fuelConsumption;
	float *averageSpeed;
	char* name;

public:
	Car(){}
	~Car(){}

	virtual float GetFuelCapacity() = 0;
	virtual float GetFuelConsumption() = 0;
	virtual float GetSpeed(Weather w=Weather::Sunny) = 0;
	virtual char* GetName() = 0;
	virtual float GetTime(float lenght, Weather w = Weather::Sunny) = 0;


};